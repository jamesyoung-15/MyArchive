#ifndef __FILTER_H__
#define __FILTER_H__
#include "module.h"
#include "array.h"

enum FilterType
{
    language,
    tone,
    reserved
};

inline string getFilterType(const FilterType &type)
{
    switch (type)
    {
    case language:
        return "language";
    case tone:
        return "tone";
    case reserved:
        return "reserved";
    default:
        return "default";
    }
}

class FilterModule : public Module
{

public:
    FilterModule(const string &name, const FilterType type) : Module(name), type(type){};
    //-------You need to define destructor and print for HandlerModule-------
    //-------You are only supposed to modify code below-------

    // Todo 4: Add function declaration in `filter.h`
    ~FilterModule();
    virtual void print() const;

    // helper information: std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getFilterType(type) << std::endl;
    //-------You are only supposed to modify code above-------

    FilterType getType() const { return type; }
    void trainPreData(const string &source, const string &target);
    void trainPostData(const string &source, const string &target);
    string translatePreData(string question) const;
    string translatePostData(string question) const;

protected:
    FilterType type;
    DataMap preData;
    DataMap postData;
};

class FilterArray
{
public:
    FilterArray()
    {
        arraySize = 0;
        array = nullptr;
    }
    ~FilterArray() { clear(); }
    void insert(FilterModule *input);
    FilterModule *get(int index) const;
    void clear()
    {
        if (arraySize != 0)
        {
            arraySize = 0;
            delete[] array;
        }
        return;
    };

    int size() const { return arraySize; }

private:
    int arraySize;
    FilterModule **array;
};

#endif // __FILTER_H__