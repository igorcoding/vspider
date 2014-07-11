#ifndef URL_ARG_H
#define URL_ARG_H

#include "arg.h"

#include <string>

namespace vspider {
namespace args {

enum class priority_t
{
    LOW,
    MEDIUM,
    HIGH
};

class url_info : public arg
{
public:
    url_info(const std::string& url, priority_t priority = priority_t::LOW);
    ~url_info();

    const std::string& raw_url() const;
    const std::string& url() const;
    const std::string& scheme() const;
    const std::string& host() const;
    int port() const;
    const std::string& path() const;
    const std::string& query() const;
    const std::string& hash() const;
    const priority_t& priority() const;
    void set_priority(priority_t p);

    static url_info create_relative(const url_info& base, const std::string& path);
    static bool is_relative(const std::string& path);

    friend bool operator <(const url_info& u1, const url_info& u2);

private:
    void parse_url();

private:
    std::string _raw_url;
    std::string _url;
    std::string _scheme;
    std::string _host;
    int _port;
    std::string _path;
    std::string _query;
    std::string _hash;
    priority_t _priority;
};

/********************** IMPLEMENTATION **********************/


inline const std::string& url_info::raw_url() const
{
    return _raw_url;
}

inline const std::string& url_info::url() const
{
    return _url;
}

inline const std::string& url_info::scheme() const
{
    return _scheme;
}

inline const std::string& url_info::host() const
{
    return _host;
}

inline int url_info::port() const
{
    return _port;
}

inline const std::string& url_info::path() const
{
    return _path;
}

inline const std::string& url_info::query() const
{
    return _query;
}

inline const std::string& url_info::hash() const
{
    return _hash;
}

inline const priority_t& url_info::priority() const
{
    return _priority;
}

} // namespace args
} // namespace vspider


#endif // URL_ARG_H
