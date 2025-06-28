#pragma once

#include <memory>

struct ServerConfig {
    uint16_t    m_port       = 8080;
    std::string http_version = "HTTP/1.1";
};