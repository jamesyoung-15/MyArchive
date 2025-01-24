#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
    std::string name;
public:
    Animal(const std::string &name);

    std::string get_name() const;
};

#endif