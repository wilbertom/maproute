#include <iostream>
#include <string>
#include <maproute/ip.hpp>
#include <maproute/ip_convertor.hpp>
#include <maproute/stringhelp.hpp>
#include <maproute/tr_parser.hpp>
#include <maproute/ip_location_finder.hpp>

int main() {

    while (std::cin.good()) {
        std::string line;
        std::string ip_string;
        IPV4Convertor convertor{};
        TracerouteLineParser parser{};
        IPV4 ip {0, 0, 0, 0};

        std::getline(std::cin, line);
        bool success = parser.parse(&line, &ip);

        if (!success) {
            std::cerr << "Failed to parse: '"
                      << line
                      << "' did the request timeout?"
                      << std::endl;
        } else {
            convertor.ip_to_string(&ip, &ip_string);
            std::cout << ip_string << std::endl;
        }
    }
    
    return 0;

}
