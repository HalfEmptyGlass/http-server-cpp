#include "Connection.hpp"

#include "Http.hpp"
#include <format>
#include <iostream>
#include <sys/socket.h>

Connection::Connection(int client_fd, std::shared_ptr<Router> router):
    m_client_fd(client_fd), m_router(router) {}

void Connection::handle() {
  std::cout << "Client connected\n";
  char buffer[4096];
  int  bytes_read = recv(m_client_fd, buffer, sizeof(buffer) - 1, 0);

  if(bytes_read > -1) {
    buffer[bytes_read] = '\0';
    Request request    = Http::parse_request(buffer);
    request.print();
    Response    res      = m_router->handle(request);
    std::string response = res.m_status_line.m_http_version + " "
                         + std::to_string(res.m_status_line.m_status_code) + " "
                         + res.m_status_line.m_reason_phrase;
    response += Http::CRLF;
    response += "Content-Length: ";
    response += std::to_string(res.m_body.size());
    response += Http::CRLF;
    for(const auto& [key, value] : res.m_header) {
      response += std::format("{}: {}\r\n", key, value);
    }
    response += Http::CRLF;
    response += res.m_body;
    ::send(m_client_fd, response.c_str(), response.length(), 0);
  }

  close(m_client_fd);
}