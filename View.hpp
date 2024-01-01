//
// Created by Sambo on 09/12/2023.
//

#ifndef SDLTEST_VIEW_HPP
#define SDLTEST_VIEW_HPP
#include "Modele.hpp"
#include "framework.hpp"

class View {
    public:
        View(Modele *mo, Framework *f);
        void Update();
private:
    Modele *mo;
    Framework *f;
};


#endif //SDLTEST_VIEW_HPP
