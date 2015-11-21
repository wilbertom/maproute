#ifndef MR_TRACE_GATEWAY_H
#define MR_TRACE_GATEWAY_H

#include <maproute/ip.h>

// Sometimes responses hang and are never received. In this scenario traceroute
// outputs a '*'. We will represent this with TRACE_GATEWAY_NO_RESPONSE.
#define TRACE_GATEWAY_NO_RESPONSE (-1)

typedef struct TraceGateway {
    int hop_number;
    IPV4 *ip;
    // milliseconds or TRACE_GATEWAY_NO_RESPONSE
    double ms_1;
    double ms_2;
    double ms_3;
} TraceGateway;

#endif
