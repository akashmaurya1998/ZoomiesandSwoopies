#include <iostream>
#include "World.h"
#include "Zoomie.h"
#include "Swoopie.h"

World::World(int gridSize) : size(gridSize) {
    // Initialize the grid with nullptrs
    grid.resize(size, std::vector<Organism*>(size, nullptr));
}

World::~World() {
    // Deallocate memory for organisms in the grid
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] != nullptr) {
                delete grid[i][j];
            }
        }
    }
}

void World::addOrganism(Organism* organism, int x, int y) {
    // Add organism to the specified position in the grid
    if (x >= 0 && x < size && y >= 0 && y < size) {
        grid[x][y] = organism;
    } else {
        std::cout << "Invalid position. Organism not added." << std::endl;
    }
}

void World::removeOrganism(Organism* organism, int x, int y) {
    if (x >= 0 && x < size && y >= 0 && y < size && grid[x][y] == organism) {
        grid[x][y] = nullptr;
    } else {
        std::cout << "Invalid position or organism not found. Organism not removed." << std::endl;
    }
}

bool World::isCellEmpty(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size && grid[x][y] == nullptr;
}

bool World::isCellZoomie(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size && dynamic_cast<Zoomie*>(grid[x][y]) != nullptr;
}

Organism* World::getOrganismAt(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return grid[x][y];
    }
    return nullptr;
}

void World::moveSwoopies() {
    // Move all Swoopies in the grid
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            if (grid[x][y] != nullptr && dynamic_cast<Swoopie*>(grid[x][y]) != nullptr) {
                grid[x][y]->move();
            }
        }
    }
}

void World::moveZoomies() {
    // Move all Zoomies in the grid
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y) {
            if (grid[x][y] != nullptr && dynamic_cast<Zoomie*>(grid[x][y]) != nullptr) {
                grid[x][y]->move();
            }
        }
    }
}

void World::display() const {
    // Display the grid with appropriate characters representing Zoomies and Swoopies
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (grid[x][y] != nullptr) {
                if (dynamic_cast<Zoomie*>(grid[x][y]) != nullptr) {
                    std::cout << "o "; // Zoomie representation
                } else if (dynamic_cast<Swoopie*>(grid[x][y]) != nullptr) {
                    std::cout << "x "; // Swoopie representation
                }
            } else {
                std::cout << "- "; // Empty cell representation
            }
        }
        std::cout << std::endl;
    }
}
