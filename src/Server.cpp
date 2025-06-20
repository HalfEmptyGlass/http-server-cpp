#include "Server.hpp"

#include "Http.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>

Server::Server(uint16_t port): m_port(port) {}

void Server::run() {
  std::cout << "Web server starting...\n";
  // Get a socketId
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(server_fd < 0) {
    std::cerr << "Failed to create server socket\n";
    exit(EXIT_FAILURE);
  }

  // set socketId to certain configurations
  int reuse = 1;
  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
    std::cerr << "setsockopt failed\n";
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family      = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port        = htons(m_port);

  // set ip and port of socket
  if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) != 0) {
    std::cerr << "Failed to bind to port\n";
    exit(EXIT_FAILURE);
  }

  // marks socket as a "listening" socket and can have at most 5 pending connections
  int connection_backlog = 5;
  if(listen(server_fd, connection_backlog) != 0) {
    std::cerr << "listen failed\n";
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in client_addr;
  socklen_t          client_addr_len = sizeof(client_addr);

  std::cout << "Waiting for a client to connect...\n";
  while(true) {
    int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);
    if(client_fd < 0) {
      std::cerr << "Failed to accept client.\n";
      continue;
    }

    std::jthread(&Server::handle_connection, this, client_fd);
  }
}

void Server::handle_connection(int client_fd) {
  std::cout << "Client connected\n";
  char buffer[4096];
  int  bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

  if(bytes_read > -1) {
    buffer[bytes_read] = '\0';
    Request request    = Http::parse_request(buffer);
    request.print();
  }

  Response res{client_fd};
  res.set_body("Hello World");
  res.send();

  close(client_fd);
}
