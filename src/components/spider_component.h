#ifndef SPIDER_COMPONENT_H
#define SPIDER_COMPONENT_H

#include "../common.h"
#include "args/arg.h"

namespace vspider {
using namespace args;

template <typename InType, typename OutType>
class spider_component : public ilogger
{
public:
    spider_component(const std::string& name, const std::string& parent_name);
    virtual ~spider_component() = 0;

    virtual std::shared_ptr<OutType> exec(std::shared_ptr<InType> input) = 0;
};

/******************* IMPLEMENTATION *******************/

template <typename InType, typename OutType>
spider_component<InType, OutType>::spider_component(const std::string& name, const std::string& parent_name)
    : ilogger(name, parent_name)
{
}

template <typename InType, typename OutType> inline
spider_component<InType, OutType>::~spider_component()
{

}

}

#endif // SPIDER_COMPONENT_H
