#pragma once

#include "StatusLine.hpp"
#include <string>
#include <string_view>
#include <unordered_map>

class Response {
  public:
    static std::string s_http_version;
    static Response    s_ok();
    static Response    s_created();
    static Response    s_not_found();
    static Response    s_method_not_allowed();

    Response(StatusLine status_line);

    void set_body(std::string_view body);
    void set_header(std::string_view key, std::string_view value);

    std::string                                  m_body;
    StatusLine                                   m_status_line;
    std::unordered_map<std::string, std::string> m_header;
};