#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for srand()
#include "World.h"
#include "Zoomie.h"
#include "Swoopie.h"

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Create a world with a 30x30 grid
    World world(30);

    // Populate the world with Zoomies and Swoopies
    for (int i = 0; i < 10; ++i) {
        int x = std::rand() % 30; // Random x-coordinate
        int y = std::rand() % 30; // Random y-coordinate
        world.addOrganism(new Zoomie(x, y, &world), x, y);
    }
    for (int i = 0; i < 5; ++i) {
        int x = std::rand() % 30; // Random x-coordinate
        int y = std::rand() % 30; // Random y-coordinate
        world.addOrganism(new Swoopie(x, y, &world), x, y);
    }

    world.display();

    // Simulate movement and behavior over multiple time steps
    for (int step = 0; step < 10; ++step) {
        std::cout << "Time Step: " << step << std::endl;
        // Move Swoopies first
        world.moveSwoopies();
        // Move Zoomies
        world.moveZoomies();
        // Display current state of the world
        world.display();
        // Pause for a moment (optional)
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    // Clean up memory
    // No need to explicitly delete organisms, as World's destructor takes care of it

    return 0;
}
