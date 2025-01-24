#ifndef BOAR_H
#define BOAR_H

#include "Animal.h"

//  TODO: Complete the class declaration of Boar
class Boar : public Animal
{
    private:
        std::string location;
    public:
        Boar(const std::string &name, const std::string &location);
        ~Boar();
        std::string get_location() const;

        void go_to(const std::string &location);
        void bite_package() const;
};


#endif