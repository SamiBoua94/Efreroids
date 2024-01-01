//
// Created by Sambo on 18/09/2023.
//

#include "FlyingObject.hpp"
#include <cmath>

FlyingObject::FlyingObject(double x, double y, double size, double SpeedX, double SpeedY)
        : x(x), y(y), size(size), SpeedX(SpeedX),SpeedY(SpeedY){}

double FlyingObject::getX() {
return x;
}

void FlyingObject::setX(double x) {
    FlyingObject::x = x;
}

double FlyingObject::getY()  {
   return y;
}

void FlyingObject::setY(double y) {
    FlyingObject::y = y;
}

double FlyingObject::getSize()  {
    return size;
}

void FlyingObject::setSize(double size) {
    FlyingObject::size = size;
}
double FlyingObject::getSpeedX() {
    return SpeedX;
}

double FlyingObject::getSpeedY() {
    return SpeedY;
}

void FlyingObject::Move() {
    x+=SpeedX;
    y+=SpeedY;
}
void FlyingObject::Move(double screenWidth, double screenHeight){
    this->Move();
    if (x < 0) {
        x = screenWidth - 1;
    } else if (x >= screenWidth) {
        x = 0;
    }

    if (y < 0) {
        y = screenHeight - 1; // Réapparition en bas de l'écran
    } else if (y >= screenHeight) {
        y = 0; // Réapparition en haut de l'écran
    }


}
bool FlyingObject::Collide(FlyingObject o1, FlyingObject o2){
    if( (sqrt(pow(o2.getX() - o1.getX(), 2) + pow(o2.getY() - o1.getY(), 2))) <= (o1.getSize()/2+o2.getSize()/2)){
        return true;
    }else{  return false;}
}

void FlyingObject::setSpeedX(double speedX) {
    SpeedX = speedX;
}

void FlyingObject::setSpeedY(double speedY) {
    SpeedY = speedY;
}


std::string FlyingObject::GetTypeName(){
    return "FlyingObject";
};
