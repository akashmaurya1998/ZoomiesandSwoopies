#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Organism.h"

class World {
private:
    std::vector<std::vector<Organism*>> grid; // Dynamic grid of organisms
    int size; // Size of the grid

public:
    World(int gridSize);
    ~World();

    void addOrganism(Organism* organism, int x, int y);
    void moveSwoopies();
    void moveZoomies();
    void display() const;
    int getSize() const;
};

#endif // WORLD_H
