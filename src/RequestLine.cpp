#include "RequestLine.hpp"

std::string RequestLine::to_string() {
    return m_http_method.to_string() + " " + m_path + " " + m_http_version;
}