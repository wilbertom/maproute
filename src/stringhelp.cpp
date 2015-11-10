#ifndef MR_STRING_HELP_C
#define MR_STRING_HELP_C

#include <maproute/stringhelp.h>

std::string string_get(const std::string *self, int ith, int jth) {
    return self->substr(ith, jth - ith);
}

std::string string_get(const std::string *self, int ith) {
    return self->substr(ith, self->length());
}

#endif
