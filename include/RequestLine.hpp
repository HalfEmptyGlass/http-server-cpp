#pragma once

#include <string>

struct RequestLine {
    std::string m_method;
    std::string m_path;
    std::string m_http_version;

    std::string to_string();
};