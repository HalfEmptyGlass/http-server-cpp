#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace utils {

  std::vector<std::string> split_by_token(std::string_view str, std::string_view token);

  template<typename T>
  void print_vector(const std::vector<T>& vec) {
    std::cout << "[";
    for(const auto& i : vec) {
      std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
  }

  template<typename K, typename V>
  void print_map(const std::unordered_map<K, V>& map) {
    for(const auto& [key, value] : map) {
      std::cout << key << ": " << value << std::endl;
    }
  }

  void print(std::string_view str);
};   // namespace utils
