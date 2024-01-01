//
// Created by Sambo on 09/12/2023.
//

#ifndef SDLTEST_SPACESHIP_H
#define SDLTEST_SPACESHIP_H

#include "FlyingObject.hpp"


class Spaceship : public FlyingObject {
private:
    double angle;
    bool Alert;
    double shield;
public:
    bool isAlert() const;

    double getShield() const;
    double getAngle() const;
    Spaceship(double x, double y, double size, double speed, double angle);
    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    void Rotate(double rAngle);
    void MoveS(double screenWidth, double screenHeight);
    void DecreaseShield();
    void IncreaseShield();
    void TriggerAlert();
    std::string GetTypeName() override;


};

#endif //SDLTEST_SPACESHIP_H