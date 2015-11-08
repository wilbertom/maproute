#ifndef MR_IP_C
#define MR_IP_C

#include <maproute/ip.h>

IPV4::IPV4(
    ipv4_component x,
    ipv4_component y,
    ipv4_component a,
    ipv4_component b
) {
    this->set_x(x);
    this->set_y(y);
    this->set_a(a);
    this->set_b(b);
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

void IPV4::set_x(ipv4_component c) {
    this->x = c;
}

void IPV4::set_y(ipv4_component c) {
    this->y = c;
}

void IPV4::set_a(ipv4_component c) {
    this->a = c;
}

void IPV4::set_b(ipv4_component c) {
    this->b = c;
}

#endif
