//
// Created by Sambo on 09/12/2023.
//
#include "Modele.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "framework.hpp"
#include "Spaceship.hpp"
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <thread>

    Modele::Modele(/*double width, double height*/Framework *f){
    /*this->width=width;
    this->height=height;*/
    /*this->sizeasteroid = (rand() % (100))+10 ;*/
    this->f=f;
        s =new Spaceship(f->GetScreenWidth()/2,f->GetScreenHeight()/2,50,0,0 );
        Flyingobject.push_back(s);

        /*Asteroid *a = new Asteroid(200,200,80,18,18);
        Flyingobject.push_back(a);*/
        lastAsteroidTime = std::chrono::system_clock::now();
        for(int i=0; i<8;i++){
            this->sizeasteroid = (rand() % (100))+50 ;
            CreateRandomAsteroid();
        }
}
void Modele::Up(){
    s->SpeedUp(0.2);
}
void Modele::Down(){
    s->SpeedDown(0.2);
}
void Modele::Left(){
    s->Rotate(-10);
}
void Modele::Right(){
    s->Rotate(10);
}
void Modele::Update(){
    Winner();
   auto currentTime = std::chrono::system_clock::now();


    // Calculez la durée écoulée depuis le dernier astéroïde
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastAsteroidTime).count();
    // Génération d'un nouvel astéroïde toutes les  secondes
  /*  if (elapsedTime >= 15 ){
        for(int i=0; i<100;i++){
            lastAsteroidTime = currentTime;
            CreateRandomAsteroid();
        }
   }*/
    //Boucle for spécial ou on peut faire des opérations dessus "for ( auto obj : Flyingobject )"
    std::vector<FlyingObject *>ObjTemporaire;
    std::vector<FlyingObject *>ObjTemporaireAdd;
    for ( auto obj : Flyingobject ){
        if(obj->GetTypeName()=="Spaceship"){
            static_cast<Spaceship *>(obj)->MoveS(f->GetScreenWidth(), f->GetScreenHeight());
            //Si je met pas le cast, methode classe mère uniquement
            //si cast, methode classe fille choisie

        }
        if(obj->GetTypeName()=="Missile" &&  static_cast<Missile *>(obj)->Move(f->GetScreenWidth(), f->GetScreenHeight())){
            ObjTemporaire.push_back(obj);
            //on ne peut pas supprimer un objet dans une liste sur laquelle on est en train d'itérer -> push back dans un vector temporaire pour supprimer après la boucle for
            s->IncreaseShield();
            s->TriggerAlert();

        }
        if(obj->GetTypeName()=="Asteroid"){
            static_cast<Asteroid *>(obj)->Move(f->GetScreenWidth(), f->GetScreenHeight());
            for ( auto obj2 : Flyingobject ){
                //*obj pointer car pointer sur pointer donne la valeur de l'objet
                if (obj2->GetTypeName()=="Missile" && FlyingObject::Collide(*obj,*obj2)){
                    if(obj->getSize()>50){
                        obj->setSize(obj->getSize()/2);
                        Asteroid *a2= new Asteroid(obj->getX(), obj->getY(),obj->getSize(), -obj->getSpeedX(), -obj->getSpeedY());
                        obj->setSpeedX(rand() % (10));
                        obj->setSpeedY(rand() % (10));

                        ObjTemporaireAdd.push_back(a2);
                        ObjTemporaire.push_back(obj2);
                    }
                    else{
                        ObjTemporaire.push_back(obj2);
                        ObjTemporaire.push_back(obj);
                    }
                    s->IncreaseShield();
                    s->TriggerAlert();
                }
                if (obj2->GetTypeName()=="Spaceship" && FlyingObject::Collide(*obj,*obj2)){

                    if(obj->getSize()>50){
                        obj->setSize(obj->getSize()/2);
                        Asteroid *a2= new Asteroid(obj->getX(), obj->getY(),obj->getSize(), -obj->getSpeedX(), -obj->getSpeedY());
                        ObjTemporaireAdd.push_back(a2);

                    }else{

                        ObjTemporaire.push_back(obj);}

                    s->DecreaseShield();
                    s->TriggerAlert();
                }
            }
        }
    }
    //https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
    Flyingobject.insert(std::end(Flyingobject), std::begin(ObjTemporaireAdd), std::end(ObjTemporaireAdd));

    for ( auto obj3 : ObjTemporaire ){
        Flyingobject.erase(std::remove(Flyingobject.begin(), Flyingobject.end(), obj3), Flyingobject.end());
    }
    //https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
    //Flyingobject.insert(std::end(Flyingobject), std::begin(ObjTemporaireAdd), std::end(ObjTemporaireAdd));
}

std::vector<FlyingObject *> &Modele::getFlyingobject()  {
    return Flyingobject;
}

void Modele::LaunchMissile()
{
    //Pour que nous puissions tirer un autre missile une fois que celui ci n'est plus dans l'ecran
    // Pour le test je prefere mettre par seconde
    /*for( auto flyobj :Flyingobject ){
        if(flyobj->GetTypeName()=="Missile"){
        return;}
    }*/

    auto missile = new Missile(s->getX(), s->getY(), 70.0,s->getAngle(),3  +sqrt(s->getSpeedX() * s->getSpeedX() + s->getSpeedY() * s->getSpeedY()));
    Flyingobject.push_back(missile);

}
void Modele::CreateRandomAsteroid() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Sélection aléatoire de la zone (0 à 7)
    std::uniform_int_distribution<int> zoneDistribution(0, 7);
    int selectedZone = zoneDistribution(gen);

    // Calcul des coordonnées minimales et maximales de la zone
    double minX, minY, maxX, maxY;

    switch (selectedZone) {
        case 0: minX = 0; minY = 0; maxX = f->GetScreenWidth() / 3; maxY = f->GetScreenHeight() / 3; break;
        case 1: minX = f->GetScreenWidth() / 3; minY = 0; maxX = 2 * f->GetScreenWidth() / 3; maxY = f->GetScreenHeight() / 3; break;
        case 2: minX = 2 * f->GetScreenWidth() / 3; minY = 0; maxX = f->GetScreenWidth(); maxY = f->GetScreenHeight() / 3; break;
        case 3: minX = 0; minY = f->GetScreenHeight() / 3; maxX = f->GetScreenWidth() / 3; maxY = 2 * f->GetScreenHeight() / 3; break;
        case 4: minX = f->GetScreenWidth() / 3; minY = f->GetScreenHeight() / 3; maxX = 2 * f->GetScreenWidth() / 3; maxY = 2 * f->GetScreenHeight() / 3; break;
        case 5: minX = 2 * f->GetScreenWidth() / 3; minY = f->GetScreenHeight() / 3; maxX = f->GetScreenWidth(); maxY = 2 * f->GetScreenHeight() / 3; break;
        case 6: minX = 0; minY = 2 * f->GetScreenHeight() / 3; maxX = f->GetScreenWidth() / 3; maxY = f->GetScreenHeight(); break;
        case 7: minX = f->GetScreenWidth() / 3; minY = 2 * f->GetScreenHeight() / 3; maxX = 2 * f->GetScreenWidth() / 3; maxY = f->GetScreenHeight(); break;
    }

    // Génération des coordonnées aléatoires dans la zone sélectionnée
    std::uniform_real_distribution<double> xDistribution(minX, maxX);
    std::uniform_real_distribution<double> yDistribution(minY, maxY);

    double x = xDistribution(gen);
    double y = yDistribution(gen);

    // Génération aléatoire de l'angle entre -180° et 180°
    std::uniform_int_distribution<int> angleDistribution(-180, 180);
    int randomAngle = angleDistribution(gen);

    // Calcul des vitesses horizontale et verticale
    double speed = 3.0;  // Ajustez la vitesse selon vos besoins
    double angleInRadians = static_cast<double>(randomAngle) * M_PI / 180.0;
    double speedX = speed * std::cos(angleInRadians);
    double speedY = speed * std::sin(angleInRadians);

    // Création et ajout de l'astéroïde à la liste
    Asteroid* asteroid = new Asteroid(x, y, /*(rand() % (110))*/  sizeasteroid, speedX, speedY);
    Flyingobject.push_back(asteroid);
}

void Modele::Winner(){
    for( auto asteroid :Flyingobject ){
        if(asteroid->GetTypeName()=="Asteroid"){
            return; }
    }
        std::exit(0);

        }






