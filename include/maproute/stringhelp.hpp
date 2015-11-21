#ifndef MR_STRING_HELP_H
#define MR_STRING_HELP_H

#include <string>

//
// Gets a new string starting at the string's ith index up to the
// jth - 1 characther.
//
std::string string_get(const std::string *self, int ith, int jth);

//
// Gets the string from the ith characther to the last.
//
std::string string_get(const std::string *self, int ith);

#endif
