//
// Created by Sambo on 09/12/2023.
//

#ifndef SDLTEST_MODELE_HPP
#define SDLTEST_MODELE_HPP
#include "Spaceship.hpp"
#include <vector>
#include "framework.hpp"
#include <chrono>



class Modele {
    public:
        Modele(Framework *f);
   void Up();
    void Down();
    void Left();
    void Right();
    void Update();
    void LaunchMissile();
    void CreateRandomAsteroid();
    void Winner();


     std::vector<FlyingObject *> &getFlyingobject() ;


private:
    Spaceship *s;
    std::vector<FlyingObject*> Flyingobject;
    /*double width;
    double height;*/
    Framework *f;
    std::chrono::time_point<std::chrono::system_clock> lastAsteroidTime ;
    double sizeasteroid;
};






#endif //SDLTEST_MODELE_HPP
