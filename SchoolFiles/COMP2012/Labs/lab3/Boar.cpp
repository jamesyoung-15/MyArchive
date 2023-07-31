#include <iostream>
#include "Boar.h"


//  TODO: Complete the constructor of Boar
// MIL add base class constructor to guarantee everything initialzed, if we initiliaze inside it will create temp object
Boar::Boar(const std::string &name, const std::string &location) : Animal(name), location(location) {
    std::cout << "Boar " << get_name() << " comes to " << get_location() << "." << std::endl;
}

std::string Boar::get_location() const {
    return location;
}

//  TODO: Complete the Boar::go_to function
void Boar::go_to(const std::string &location) {

    std::cout << "Boar " << get_name() << " goes to " << location  << "." << std::endl;
    // update location
    this->location = location;
}

void Boar::bite_package() const {
    std::cout << "Boar " << get_name() << " bites package at " << get_location() << "." << std::endl;
}

Boar::~Boar() {
    std::cout << "Boar " << get_name() << " leaves UST.";
}
