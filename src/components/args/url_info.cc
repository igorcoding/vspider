#include "url_info.h"

#include <regex>
#include <iostream>
#include <Poco/URI.h>

namespace vspider {
namespace args {

url_info::url_info(const std::string& url, priority_t priority)
    : _raw_url(url),
      _port(80),
      _priority(priority)
{
    parse_url();
}

url_info::~url_info()
{

}

void url_info::set_priority(priority_t p)
{
    _priority = p;
}

url_info url_info::create_relative(const url_info& base, const std::string& path)
{
    Poco::URI uri;
    uri.setScheme(base.scheme());
    uri.setHost(base.host());
    uri.setPort(base.port());
    uri.setPath(path);
    return url_info(uri.toString());
}

bool url_info::is_relative(const std::string& path)
{
    Poco::URI uri(path);
    return uri.isRelative();
}






void url_info::parse_url()
{
    auto url = this->raw_url();

    Poco::URI uri(url);
    uri.normalize();
    _url = uri.toString();

    _scheme = uri.getScheme();
    _host = uri.getHost();
    _port = uri.getPort();
    _path = uri.getPath();
    _query = uri.getQuery();
    _hash = uri.getFragment();
}

bool operator <(const url_info& u1, const url_info& u2)
{
    return u1._priority < u2._priority;
}

} // namespace args
} // namespace vspider




