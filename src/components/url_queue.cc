#include "url_queue.h"


namespace vspider {

url_queue::url_queue(const std::string& parent_name)
    : spider_component(type_name<url_queue>(), parent_name)
{

}

url_queue::~url_queue()
{

}

std::shared_ptr<arg> url_queue::exec(std::shared_ptr<arg> input)
{

}

void url_queue::add(std::shared_ptr<url_info> url)
{
    _queue.emplace(std::move(url));
}

void url_queue::add(const std::vector<std::shared_ptr<url_info> >& urls)
{
    for (auto& url: urls)
        _queue.emplace(std::move(url));
}



}
