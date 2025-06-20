#include "Response.hpp"
#include <format>
#include <sys/socket.h>
#include "Http.hpp"

Response::Response(int client_fd) : m_client_fd(client_fd), m_status_line("HTTP/1.1 200 OK") , m_header({}), m_body("") {
    m_header["Content-Type"] = "text/plain";
}

void Response::set_body(std::string_view body) {
    m_body = body;
}

void Response::set_header(std::string_view key, std::string_view value) {
    m_header[std::string(key)] = std::string(value);
}

void Response::send() const {
    std::string response = m_status_line;
    response += Http::CRLF;
    response += "Content-Length: ";
    response += std::to_string(m_body.size());
    response += Http::CRLF;
    for(const auto& [key, value] : m_header) {
        response += std::format("{}: {}\r\n", key, value);  
    }
    response += Http::CRLF;
    response += m_body;
    ::send(m_client_fd, response.c_str(), response.length(), 0);
}
