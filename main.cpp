#include <iostream>
#include <cstdlib>
#include <ctime>
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

    world.display(); // Initial World representation

    // Simulate movement and behavior over multiple time steps
    for (int step = 0; step < 10; ++step) {

        char input;
        bool validInput = false;
        while (!validInput) {
            std::cout << "Do you want to continue to the next step? (y/n): ";
            std::cin >> input;

            switch (input) {
                case 'y':
                case 'Y':
                    validInput = true;
                    break;
                case 'n':
                case 'N':
                    std::cout << "Exiting simulation..." << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        }

        std::cout << "Time Step: " << step << std::endl;
        // Move Swoopies first
        world.moveSwoopies();
        // Move Zoomies
        world.moveZoomies();
        // Display current state of the world
        world.display();
    }

    return 0;
}
