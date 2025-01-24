#include "handler.h"
#include <iostream>
#include <string>

// Todo 2: Implement (destructor function and print() function) in "handler.cpp" 

HandlerModule::~HandlerModule()
{
    // if(languageFilter!=nullptr)
    // {
    //     delete [] languageFilter;
    //     languageFilter = nullptr;
    // }
    // if(toneFilter!=nullptr)
    // {
    //     delete [] toneFilter;
    //     toneFilter = nullptr;    
    // }
}

void HandlerModule::print() const
{
    std::cout << "Module name = " << m_name << ", this is a Handler, can handle topic = " << topic << std::endl;
}

// Todo 3: Implement "trainData" and "answer" function of "HandlerModule". 

void HandlerModule::trainData(const string &question, const string & answer)
{

    // store trained data in data which maps question and answer
    data.insert(question, answer);
    
}

string HandlerModule::answer(const string &question) const
{
    string translatedQuestion = question;
    // Firstly, it passes the question to the language filter if languageFilter is not a nullptr. 
    if(languageFilter!=nullptr)
    {   
        translatedQuestion = languageFilter->translatePreData(translatedQuestion);
        // cout<<"Translated Question: "<< translatedQuestion<< endl;
    }
    
    // Secondly, it passes the "translated" question to the tone filter if toneFilter is not a nullptr. 
    if(toneFilter!=nullptr)
    {
        if(toneFilter->translatePreData(translatedQuestion)!="Sorry, I don't know")
        {
            translatedQuestion = toneFilter->translatePreData(translatedQuestion);
        }
        // cout<<"Tone filtered question: " << translatedQuestion << endl;
    }
    

    //Thirdly, it queries the inneranswer function, which find the answer within its own data.
    string answer = inneranswer(translatedQuestion);

    // cout<<"Original Answer found: "<<answer<<"\n\n"<<endl;
    
    // Fourthly, it passes the answer to the tone filter if toneFilter is not a nullptr.
    if(toneFilter!=nullptr)
    {
        if(toneFilter->translatePostData(answer)!="Sorry, I don't know")
        {
            answer = toneFilter->translatePostData(answer);
        }
        // cout<<"Tone filtered answer: " << answer << endl;
    }
    
    // Lastly, it passes the answer to the language filter if languageFilter is not a nullptr.
    if(languageFilter!=nullptr)
    {
        if(languageFilter->translatePostData(answer)!="Sorry, I don't know")
            answer = languageFilter->translatePostData(answer);
        // cout << "Translated answer: " << answer << endl;
    }

    return answer;
}

string HandlerModule::inneranswer(const string &question) const
{
    string answer =  data.find(question);
    return answer;
}

//  Todo 6: Implement "HandlerMap"

HandlerMap::HandlerMap():arraySize(0),names(nullptr),handlerModules(nullptr){}

HandlerMap::~HandlerMap()
{
}

void HandlerMap::clear()
{
    if(arraySize!=0)
    {
        if(names!=nullptr)
            delete [] names;
        if(handlerModules!=nullptr)
            delete  [] handlerModules;
        arraySize=0;
        names = nullptr;
        handlerModules = nullptr;
    }
}

void HandlerMap::insert(string key, HandlerModule *value)
{
    if(arraySize==0)
    {
        handlerModules = new HandlerModule*[1];
        names = new string[1];
        handlerModules[0] = value;
        names[0] = key;
        arraySize++;
        return;
    }
    else
    {
        arraySize++;
        HandlerModule **tempModules = new HandlerModule*[arraySize];
        string *tempNames = new string[arraySize];
        for(int i=0;i<arraySize-1;i++)
        {
            tempModules[i] = handlerModules[i];
            tempNames[i] = names[i];
        }
        // cout<<"Array size:"<<arraySize<<endl;
        tempModules[arraySize-1] = value;
        tempNames[arraySize-1] = key;
        delete [] handlerModules;
        delete [] names;
        names = tempNames;
        handlerModules = tempModules;
    }

}

HandlerModule * HandlerMap::find(const string &key) const
{
    if(arraySize==0)
        return nullptr;
    for(int i=0;i<arraySize;i++)
    {
        if(names[i]==key)
        {
            return handlerModules[i];
        }
    }
    return nullptr;
}

string HandlerMap::getNames(int index) const
{
    if(index>=0 && index< arraySize)
        return names[index];
    return nullptr;
}