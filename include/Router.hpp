#pragma once

#include "Request.hpp"
#include "Response.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Router {
  public:
    void add_route(const std::string& method, const std::string& path,
                   std::function<Response(const Request&)> handler);

    Response handle(const Request& req);
    Router() = default;

  private:
    std::string route_key(const std::string& method, const std::string& path) const;

    std::unordered_map<std::string, std::function<Response(const Request&)>> m_routes;
    std::unordered_map<std::string, std::unordered_set<std::string>>         m_supported_methods;
};