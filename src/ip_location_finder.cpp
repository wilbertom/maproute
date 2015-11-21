#ifndef MR_IP_LOCATION_FINDER_C
#define MR_IP_LOCATION_FINDER_C

#include <iostream>

#include <maproute/ip_location_finder.hpp>
#include <maproute/types.h>


int process_lines(void *data, int columns, char **row, char **row_columns) {

    for (int i = 0; i < columns; i++) {
        std::cout << row[i] << ", ";
    }

    std::cout << std::endl;

    return 0;
}

IPLocationFinder::IPLocationFinder() {
    int result = sqlite3_open(this->database_path, &this->db);

    if (result != SQLITE_OK) {
        std::cout << "Error opening a connection to the database" << std::endl;
    }

}

bool IPLocationFinder::get_location(const IPV4 *ip) {
    uint ip_number = this->convertor.ip_to_uint(ip);

    std::string query = "" \
        "SELECT country_name, region_name, city_name, latitude, longitude " \
        "FROM ips WHERE ";
    query.append(std::to_string(ip_number));
    query.append(" BETWEEN ip_from AND ip_to");

    int result = sqlite3_exec(
        this->db, query.c_str(), process_lines, NULL, NULL
    );

    bool ok = result == SQLITE_OK;

    return ok;
}

void IPLocationFinder::close() {
    int result = sqlite3_close_v2(this->db);

    if (result != SQLITE_OK) {
        std::cout << "Error closing a connection to the database" << std::endl;
    }

}

#endif
