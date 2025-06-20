#include "RequestLine.hpp"

std::string RequestLine::to_string() { return m_method + " " + m_path + " " + m_http_version; }