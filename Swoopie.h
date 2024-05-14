#ifndef SWOOPIE_H
#define SWOOPIE_H

#include "Organism.h"
#include "World.h"

class World;

class Swoopie : public Organism {
private:
    int breedTime; // time steps required for breeding
    int starveTime; // time steps after which Swoopie starves if it hasn't eaten

public:
    Swoopie(int posX, int posY, World* world);
    ~Swoopie() {}

    void move() override;
    void breed() override;
    void eatZoomie();
    void starve();

    World *world;
};

#endif // SWOOPIE_H
