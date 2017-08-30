#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <cstdio>

#include "ValueTypeEnum.h"


class Cell
{
private:

    unsigned short int dataType;

    char* stringValue;
    int intValue;
    double doubleValue;

    bool isEmpty;

public:

    //CONSTRUCTORS
    Cell();
    Cell(const Cell& other); //copy
    Cell(const char* _value);
    Cell(int _value);
    Cell(double _value);

    //DESTRUCTOR
    ~Cell();

    //SETTERS
    void setDataType(unsigned short int _dataType);
    void setValue(const char* _value);
    void setValue(int _value);
    void setValue(double _value);
    void nullify();

    //GETTERS
    unsigned short int getDataType() const;

    void* getValue();

    char* getStringValue() const;
    int getIntValue() const;
    double getDoubleValue() const;
    bool getIsEmpty() const;

    //OPERATORS
    Cell& operator= (const Cell& other);

};

//STREAM OPERATORS
std::ostream& operator<< (std::ostream& os , const Cell& obj);
std::istream& operator>> (std::istream& is , Cell& obj);


#endif // CELL_H
