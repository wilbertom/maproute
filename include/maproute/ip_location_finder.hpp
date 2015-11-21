#ifndef MR_IP_LOCATION_FINDER_H
#define MR_IP_LOCATION_FINDER_H

#include <sqlite3.h>

#include <maproute/ip.hpp>
#include <maproute/ip_convertor.hpp>

//
// Finds IP address' locations. This class is implemented by having a sqlite3
// database with IP ranges for cities and states. We use:
// http://lite.ip2location.com/
//
// If you have a better source for this just overwrite this class
// implementation.
//
class IPLocationFinder {

private:
    IPV4Convertor convertor{};
    const char *database_path = IP_DATABASE_PATH;
    sqlite3 *db;

public:

    IPLocationFinder();

    //
    // Returns true when the location was found. Right now it just prints
    // the results found in the database. In the future it will fill the data
    // into an output parameter.
    //
    bool get_location(const IPV4 *ip);

    //
    // Close all external data sources like database connections.
    // Should be called when we are done with instances of this object.
    //
    void close();

};

#endif
