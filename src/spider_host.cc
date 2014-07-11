#include "spider_host.h"

namespace vspider {

const std::string spider_host::NAME = type_name<spider_host>();

spider_host::spider_host(int id, int threads_count)
    : ilogger(NAME),
      _id(id),
      _threads_count(threads_count),
      _queue(new url_queue(NAME))
{
    auto v = std::vector<std::shared_ptr<url_info>>({
                                                       std::make_shared<url_info>("http://www.cplusplus.com/reference/regex/regex_search/"),
                                                       std::make_shared<url_info>("http://www.google.com"),
                                                    });
    _queue->add(v);
    ls().information() << "Spider Host #" << this->_id << " started" << std::endl;
}

spider_host::spider_host(int id)
    : spider_host(id, std::thread::hardware_concurrency())
{

}

spider_host::~spider_host()
{
    stop();
    delete _queue;
    _queue = nullptr;
    ls().information() << "Spider Host #" << this->_id << " stopped" << std::endl;
}

int spider_host::id() const
{
    return _id;
}

int spider_host::threads_count() const
{
    return _threads_count;
}

void spider_host::start()
{
    for (int i = 0; i < _threads_count; ++i)
    {
        auto th = std::thread(&spider_host::worker, this, i);
        _threads.emplace_back(std::move(th));
        _conds.push_back(true);
    }
}

void spider_host::stop()
{
    for (size_t i = 0; i < _conds.size(); ++i)
    {
        _conds[i] = false;
    }

    for (size_t i = 0; i < _threads.size(); ++i)
    {
        _threads[i].join();
    }
}

void spider_host::worker(int thread_id)
{
    auto dl = new downloader(NAME);
    auto arg = std::make_shared<url_info>("http://www.cplusplus.com/reference/regex/regex_search/");
    _queue->add(arg);
    while (_conds[thread_id])
    {
        _log_m.lock();
        ls().information() << "working thread #" << thread_id << std::endl;
        _log_m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    delete dl;
}


void spider_host::test()
{
    auto downloader = new vspider::downloader(NAME);
    auto arg = std::make_shared<url_info>("http://www.cplusplus.com/reference/regex/regex_search/");
//    auto arg = std::make_shared<url_info>("www.microsoft.com");
    downloader->exec(arg);
}

}
