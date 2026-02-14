#pragma once

#include <string>

class HttpMethod {
    public:
        static const HttpMethod GET;
        static const HttpMethod POST;
        static const HttpMethod PUT;
        static const HttpMethod DELETE;
        static const HttpMethod PATCH;
        static const HttpMethod OPTIONS;
        static const HttpMethod UNKNOWN;

        HttpMethod(const std::string& s);
        bool        operator==(const HttpMethod& rhs) const;
        bool        operator!=(const HttpMethod& rhs) const;
        std::string to_string() const;

    private:
        std::string m_name;
};
