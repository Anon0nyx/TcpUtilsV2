#include "TcpHttpServerImplementation.h"

TcpHttpServerImplementation::TcpHttpServerImplementation() {
  initialize_routes();
}

void TcpHttpServerImplementation::run() {
  port = 6969;
  server_fd = create_connection();
  start_listening();

  while(true) {
    sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    SOCKET client_socket = accept(server_fd, (sockaddr*)&client_addr, &client_size);
    handle_client(client_socket);
  }
}

void TcpHttpServerImplementation::initialize_routes() {
  get_routes["/"] = [this](const std::string&) { return handle_get_request("/index.html"); };
}
