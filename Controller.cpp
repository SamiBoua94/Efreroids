//
// Created by Sambo on 09/12/2023.
//

#include "Controller.hpp"
#include "framework.hpp"
#include "Modele.hpp"
#include "View.hpp"
#include "Spaceship.hpp"
#include <chrono>


Controller::Controller(int FPS, int shipSize, int missileSize) {
    this->f = new Framework(FPS,shipSize,missileSize);
    this->mo = new Modele(f);
    this->vi = new View(mo, f);

}
void Controller::LaunchGame() {
    while (true) {
        int tmp = f->GetInput();
        if (tmp == SDLK_ESCAPE)
            break;
        MoveSpaceship(tmp);
        LaunchMissile(tmp);
        mo->Update();
        vi->Update();
    }
}
void Controller::LaunchMissile (int key){
    if (key == SDLK_SPACE)
        mo->LaunchMissile();



    //J'avais fais une fonction qui peut lancer un missile toute les secondes car c'est mieux pour faire les test et jouer
    /*auto currentTime = std::chrono::high_resolution_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastLaunchTime).count();

    if (key == SDLK_SPACE && elapsedSeconds >= 0.1) {
        mo->LaunchMissile();
        lastLaunchTime = currentTime;
    }*/

}

void Controller::MoveSpaceship(int key) {
    switch (key) {
        case SDLK_UP:
            mo->Up();
            break;
        case SDLK_LEFT:
            mo->Left();
            break;
        case SDLK_DOWN:
            mo->Down();
            break;
        case SDLK_RIGHT:
            mo->Right();
            break;
        default:
            break;
    }
}
