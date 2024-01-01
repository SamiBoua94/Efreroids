#include <iostream>
#include "framework.hpp"
#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include "Controller.hpp"
#include <iostream>
#include <ctime>
#include <thread>





int WinMain(int argc, char* argv[])
//int main(int argc, char* argv[])
{
    Controller* c =  new Controller(60, 50, 30);
    c->LaunchGame();
    return 0;
    /*Controller* c = new Controller(60, 50, 30);
    c->LaunchGame();*/

    return 0;
   /* Framework *f = new Framework(10,50,30);
    Asteroid *a = new Asteroid(200,200,80,18,18);
    Missile *m = new Missile(f->GetScreenWidth()/2,f->GetScreenHeight()/2,10,85,29);
    Spaceship *s = new Spaceship(f->GetScreenWidth()/2,f->GetScreenHeight()/2,50,0,0 );
    while(true){

        switch (f->GetInput()) {
            case SDLK_UP:
                s->SpeedUp(2);
                break;
            case SDLK_LEFT:
                s->Rotate(-5);
                break;
            case SDLK_DOWN:
                s->SpeedDown(2);
                break;
            case SDLK_RIGHT:
                s->Rotate(5);
                break;
            default:
                break;
        }

        s->MoveS(f->GetScreenWidth(), f->GetScreenHeight());
        f->DrawShip(s->getX(),s->getY(),s->getAngle(),1,false);

        if (a){
            f->DrawAsteroid(a->getX(), a->getY(), a->getSize());
            a->Move(f->GetScreenWidth(), f->GetScreenHeight());
        }

        if(m){
            f->DrawMissile(m->getX(),m->getY());

            if(FlyingObject::Collide(*m,*a)){
                delete m;
                delete a;

                m = nullptr;
                a = nullptr;
            } else if (m->Move(f->GetScreenWidth(), f->GetScreenHeight())) {
                delete m;
                m = nullptr;
            }
        }
        f->Update();

    }
    return 0;*/
}