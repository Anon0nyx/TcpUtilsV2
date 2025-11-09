#pragma once
#include "TcpHttpProtocol.h"
#include <string>
#include <sstream>
#include <iostream>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SOCKET int
#define closesocket(s) close(s)
#endif

class TcpHttpServer : public TcpHttpProtocol {
  public:
    virtual void run() = 0;
    virtual void initialize_routes() = 0;
    std::string handle_get_request(const std::string& data) override;
    void handle_client(SOCKET conn);
    void start_listening();

    TcpHttpServer();
};
