#pragma once

#include "HttpMethod.hpp"
#include <string>

struct RequestLine {
        // std::string m_method;
        HttpMethod  m_http_method  = HttpMethod::UNKNOWN;
        std::string m_path         = "";
        std::string m_http_version = "HTTP/1.1";

        std::string to_string();
};