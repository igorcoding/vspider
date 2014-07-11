#ifndef MAIN_H
#define MAIN_H

#ifndef PLATFORM_UNIX
#error Unix system is required.
#endif

#include <iostream>
#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>
#include <Poco/AsyncChannel.h>
#include <Poco/AutoPtr.h>

#include "spider_host.h"

void logger_init() {
    using Poco::Logger;
    using Poco::ConsoleChannel;
    using Poco::FormattingChannel;
    using Poco::PatternFormatter;
    using Poco::AsyncChannel;
    using Poco::AutoPtr;

    AutoPtr<ConsoleChannel> pCons(new ConsoleChannel);
//    AutoPtr<AsyncChannel> pAsync(new AsyncChannel(pCons));

    AutoPtr<PatternFormatter> pPF(new PatternFormatter);
    pPF->setProperty("pattern", "[%p] %Y-%m-%d %H:%M:%S %s [%P | %I]: %t");
    AutoPtr<FormattingChannel> pFC(new FormattingChannel(pPF, pCons));

//    pChannel->setProperty("path", "sample.log");
//    pChannel->setProperty("rotation", "2 K");
//    pChannel->setProperty("archive", "timestamp");

    Logger::root().setChannel(pFC);
}

#endif // MAIN_H
