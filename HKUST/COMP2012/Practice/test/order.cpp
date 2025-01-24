#include <iostream>
using namespace std;
class ExhaustFan {
public:
    ExhaustFan() { cout << "E"<< endl; }
    ~ExhaustFan() { cout << "~E"<< endl; }
};
class Bathroom {
    private:
        string name;
        ExhaustFan exhaustFan;
    public:
        Bathroom(string n) { name = n; cout << "B" << endl; }
        ~Bathroom() { cout << "~B" << endl; }
};
class Kitchen {
    private:
        string name;
        ExhaustFan* exhaustFan;
    public:
        Kitchen(string n) : exhaustFan(new ExhaustFan) { name = n; cout << "K" << endl; }
        ~Kitchen() { delete exhaustFan; cout << "~K" << endl; }
};
class Apartment {
    private:
        Kitchen kitchen;
        Bathroom bathroom;
    public:
        Apartment() : 
        bathroom("Warm bathroom"),
        kitchen("Amazing kitchen") { cout << "A" << endl; }
        ~Apartment() { cout << "~A" << endl; }
};
int main() {
    Apartment* apartment = new Apartment;
    delete apartment;
}