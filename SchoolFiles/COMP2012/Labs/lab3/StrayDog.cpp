#include <iostream>
#include "StrayDog.h"


StrayDog::StrayDog(const std::string &name, const std::string &location, const std::string &color) : Dog(name, location), color(color) {
    std::cout << "Dog " << get_name() << " is a " << get_color() << " stray dog." << std::endl;
}

//  TODO: Write the StrayDog::get_color() function
std::string StrayDog::get_color() const { // return string color, since it is a accessor we need const
    return color;
}

void StrayDog::bark_to_boar() const {
    std::cout << "Stray dog " << get_name() << " barks to boar at " << get_location() << "." << std::endl;
}
