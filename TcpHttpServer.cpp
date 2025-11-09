#include "TcpHttpServer.h"

TcpHttpServer::TcpHttpServer() {
  initialize_mime_types();
}

void TcpHttpServer::start_listening() {
  listen(server_fd, SOMAXCONN);
  std::cout << "Server is listening on port " << port << std::endl;
}

std::string TcpHttpServer::handle_get_request(const std::string& path) {
  std::string file_path = (path == "/") ? "index.html" : path;
  auto route = get_routes.find(file_path);
  if (route != get_routes.end()) return route->second(file_path);

  std::string content = get_file_content(file_path);
  if (content.empty()) return "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\nContent-Length: 9\r\n\r\nNot Found";

  std::ostringstream response;
  response << "HTTP/1.1 200 OK\r\n"
    << "Content-Type: " << this->get_mime_type(file_path) << "\r\n"
    << "Content-Length: " << content.size() << "\r\n\r\n"
    << content;
  return response.str();
}

void TcpHttpServer::handle_client(SOCKET conn) {
  std::string data_in = receive_data(conn);
  std::istringstream request_stream(data_in);
  std::string method, path, version;
  request_stream >> method >> path >> version;

  std::cout << "{'Request type': '" << method;
  std::cout << "', 'Path': '" << path << "', 'Version': '" << version << "'}" << std::endl;

  std::string response;
  if (method == "GET") {
    response = handle_get_request(path);
  } else {
    response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\n\r\nMethod not allowed";
  }
  send_data(conn, response);
  closesocket(conn);
}
