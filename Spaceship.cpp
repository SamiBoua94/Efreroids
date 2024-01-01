//
// Created by Sambo on 09/12/2023.
//

#include "Spaceship.hpp"
#include "FlyingObject.hpp"
#include <cmath>
#include <iostream>
Spaceship::Spaceship(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size, speed, speed),  angle(angle) {  Alert = false;shield =1; }

double Spaceship::getAngle() const {
    return angle;
}

void Spaceship::SpeedUp(double accelerationFactor)
{
    double radianAngle = (angle - 90) * M_PI / 180.0;
    setSpeedX(getSpeedX()+accelerationFactor * cos(radianAngle));
    setSpeedY(getSpeedY()+accelerationFactor * sin(radianAngle));
}

void Spaceship::SpeedDown(double decelerationFactor)
{
    double radianAngle = (angle - 90) * M_PI / 180.0;
    setSpeedX(getSpeedX()-decelerationFactor * cos(radianAngle));
    setSpeedY(getSpeedY()-decelerationFactor * sin(radianAngle));
}
void Spaceship::Rotate(double rAngle){
    angle += rAngle;
}
void Spaceship::MoveS(double screenWidth, double screenHeight)
{
    this->setX(getX()+this->getSpeedX()) ;
    this->setY(getY()+this->getSpeedY()) ;

    if (getX() < 0)
    {
        setX(0);
        setSpeedX(0);
    }
    if (getX() + getSize() > screenWidth)
    {
        setX(screenWidth-getSize());
        setSpeedX(0);
    }
    if (getY() < 0)
    {
        setY(0);
        setSpeedY(0);
    }
    if (getY() + getSize() > screenHeight)
    {
        setY(screenHeight-getSize());
        setSpeedY(0);
}}

std::string Spaceship::GetTypeName(){
    return "Spaceship";
};

void Spaceship::TriggerAlert() {

    /*if (shield < 0.5) {
        Alert=true;
    }else{
        Alert= false;
    }
}*/
    if (shield <= 0.0) {
        std::exit(0);
        std::cout << "Terminé";
    } else if (shield < 0.5) {
        Alert = true;
    } else {
        Alert = false;
    }
}
void Spaceship::DecreaseShield() {
    // Mettez ici le code pour implémenter le bouclier, par exemple, réduisez sa valeur
    if(shield>0)
    shield -= 0.2;

    // Affichez la valeur actuelle du bouclie
};

void Spaceship::IncreaseShield() {
    // Mettez ici le code pour implémenter le bouclier, par exemple, réduisez sa valeur
    if(shield<=1)
        shield += 0.1;

    // Affichez la valeur actuelle du bouclie
}

bool Spaceship::isAlert() const {
    return Alert;
}

double Spaceship::getShield() const {
    return shield;
};