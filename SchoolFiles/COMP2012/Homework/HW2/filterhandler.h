#ifndef __FILTERHANDLER_H__
#define __FILTERHANDLER_H__
#include <string>
#include "filter.h"
#include "handler.h"

class FilterHandlerModule : public HandlerModule, public FilterModule
{
private:
public:
    FilterHandlerModule(const string &name, const FilterType &type, const string &topic) : FilterModule(name, type), HandlerModule(name, topic){};
    virtual ~FilterHandlerModule()
    {
        data.clear();
        languageFilter = nullptr;
        toneFilter = nullptr;
        preData.clear();
        postData.clear();
    }
    virtual void print() const
    {
        std::cout << "Module name = " << FilterModule::m_name << ", this is a filterHandler, filter type = "
                  << getFilterType(type) << ", handler topic = " << topic << std::endl;
    };
};
#endif // __FILTERHANDLER_H__