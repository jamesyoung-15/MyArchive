#include <iostream>
#include "Dog.h"

Dog::Dog(const std::string &name, const std::string &location) : Animal(name), location(location) {
    std::cout << "Dog " << get_name() << " comes to " << get_location() << "." << std::endl;
}

std::string Dog::get_location() const {
    return location;
}

void Dog::go_to(const std::string &location) {
    Dog::location = location;
    std::cout << "Dog " << get_name() << " goes to " << get_location() << "." << std::endl;
}
