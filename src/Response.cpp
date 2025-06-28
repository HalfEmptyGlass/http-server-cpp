#include "Response.hpp"
#include "Http.hpp"
#include <format>
#include <sys/socket.h>

std::string Response::s_http_version = "";

Response::Response(StatusLine status_line): m_status_line(status_line), m_header({}), m_body("") {
  m_header["Content-Type"] = "text/plain";
}

void Response::set_body(std::string_view body) { m_body = body; }

void Response::set_header(std::string_view key, std::string_view value) {
  m_header[std::string(key)] = std::string(value);
}

Response Response::s_ok() { return Response({s_http_version, 200, "OK"}); }

Response Response::s_created() { return Response({s_http_version, 201, "Created"}); }

Response Response::s_not_found() { return Response({s_http_version, 404, "Not Found"}); }

Response Response::s_method_not_allowed() {
  return Response({s_http_version, 405, "Method Not Allowed"});
}
