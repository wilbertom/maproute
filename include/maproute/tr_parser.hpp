#ifndef MR_TR_PARSER_H
#define MR_TR_PARSER_H

#include <string>
#include <vector>

#include <maproute/ip.hpp>

//
// This class parses a single output of the traceroute command into a
// TraceGateway structure.
//
// This parser expects that the traceroute command is ran with the -n flag.
//
// Every normal line has this format:
// <integer> <ip-address> <float> ms <float> ms <float> ms
//
// The initial integer is optional sometimes we just get a space characther for
// it. Meaning that the gateway is related to the previous one. When that is
// the case only one packet is timed.
//
//   <ip-address> <float> ms
//
// Every packet timing seems to be optional. Therefore we have the following
// format:
// [<integer>] <ip-address> [<float> ms] [<float> ms] [<float> ms]
//
class TracerouteLineParser {

public:

    //
    // Parses the line and creates a trace gateway record.
    // Returns true if all went ok.
    //
    bool parse(std::string *line, IPV4 *out);

};


#endif
