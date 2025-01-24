#include "filter.h"
#include "handler.h"


// Todo 4:  Implement destructor and print in `filter.cpp` 

FilterModule::~FilterModule()
{}

void FilterModule::print() const
{
    std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getFilterType(type) << std::endl;
}

//  Todo 5: Implement "trainPreData", "trainPostData", "translatePreData", "translatePostData"

void FilterModule::trainPreData(const string &source, const string &target)
{
    // preData stores the data for translation of handlers's questions
    preData.insert(source, target);
}
void FilterModule::trainPostData(const string &source, const string &target)
{
    //  stores the data for translation of handlers's answers
    postData.insert(source, target);
}
string FilterModule::translatePreData(string question) const
{
    string newQuestion = preData.find(question);
    return newQuestion;
}
string FilterModule::translatePostData(string question) const
{
    string newAnswer = postData.find(question);
    return newAnswer;
}


// Todo 6: Implement "FilterArray" in "filter.cpp"
void FilterArray::insert(FilterModule *input)
{
    if(arraySize==0)
    {
        arraySize++;
        array = new FilterModule*[arraySize];
        array[0] = input;
        return;
    }
    else 
    {
        arraySize++;
        FilterModule** temp = new FilterModule*[arraySize];
        for(int i=0;i<arraySize-1;i++)
        {
            temp[i] = array[i];
        }
        temp[arraySize-1] = input;
        delete [] array;
        array = temp;
    }
}

FilterModule* FilterArray::get(int index) const
{
    if(arraySize==0)
        return nullptr;
    return array[index];
}