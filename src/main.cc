#include "main.h"

int main()
{
    using namespace std;
    logger_init();

    vspider::spider_host sp_host(0, 1);
//    sp_host.start();
//    std::this_thread::sleep_for(std::chrono::seconds(10));
    sp_host.test();

    cout << "All done." << endl;
    return 0;
}

