#include "TcpUtils.h"
#include <string>
#include <unordered_map>


class TcpHttpProtocol : TcpUtils
{
  protected:
    std::unordered_map<std::string, std::string> routes;
    std::unordered_map<std::string, std::string> post_routes;
    std::unordered_map<std::string, std::string> get_routes;


  public:
    virtual void initialize_routes() = 0;
    virtual void handle_get_request(const <std::string>& data) = 0;
    virtual void handle_post_request(const <std::string>& data) = 0;

};