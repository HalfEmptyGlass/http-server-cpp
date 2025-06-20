#pragma once

#include "Request.hpp"
#include "RequestLine.hpp"
#include <string>
#include <string_view>

class Http {
  public:
    inline static constexpr std::string_view CRLF       = "\r\n";
    inline static constexpr std::string_view HEADER_END = "\r\n\r\n";

    enum class Status : int {
      Continue           = 100,
      SwitchingProtocols = 101,
      Processing         = 102,

      Ok                          = 200,
      Created                     = 201,
      Accepted                    = 202,
      NonAuthoritativeInformation = 203,
      NoContent                   = 204,
      ResetContent                = 205,
      PartialContent              = 206,

      MultipleChoices   = 300,
      MovedPermanently  = 301,
      Found             = 302,
      SeeOther          = 303,
      NotModified       = 304,
      TemporaryRedirect = 307,
      PermanentRedirect = 308,

      BadRequest                  = 400,
      Unauthorized                = 401,
      PaymentRequired             = 402,
      Forbidden                   = 403,
      NotFound                    = 404,
      MethodNotAllowed            = 405,
      NotAcceptable               = 406,
      ProxyAuthenticationRequired = 407,
      RequestTimeout              = 408,
      Conflict                    = 409,
      Gone                        = 410,
      LengthRequired              = 411,
      PreconditionFailed          = 412,
      PayloadTooLarge             = 413,
      URITooLong                  = 414,
      UnsupportedMediaType        = 415,
      RangeNotSatisfiable         = 416,
      ExpectationFailed           = 417,

      InternalServerError     = 500,
      NotImplemented          = 501,
      BadGateway              = 502,
      ServiceUnavailable      = 503,
      GatewayTimeout          = 504,
      HTTPVersionNotSupported = 505
    };

    static Request                                      parse_request(const char* buffer);
    static RequestLine                                  parse_request_line(std::string_view str);
    static std::unordered_map<std::string, std::string> parse_headers(std::string_view str);
};
