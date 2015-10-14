#include "stringUtil.h"
#include <iostream>

unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();
    
    // Decompose statement
    // string::npos on a mac equals 18446744073709551615, but string::find returns
    // 4294967295 when char is not found, equivalent to (unsigned int) (-1)
    while( pos != (unsigned int) (-1) ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr(initialPos, std::min(pos, (unsigned int)txt.size() ) - initialPos + 1 ) );

    return strs.size();
    
}