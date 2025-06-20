#pragma once

#include "RequestLine.hpp"
#include <string>
#include <unordered_map>

struct Request {
  public:
    RequestLine                                  m_request_line;
    std::unordered_map<std::string, std::string> m_header;
    std::string                                  m_body;

    void print() const;
};
