#include "TcpHttpServer.h"
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
#endif


class TcpHttpServerImplementation : public TcpHttpServer {
  public:
    TcpHttpServerImplementation();
    void run() override;
    void initialize_routes() override;
};


