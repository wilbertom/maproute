#ifndef MR_IP_CONVERTOR_C
#define MR_IP_CONVERTOR_C

#include <maproute/ip_convertor.h>
#include <maproute/stringhelp.h>

void IPV4Convertor::ip_to_string(const IPV4 *ip, std::string *buffer) {

    buffer->append(std::to_string(ip->get_x()));
    buffer->push_back('.');
    buffer->append(std::to_string(ip->get_y()));
    buffer->push_back('.');
    buffer->append(std::to_string(ip->get_a()));
    buffer->push_back('.');
    buffer->append(std::to_string(ip->get_b()));

}

void IPV4Convertor::string_to_ip(const std::string *ip, IPV4 *out) {

    int dot_index_1 = ip->find('.', 0);
    int dot_index_2 = ip->find('.', dot_index_1 + 1);
    int dot_index_3 = ip->find('.', dot_index_2 + 1);

    std::string xs = string_get(ip, 0, dot_index_1);
    std::string ys = string_get(ip, dot_index_1 + 1, dot_index_2);
    std::string as = string_get(ip, dot_index_2 + 1, dot_index_3);
    std::string bs = string_get(ip, dot_index_3 + 1);

    out->set_x(stoi(xs));
    out->set_y(stoi(ys));
    out->set_a(stoi(as));
    out->set_b(stoi(bs));

}

#endif
