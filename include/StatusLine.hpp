#pragma once

#include <string>

struct StatusLine {
    std::string m_http_version;
    int         m_status_code;
    std::string m_reason_phrase;
};