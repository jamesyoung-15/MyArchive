#ifndef __LEGOGPT_H__
#define __LEGOGPT_H__
#include "module.h"
#include "filter.h"
#include "handler.h"
#include "array.h"

using namespace std;

class LegoGPT
{
public:
    LegoGPT(){};
    ~LegoGPT();
    void LoadHandlerModule(HandlerModule &input);
    void LoadFilterModule(FilterModule &input);
    void printHandlers() const;
    void printFilters() const;
    void printTopics() const;
    void printLanguages() const;
    void clear();
    void chat(string topic, string question) const;

private:
    HandlerMap handlerMap;
    FilterArray filterArray;
    Array topics;
    Array languages;
};

#endif // __LEGOGPT_H__