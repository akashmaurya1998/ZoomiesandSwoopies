#include "Swoopie.h"
#include "World.h"
#include <cstdlib>

Swoopie::Swoopie(int posX, int posY, World* world) : Organism(posX, posY), world(world), breedTime(8), starveTime(3), lastEaten(0) {}

void Swoopie::move() {
    int oldX = x;
    int oldY = y;

    int direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right
    switch (direction) {
        case 0: // up
            if (y > 0) y--;
            break;
        case 1: // down
            if (y < world->getSize() - 1) y++;
            break;
        case 2: // left
            if (x > 0) x--;
            break;
        case 3: // right
            if (x < world->getSize() - 1) x++;
            break;
    }

    // Update the position in the world grid
    world->removeOrganism(this, oldX, oldY);
    world->addOrganism(this, x, y);

    stepsSurvived++;
    lastEaten++;
    eatZoomie();
    breed();
    starve();
}

void Swoopie::breed() {
    if (stepsSurvived >= breedTime) {
        // Try to breed into an adjacent empty cell
        if (world->isCellEmpty(x, y - 1)) {
            world->addOrganism(new Swoopie(x, y - 1, world), x, y - 1);
        } else if (world->isCellEmpty(x, y + 1)) {
            world->addOrganism(new Swoopie(x, y + 1, world), x, y + 1);
        } else if (world->isCellEmpty(x - 1, y)) {
            world->addOrganism(new Swoopie(x - 1, y, world), x - 1, y);
        } else if (world->isCellEmpty(x + 1, y)) {
            world->addOrganism(new Swoopie(x + 1, y, world), x + 1, y);
        }
        stepsSurvived = 0; // Reset the breeding counter
    }
}

void Swoopie::eatZoomie() {
    if (world->isCellZoomie(x, y - 1)) {
        world->removeOrganism(world->getOrganismAt(x, y - 1), x, y - 1);
        lastEaten = 0;
    } else if (world->isCellZoomie(x, y + 1)) {
        world->removeOrganism(world->getOrganismAt(x, y + 1), x, y + 1);
        lastEaten = 0;
    } else if (world->isCellZoomie(x - 1, y)) {
        world->removeOrganism(world->getOrganismAt(x - 1, y), x - 1, y);
        lastEaten = 0;
    } else if (world->isCellZoomie(x + 1, y)) {
        world->removeOrganism(world->getOrganismAt(x + 1, y), x + 1, y);
        lastEaten = 0;
    }
}

void Swoopie::starve() {
    if (lastEaten >= starveTime) {
        world->removeOrganism(this, x, y);
    }
}
