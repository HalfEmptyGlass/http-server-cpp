#include "HttpMethod.hpp"
#include <algorithm>

// Define the static constants
const HttpMethod HttpMethod::GET("GET");
const HttpMethod HttpMethod::POST("POST");
const HttpMethod HttpMethod::PUT("PUT");
const HttpMethod HttpMethod::DELETE("DELETE");
const HttpMethod HttpMethod::PATCH("PATCH");
const HttpMethod HttpMethod::OPTIONS("OPTIONS");
const HttpMethod HttpMethod::UNKNOWN("UNKNOWN");

HttpMethod::HttpMethod(const std::string& s): m_name(s) {}

bool HttpMethod::operator==(const HttpMethod& rhs) const { return m_name == rhs.m_name; }

bool HttpMethod::operator!=(const HttpMethod& rhs) const { return !(*this == rhs); }

std::string HttpMethod::to_string() const { return m_name; }