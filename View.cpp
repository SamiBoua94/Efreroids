//
// Created by Sambo on 09/12/2023.
//
#include "Spaceship.hpp"
#include "View.hpp"
#include <iostream>
View::View(Modele *mo, Framework *f){
    this->mo=mo;
    this->f=f;
}

void View::Update() {
    std::vector<FlyingObject*>& flyingObjects = mo->getFlyingobject();

    for (FlyingObject *obj : flyingObjects) {
        if (obj->GetTypeName() == "Spaceship") {
            f->DrawShip(obj->getX(), obj->getY(), ((Spaceship*)obj)->getAngle(), ((Spaceship*)obj)->getShield(),((Spaceship*)obj)->isAlert());
        } else if (obj->GetTypeName() == "Missile") {
            f->DrawMissile(obj->getX(), obj->getY());
        } else if (obj->GetTypeName() == "Asteroid") {
            f->DrawAsteroid(obj->getX(), obj->getY(), obj->getSize());
        }
    }
    f->Update();
}
