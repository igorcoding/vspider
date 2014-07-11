#ifndef SPIDER_HOST_H
#define SPIDER_HOST_H

#include "common.h"
#include "components/components.h"

#include <vector>
#include <thread>
#include <mutex>


namespace vspider {

class spider_host : ilogger {
public:
    spider_host(int id, int threads_count);
    explicit spider_host(int id);
    ~spider_host();

    int id() const;
    int threads_count() const;

    void start();
    void stop();


    void test();

private:
    void worker(int thread_id);

private:
    int _id;
    int _threads_count;
    std::vector<std::thread> _threads;
    std::vector<bool> _conds;

    std::mutex _log_m;
    std::mutex _q_m;

    url_queue* _queue;

    static const std::string NAME;
};

}

#endif // SPIDER_HOST_H
