#pragma once
#include "TcpUtils.h"
#include <string>
#include <unordered_map>

class TcpHttpProtocol : public TcpUtils {
  public:
    //std::unordered_map<std::string, std::string> routes;
    //std::unordered_map<std::string, std::string> post_routes;
    //std::unordered_map<std::string, std::string> get_routes;

    std::unordered_map<std::string, std::function<std::string(const std::string&)>> get_routes;

    virtual void initialize_routes() = 0;
    virtual std::string handle_get_request(const std::string& data) = 0;
    //virtual void handle_post_request(const std::string& data) = 0;

    void initialize_mime_types() override;
};
