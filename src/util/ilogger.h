#ifndef LOGGER_H
#define LOGGER_H

#include <Poco/Logger.h>
#include <Poco/LogStream.h>
#include <string>

namespace vspider {

using Poco::Logger;
using Poco::LogStream;

class ilogger
{
public:
    ilogger(const std::string& name, const std::string& parent_name = "");
    virtual ~ilogger() = 0;

protected:
    Poco::Logger& logger();
    Poco::LogStream& ls();

private:
    void init_logsystem();

private:
    Poco::Logger* _logger;
    Poco::LogStream* _ls;
    std::string _name;
    std::string _parent_name;
};

}

#endif // LOGGER_H
