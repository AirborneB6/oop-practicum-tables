#ifndef VALUE_CONVERTER_H
#define VALUE_CONVERTER_H

#include "include/Cell.h"


class ValueConverter
{
private:


public:
    int toInt(char* _value);
    float toFloat (char* _value);
    float parseOperations(char* _value);

};
#endif // VALUE_CONVERRTER_H
