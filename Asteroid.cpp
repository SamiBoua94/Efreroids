//
// Created by Sambo on 18/09/2023.
//

#include "Asteroid.hpp"
#include "FlyingObject.hpp"

Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed) :  FlyingObject(x, y, size, xSpeed,ySpeed) {
}


std::string Asteroid::GetTypeName(){
    return "Asteroid";
};

