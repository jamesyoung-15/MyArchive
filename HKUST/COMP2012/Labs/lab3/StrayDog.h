#ifndef STRAYDOG_H
#define STRAYDOG_H

#include "Dog.h"

class StrayDog : public Dog {
private:
    std::string color;
public:
    StrayDog(const std::string &name, const std::string &location, const std::string &color);

    std::string get_color() const;

    void bark_to_boar() const;

};

#endif