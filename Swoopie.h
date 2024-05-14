#ifndef SWOOPIE_H
#define SWOOPIE_H

#include "Organism.h"
#include "World.h"

class World;

class Swoopie : public Organism {
private:
    World *world;
    int breedTime;
    int starveTime;
    int lastEaten;

public:
    Swoopie(int posX, int posY, World* world);
    ~Swoopie() {}

    void move() override;
    void breed() override;
    void eatZoomie();
    void starve();
};

#endif
