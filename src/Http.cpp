#include "Http.hpp"

#include "Utils.hpp"
#include <vector>

Request Http::parse_request(const char* buffer) {
  Request          request;
  std::string      requestString{buffer};
  std::string_view request_view{requestString};

  // Get request line
  size_t           request_line_index = request_view.find(CRLF);
  std::string_view request_line       = request_view.substr(0, request_line_index);
  request.m_request_line              = parse_request_line(request_line);

  // Get Headers
  size_t           headers_index = request_view.find(Http::HEADER_END);
  std::string_view headers
      = request_view.substr(request_line_index + 2, headers_index - (request_line_index + 2));
  request.m_header = parse_headers(headers);

  // Get Body
  request.m_body = request_view.substr(headers_index + 4);
  return request;
}

RequestLine Http::parse_request_line(std::string_view str) {
  std::vector<std::string> vec = utils::split_by_token(str, " ");
  RequestLine              request_line;
  request_line.m_method       = vec[0];
  request_line.m_path         = vec[1];
  request_line.m_http_version = vec[2];
  return request_line;
}

std::unordered_map<std::string, std::string> Http::parse_headers(std::string_view str) {
  std::vector<std::string>                     vec = utils::split_by_token(str, CRLF);
  std::unordered_map<std::string, std::string> header;
  for(const auto& i : vec) {
    std::vector<std::string> line = utils::split_by_token(i, ": ");
    if(line.size() == 2) {
      header.insert({line[0], line[1]});
    }
  }
  return header;
}
