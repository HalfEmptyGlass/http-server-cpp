#include "Request.hpp"
#include <iostream>
void Request::print() const {
    std::string CRLF = "\r\n";
    std::cout << "Request Line: " << m_request_line.m_method << " " << m_request_line.m_path << " " << m_request_line.m_http_version << CRLF;
    std::cout << "Header:" << CRLF;
    for (const auto& [key, value] : m_header) {
        std::cout  << "  " << key << ": " << value << CRLF;
    }
    std::cout << "Body: " << m_body;
    std::cout << std::endl;
  }