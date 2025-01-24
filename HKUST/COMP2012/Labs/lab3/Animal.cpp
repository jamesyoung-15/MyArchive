#include "Animal.h"

Animal::Animal(const std::string &name) : name(name) {}

std::string Animal::get_name() const {
    return name;
}
