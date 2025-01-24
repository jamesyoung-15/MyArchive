#ifndef __HANDLER_H__
#define __HANDLER_H__
#include <string>
#include "module.h"
#include "filter.h"

class HandlerModule : public Module
{

public:
    HandlerModule(const string &name, const string &topic) : Module(name), topic(topic)
    {
        this->languageFilter = nullptr;
        this->toneFilter = nullptr;
    };
    //-------You need to define destructor and print for HandlerModule-------
    //-------You are only supposed to modify code below-------
    //  Todo 2: Add function declaration in "handler.h"
    ~HandlerModule();
    virtual void print() const;
    // helper information: std::cout << "Module name = " << m_name << ", this is a Handler, can handle topic = " << topic << std::endl;
    //-------You are only supposed to modify code above-------
    string getTopic() const { return topic; }
    void trainData(const string &question, const string &answer);
    string answer(const string &question) const;
    void setLanguageFilter(FilterModule *input) { this->languageFilter = input; }
    void setToneFilter(FilterModule *input) { this->toneFilter = input; }

protected:
    string inneranswer(const string &question) const;

    string topic;
    FilterModule *languageFilter;
    FilterModule *toneFilter;
    DataMap data;
};

class HandlerMap
{
public:
    HandlerMap();
    ~HandlerMap();

    int size() const { return arraySize; }
    void insert(string key, HandlerModule *value);
    HandlerModule *find(const string &key) const;
    string getNames(int index) const;
    void clear();

private:
    int arraySize;
    string *names;
    HandlerModule **handlerModules;
};
#endif // __HANDLER_H__