#ifndef __MODULE_H__
#define __MODULE_H__

#include <iostream>
#include <string>

using namespace std;

class Module
{

public:
    Module(const string &name) : m_name(name){};
    virtual ~Module(){};
    virtual void print() const = 0;
    void setName(const string &newName) { m_name = newName; }
    string getName() { return m_name; }

protected:
    string m_name;
};

#endif // __MODULE_H__