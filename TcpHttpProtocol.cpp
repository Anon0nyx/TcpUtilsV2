#include "TcpHttpProtocol.h"
#include <string>
#include <unordered_map>

void TcpHttpProtocol::initialize_mime_types() {
  mime_types[".html"] = "text/html";
  mime_types[".css"] = "text/css";
  mime_types[".js"] = "application/javascript";
  mime_types[".png"] = "image/png";
  mime_types[".jpg"] = "image/jpeg";
  mime_types[".gif"] = "image/gif";
  mime_types[".svg"] = "image/svg+xml";
  mime_types[".json"] = "application/json";
}
