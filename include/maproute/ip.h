#ifndef MR_IP_H
#define MR_IP_H

#include <string>
#include <maproute/types.h>

//
// Each ipv4 component must be a unsigned integer ranging from 0 to 255
// inclusive. Four of these components and you have a full address.
//
typedef byte ipv4_component;

//
// This is an IP address in the x.y.a.b format
// For now we only support IPV4.
//
class IPV4 {

private:

    ipv4_component x;
    ipv4_component y;
    ipv4_component a;
    ipv4_component b;

public:

    //
    // Creates a new ipv4 instance with the for components needed to
    // have a full address (x.y.a.b).
    //
    IPV4(
        ipv4_component x,
        ipv4_component y,
        ipv4_component a,
        ipv4_component b
    );

    //
    // Creates a new ipv4 instance with an ip address string.
    //
    IPV4(std::string ip);

    void set_x(ipv4_component c);
    ipv4_component get_x() const;

    void set_y(ipv4_component c);
    ipv4_component get_y() const;

    void set_a(ipv4_component c);
    ipv4_component get_a() const;

    void set_b(ipv4_component c);
    ipv4_component get_b() const;

};

#endif
