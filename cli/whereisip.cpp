
#include <iostream>
#include <maproute/ip_location_finder.hpp>
#include <maproute/ip.hpp>

int main(int argc, char **argv) {
    IPV4 ip {0, 0, 0, 0};
    IPV4Convertor convertor{};
    IPLocationFinder finder{};
    std::string ip_string;

    if (argc == 1) {

        while (std::cin.good() ) {
            std::cin >> ip_string;
            convertor.string_to_ip(&ip_string, &ip);
            std::cout << ip_string << ", ";
            finder.get_location(&ip);
        }

    } else {
        finder.close();
        return 1;
    }

    finder.close();
    return 0;

}
