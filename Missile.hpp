//
// Created by Sambo on 18/09/2023.
//

#ifndef SDLTEST_MISSILE_HPP
#define SDLTEST_MISSILE_HPP


#include "FlyingObject.hpp"

class Missile : public FlyingObject{
public:
    Missile(double x, double y, double size, double angle, double speed);
    void Move();
    bool Move(double screenWidth, double screenHeight);

    double getAngle();

    void setAngle(double angle);

    double getSpeed() ;

    void setSpeed(double speed);
    std::string GetTypeName() override;


private:

    double angle;
    double speed;


};


#endif //SDLTEST_MISSILE_HPP
