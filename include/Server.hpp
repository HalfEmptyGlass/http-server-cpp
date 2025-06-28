#pragma once

#include "Router.hpp"
#include "ServerConfig.hpp"
#include <cstdint>
#include <memory>

class Server {
  public:
    Server(ServerConfig config, std::shared_ptr<Router> router);

    void run();

  private:
    ServerConfig            m_config;
    std::shared_ptr<Router> m_router;
};
