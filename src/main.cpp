#include <iostream>
#include "Server.hpp"
// TODO
// move parsing functions from Request to HTTP
// any opertations on the raw buffer/request should be operated by the HTTP class





class Router {

};


int main(int argc, char **argv) {
  Server server{4421};

  // IDEAL SCENARIO
  // WebApp app;
  // app.get("/", [](Request& req, Response& res) {
  //       res.send("Hello, World!");
  // });

  server.run();

  return 0;
}
