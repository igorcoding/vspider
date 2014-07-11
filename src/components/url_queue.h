#ifndef URL_QUEUE_H
#define URL_QUEUE_H

#include "spider_component.h"
#include "args/url_info.h"
#include "args/raw_document_info.h"

#include <queue>

namespace vspider {

class url_queue : public spider_component<arg, arg>
{
public:
    explicit url_queue(const std::string& parent_name);
    ~url_queue();
    std::shared_ptr<arg> exec(std::shared_ptr<arg> input) override;

    void add(std::shared_ptr<url_info> url);
    void add(const std::vector<std::shared_ptr<url_info>>& urls);

private:


private:
    std::priority_queue<std::shared_ptr<url_info>> _queue;
};

}

#endif // URL_QUEUE_H
