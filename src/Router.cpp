#include "Router.hpp"

void Router::add_route(const std::string& method, const std::string& path,
                       std::function<Response(const Request&)> handler) {
  std::string key = route_key(method, path);
  m_routes[key]   = handler;
  m_supported_methods[path].insert(method);
}

Response Router::handle(const Request& req) {
  std::string key = route_key(req.m_request_line.m_method, req.m_request_line.m_path);

  auto route_it = m_routes.find(key);
  if(route_it != m_routes.end()) {
    return route_it->second(req);
  }

  auto method_it = m_supported_methods.find(req.m_request_line.m_path);
  if(method_it != m_supported_methods.end()) {
    return Response::s_method_not_allowed();   // 405
  }

  return Response::s_not_found();   // 404
}

std::string Router::route_key(const std::string& method, const std::string& path) const {
  return method + ":" + path;
}