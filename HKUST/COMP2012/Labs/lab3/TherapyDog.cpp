#include <iostream>
#include "TherapyDog.h"

TherapyDog::TherapyDog(const std::string &name, const std::string &location, const std::string &employment) : Dog(name, location), employment(employment) {
    std::cout << "Dog " << get_name() << " is a " << get_employment() << " therapy dog." << std::endl;
}

std::string TherapyDog::get_employment() const {
    return employment;
}

void TherapyDog::smile() const {
    std::cout << "Therapy dog " << get_name() << " smiles at " << get_location() << "." << std::endl;
}
