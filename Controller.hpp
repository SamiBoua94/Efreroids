//
// Created by Sambo on 09/12/2023.
//

#ifndef SDLTEST_CONTROLLER_HPP
#define SDLTEST_CONTROLLER_HPP


#include "View.hpp"

class Controller {
public:
    Controller(int FPS,  int shipSize, int missileSize);
    void LaunchGame();
    void MoveSpaceship(int tmp);
    void LaunchMissile(int tmp);
    std::chrono::high_resolution_clock::time_point lastLaunchTime;
private:
    Modele *mo;
    View *vi ;
    Framework *f;


};


#endif //SDLTEST_CONTROLLER_HPP
