#ifndef MR_IP_CONVERTOR_H
#define MR_IP_CONVERTOR_H

#include <string>

#include <maproute/types.hpp>
#include <maproute/ip.hpp>

// TODO: rename IPV4 to IP, we can transform ipv6 by overloading methods

//
// A class that converts various formats of ipv4 addresses.
//
class IPV4Convertor {

public:

    //
    // Converts an IP into a string in the format x.y.a.b.
    //
    void ip_to_string(const IPV4 *ip, std::string *buffer);

    //
    // Parses an IP in the format x.y.a.b into the out IP.
    //
    void string_to_ip(const std::string *ip, IPV4 *out);

    //
    // Converts an IP into an unsigned integer as described in
    // http://lite.ip2location.com/faqs. This integer format makes it easy to
    // query IP ranges.
    //
    uint ip_to_uint(const IPV4 *ip);

};

#endif
