#include "ilogger.h"

namespace vspider {

ilogger::ilogger(const std::string& name, const std::string& parent_name)
    : _logger(nullptr),
      _ls(nullptr),
      _name(name),
      _parent_name(parent_name)
{

}

ilogger::~ilogger()
{
    _logger = nullptr;
    delete _ls;
    _ls = nullptr;
}

Poco::Logger& ilogger::logger()
{
    init_logsystem();
    return *_logger;
}

Poco::LogStream& ilogger::ls()
{
    init_logsystem();
    return *_ls;
}

void ilogger::init_logsystem()
{
    if (_logger == nullptr && _ls == nullptr)
    {
        if (_parent_name == "") {
            _logger = &(Poco::Logger::get(_name));
        }
        else {
            _logger = &(Poco::Logger::get(_parent_name).get(_name));
        }
        _ls = new Poco::LogStream(*_logger);
    }
}

}
