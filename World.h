#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Organism.h"
#include "Zoomie.h"

class World {
private:
    std::vector<std::vector<Organism*>> grid; // Dynamic grid of organisms
    int size; // Size of the grid

public:
    World(int gridSize);
    ~World();

    void addOrganism(Organism* organism, int x, int y);
    void removeOrganism(Organism* organism, int x, int y);
    void moveSwoopies();
    void moveZoomies();
    void display() const;
    int getSize() const;

    void updatePositions();

};

#endif // WORLD_H
