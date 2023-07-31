#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <string>
#include <iostream>

using namespace std;

class DataMap
{
public:
    DataMap();
    ~DataMap();

    int size() const { return arraySize; }
    void insert(const string &key, const string &value);
    string find(const string &key) const;
    void clear();

private:
    int arraySize;
    string *keys;
    string *values;
};

class Array
{
public:
    Array()
    {
        arraySize = 0;
        array = nullptr;
    }
    ~Array() { clear(); }
    inline void insert(const string &input);
    inline string get(int index) const;
    void clear()
    {
        if (arraySize != 0)
        {
            arraySize = 0;
            delete[] array;
        }
    };

    int size() const { return arraySize; }

private:
    int arraySize;
    string *array;
};

// Usually, the implementation is put in the source file.
// But please note that it can also be put in the header file.
inline void Array::insert(const string &input)
{
    if (0 == arraySize)
    {
        arraySize = 1;
        array = new string[1];
        array[0] = input;
        return;
    }
    arraySize++;
    string *temp = new string[arraySize];
    for (int i = 0; i < arraySize - 1; i++)
    {
        temp[i] = array[i];
    }
    temp[arraySize - 1] = input;
    delete[] array;
    array = temp;
    return;
}

inline string Array::get(int index) const
{
    if (index < 0)
    {
        return nullptr;
    }
    if (index < arraySize)
    {
        return array[index];
    }
    else
    {
        return nullptr;
    }
}

#endif // __ARRAY_H__