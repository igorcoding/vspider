#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include "spider_component.h"
#include "args/url_info.h"
#include "args/raw_document_info.h"

#include <vector>
#include <set>

namespace vspider {

class downloader : public spider_component<url_info, raw_document_info>
{
public:
    explicit downloader(const std::string& parent_name);
    ~downloader();
    std::shared_ptr<raw_document_info> exec(std::shared_ptr<url_info> input) override;


private:
    bool check_scheme(const std::string& scheme) const;

private:
    static std::set<std::string> supported_schemes;
};

}

#endif // DOWNLOADER_H
