//
// Created by Sambo on 18/09/2023.
//

#ifndef SDLTEST_ASTEROID_HPP
#define SDLTEST_ASTEROID_HPP
#include "FlyingObject.hpp"


class Asteroid : public FlyingObject{
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;
    static double sizeasteroid;
public:

    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);
    std::string GetTypeName() override;




};


#endif //SDLTEST_ASTEROID_HPP
