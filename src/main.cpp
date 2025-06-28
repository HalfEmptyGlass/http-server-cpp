#include "Server.hpp"
#include "ServerConfig.hpp"
#include <iostream>
#include <memory>

// Remove client_fd from response!!
//  create a connection class

int main(int argc, char** argv) {
  std::shared_ptr<Router> router = std::make_shared<Router>();
  router->add_route("GET", "/helloworld", [](const Request& req) -> Response {
    Response res = Response::s_ok();
    res.m_body   = "Hello World";
    return res;
  });

  ServerConfig config;
  config.m_port       = 4421;
  config.http_version = "HTTP/1.1";
  Server server{config, router};

  // IDEAL SCENARIO
  // WebApp app;
  // app.get("/", [](Request& req, Response& res) {
  //       res.send("Hello, World!");
  // });

  server.run();

  return 0;
}
