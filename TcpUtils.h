#pragma once
#include <unordered_map>
#include <string>
#include <istream>
#include <functional>

#ifdef _WIN32
#include <ws2tcpip.h>
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SOCKET int
#define closesocket(s) close(s)
#endif

class TcpUtils {
  public:
    TcpUtils();
    ~TcpUtils();
    std::unordered_map<std::string, std::string> mime_types;
    SOCKET server_fd;
    int port;

    virtual void initialize_mime_types() = 0;
    SOCKET create_connection(int port = 6969);
    std::string get_current_time();
    std::string get_mime_type(const std::string& path);
    std::string get_file_content(const std::string& path);
    void send_data(SOCKET conn, const std::string& data);
    std::string receive_data(SOCKET conn);
};
