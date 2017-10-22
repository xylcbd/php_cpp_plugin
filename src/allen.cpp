#include "allen.h"
#include <string>
#include <cstring>

char* allen_say_to(const char* name)
{
    std::string result = "hello, ";
    result += name;
    return strdup(result.c_str());
}

void release_memory(char* buffer)
{
    free(buffer);
}
