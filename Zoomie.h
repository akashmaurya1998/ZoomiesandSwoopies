#ifndef ZOOMIE_H
#define ZOOMIE_H

#include "Organism.h"

class Zoomie : public Organism {
private:
    int breedTime; // time steps required for breeding

public:
    Zoomie(int posX, int posY);
    ~Zoomie() {}

    void move() override;
    void breed() override;
};

#endif // ZOOMIE_H
