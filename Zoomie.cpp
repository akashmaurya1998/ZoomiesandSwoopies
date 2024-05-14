#include "Zoomie.h"
#include "World.h"
#include <cstdlib> // for rand()

Zoomie::Zoomie(int posX, int posY, World* world) : Organism(posX, posY), world(world), breedTime(3) {}

void Zoomie::move() {
    int oldX = x;
    int oldY = y;

    int direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right
    switch (direction) {
        case 0: // up
            if (y > 0) y--;
            break;
        case 1: // down
            if (y < 29) y++;
            break;
        case 2: // left
            if (x > 0) x--;
            break;
        case 3: // right
            if (x < 29) x++;
            break;
    }

    // Update the position in the world grid
    world->removeOrganism(this, oldX, oldY);
    world->addOrganism(this, x, y);

    stepsSurvived++;
}

void Zoomie::breed() {
    if (stepsSurvived >= breedTime) {
        // breed if enough time has passed
        // code for creating a new Zoomie in an adjacent empty cell
    }
}
