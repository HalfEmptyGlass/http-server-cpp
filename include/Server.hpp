#pragma once

#include <cstdint>

class Server {
public:
  Server(uint16_t port);

  void run();

private:
  uint16_t m_port;

  void handle_connection(int client_fd);
};
