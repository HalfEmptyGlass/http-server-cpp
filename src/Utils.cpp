#include "Utils.hpp"

namespace utils {

  std::vector<std::string> split_by_token(std::string_view str, std::string_view token) {
    std::vector<std::string> result;
    size_t start = 0;

    while(start < str.size()) {
      size_t i = str.find(token, start);
      if(i == std::string::npos) {
        result.push_back(std::string(str.substr(start)));
        break;
      }
      result.push_back(std::string(str.substr(start, i - start)));
      start = i + token.size();
    }
    return result;
  }

  void print(std::string_view str) {
    std::cout << "=====";
    std::cout << str;
    std::cout << "=====" << std::endl;
  }
};