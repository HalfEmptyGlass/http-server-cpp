#pragma once

#include "Router.hpp"
#include <memory>

class Connection {
  public:
    Connection(int client_fd, std::shared_ptr<Router> router);
    void handle();

  private:
    int                     m_client_fd;
    std::shared_ptr<Router> m_router;
};