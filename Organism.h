#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
protected:
    int x, y; // position of the organism
    int stepsSurvived; // to track the time steps survived

public:
    Organism(int posX, int posY);
    virtual ~Organism() {}

    // Virtual function to perform movement
    virtual void move() = 0;

    // Virtual function to handle breeding
    virtual void breed() = 0;

    // Getter functions for position
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // ORGANISM_H
