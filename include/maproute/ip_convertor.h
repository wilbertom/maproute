#ifndef MR_IP_CONVERTOR_H
#define MR_IP_CONVERTOR_H

#include <string>
#include <maproute/ip.h>

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

};

#endif
