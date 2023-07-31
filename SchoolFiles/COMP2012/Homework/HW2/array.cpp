#include "array.h"

// Todo 1: Implement "DataMap" in "array.cpp"

// default constructor, set pointers to null and array size to 0
DataMap::DataMap() : keys(nullptr), values(nullptr), arraySize(0)
{}

// destructor clean dynamically allocated memory
DataMap::~DataMap()
{
    clear();
}

// clear dynamically allocated memory
void DataMap::clear()
{
    // if not empty, delete dynamically allocated memories
    if(arraySize!=0)
    {
        delete [] keys;
        delete [] values;
        keys = nullptr;
        values = nullptr;;
        arraySize=0;
    }
}

// insert key and value
void DataMap::insert(const string &key, const string &value)
{
    // if no existing keys and values, create new dynamic array for keys and values
    if (this->arraySize==0)
    {
        this->arraySize = 1;
        this->keys = new string[1];
        this->values = new string[1];
        this->keys[0] = key;
        this->values[0] = value; 
    }
    else
    {
        // copy keys and values to temp
        arraySize++;
        string *tempKeys = new string[arraySize];
        string *tempValues = new string[arraySize];
        for (int i = 0;i<arraySize -1; i++)
        {
            tempKeys[i] = keys[i];
            tempValues[i] = values[i];
        }
        tempKeys[arraySize-1] = key;
        tempValues[arraySize-1] = value;
        delete [] keys;
        delete [] values;
        values = tempValues;
        keys = tempKeys;
    }
}

// find value from key
string DataMap::find(const string &key) const
{       
    for (int i=0;i<arraySize;i++)
    {
        if(keys[i]==key)
            return values[i];
    }
    return "Sorry, I don't know";
}
