//
// Created by Sambo on 18/09/2023.
//

#include "Missile.hpp"
#include <cmath>



Missile::Missile(double x, double y, double size, double angle, double speed) : FlyingObject(x, y, size,speed * cos((angle-90) * M_PI / 180.0), speed * sin((angle-90) * M_PI / 180.0) ), angle(angle) {}
void Missile::Move() {
    setX(getX() + getSpeedX());
    setY(getY() + getSpeedY());
}

double Missile::getAngle() {
    return angle;
}

void Missile::setAngle(double angle) {
    Missile::angle = angle;
}

double Missile::getSpeed()  {
    return speed;
}

void Missile::setSpeed(double speed) {
    Missile::speed = speed;
}



bool Missile::Move(double screenWidth, double screenHeight) {
    if( getX() > screenWidth || getY() > screenHeight
        || getX() < 0  || getY() < 0 ) {
        return true;
    }
    FlyingObject::Move();
    return false;
}
std::string Missile::GetTypeName(){
    return "Missile";
};