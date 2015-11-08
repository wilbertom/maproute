#ifndef MR_IP_C
#define MR_IP_C

#include <maproute/ip.h>

IPV4::IPV4(
    ipv4_component x,
    ipv4_component y,
    ipv4_component a,
    ipv4_component b
) {
    this->x = x;
    this->y = y;
    this->a = a;
    this->b = b;
}

ipv4_component IPV4::get_x() const {
    return this->x;
}

ipv4_component IPV4::get_y() const {
    return this->y;
}

ipv4_component IPV4::get_a() const {
    return this->a;
}

ipv4_component IPV4::get_b() const {
    return this->b;
}

#endif
