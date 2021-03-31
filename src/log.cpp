#include <log.hpp>

void pear::log(const char *format, ...)
{
    va_list vl;
    va_start(vl, format);

    char *target = new char[strlen(format) + 128];
    
    vsprintf(target, format, vl);

    printf("\033[1;32m[ Pear ]\033[0m %s  \n",
           target);
    
    va_end(vl);
    
    delete[] target;
}
