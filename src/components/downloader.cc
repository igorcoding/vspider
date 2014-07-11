#include "downloader.h"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <iostream>

namespace vspider {

std::set<std::string> downloader::supported_schemes({
                                                        "http"
                                                    });

downloader::downloader(const std::string& parent_name)
    : spider_component(type_name<downloader>(), parent_name)
{

}

downloader::~downloader()
{

}

std::shared_ptr<raw_document_info> downloader::exec(std::shared_ptr<url_info> input)
{
    if (check_scheme(input->scheme()))
    {
        logger().information("Begin downloading page: " + input->url());

        using namespace Poco::Net;
        HTTPClientSession s(input->host(), input->port());
        HTTPRequest request(HTTPRequest::HTTP_GET, input->path());
        s.sendRequest(request);
        HTTPResponse response;
        std::istream& rs = s.receiveResponse(response);
        Poco::StreamCopier::copyStream(rs, std::cout);

        logger().information("Finished downloading page: " + input->url());
        return nullptr;
    }
    else
    {
        logger().notice("Url " + input->url() + " has not been downloaded. Scheme " + input->scheme() + " is not supported");
        return nullptr;
    }
}

bool downloader::check_scheme(const std::string& scheme) const
{
    auto end = std::end(supported_schemes);
    return std::find(std::begin(supported_schemes), end, scheme) != end;
}



}
