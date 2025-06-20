#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

class Response {
public:
  Response(int client_fd);

  void set_body(std::string_view body);

  void set_header(std::string_view key, std::string_view value);
  void send() const;

private:
  int m_client_fd;
  std::string m_status_line;
  std::unordered_map<std::string, std::string> m_header;
  std::string m_body;
};