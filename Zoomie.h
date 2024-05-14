#ifndef ZOOMIE_H
#define ZOOMIE_H

#include "Organism.h"
#include "World.h"

class World;

class Zoomie : public Organism {
private:
    int breedTime; // time steps required for breeding

public:
    Zoomie(int posX, int posY, World* world);
    ~Zoomie() {}

    void move() override;
    void breed() override;

    void updatePosition();

private:
    World* world;
};

#endif // ZOOMIE_H
