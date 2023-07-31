#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
private:
    std::string location;
public:
    Dog(const std::string &name, const std::string &location);

    std::string get_location() const;

    void go_to(const std::string &location);
};

#endif