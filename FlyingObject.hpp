//
// Created by Sambo on 18/09/2023.
//
#include<string>
#ifndef SDLTEST_FLYINGOBJECT_HPP
#define SDLTEST_FLYINGOBJECT_HPP


class FlyingObject {
private:
        double x;
        double y;
        double size;
        double SpeedX;
        double SpeedY;



        // Setters
public :

    FlyingObject(double x, double y, double size, double SpeedX,double SpeedY);

    double getX();

    void setX(double x);

    double getY() ;

    void setY(double y);

    double getSize() ;
    void setSpeedX(double speedX);

    void setSpeedY(double speedY);

    void setSize(double size);
    double getSpeedX();
    double getSpeedY();
    void Move();
    void Move(double screenWidth, double screenHeight);
    static bool Collide(FlyingObject o1, FlyingObject o2);
    virtual std::string GetTypeName();



};


#endif //CPP_PROJECT_FLYINGOBJECT_HPP


