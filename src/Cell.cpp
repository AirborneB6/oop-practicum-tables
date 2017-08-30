#include "include/Cell.h"
#include "include/ValueTypeEnum.h"
#include <iostream>
#include <string.h>


//CONSTRUCTORS
Cell::Cell()
{
    this->nullify();
}
Cell::Cell(const Cell& other)
{
    *this = other;
}
Cell::Cell(const char* _value)
{
    this->setValue(_value);
}
Cell::Cell(int _value)
{
    this->setValue(_value);
}
Cell::Cell(double _value)
{
    this->setValue(_value);
}


//DESTRUCTOR
Cell::~Cell()
{
    delete[] this->stringValue;
}


//SETTERS
void Cell::setDataType(unsigned short int _dataType)
{
    this->dataType = _dataType;
}
void Cell::setValue(const char* _value)
{
    this->nullify();
    this->setDataType(charString);

    this->stringValue = new char[strlen(_value) + 1];
    strcpy(this->stringValue , _value);

    this->isEmpty = false;
}
void Cell::setValue(int _value)
{
    this->nullify();
    this->setDataType(integer);
    this->intValue = _value;

    this->isEmpty = false;
}
void Cell::setValue(double _value)
{
    this->nullify();
    this->setDataType(doubleFloat);
    this->doubleValue = _value;

    this->isEmpty = false;
}
void Cell::nullify()
{
    delete[] this->stringValue;
    //re-deletion protection (ask what happens to the pointer after deletion?)
    this->stringValue = NULL;

    this->intValue = 0;
    this->doubleValue = 0;

    this->isEmpty = true;

}


//GETTERS
//! add warnings for wrong data type calls
unsigned short int Cell::getDataType() const
{
    return this->dataType;
}

void* Cell::getValue()
{
    return &this->dataType;
}

char* Cell::getStringValue() const
{
    return this->stringValue;
}
int Cell::getIntValue() const
{
    return this->intValue;
}
double Cell::getDoubleValue() const
{
    return this->doubleValue;
}

bool Cell::getIsEmpty() const
{
    return this->isEmpty;
}


//OPERATORS
Cell& Cell::operator=(const Cell& other)
{
    if (this != &other)
    {
        this->nullify();


        if (other.getIsEmpty() == false)
        {
            this->dataType = other.getDataType();

            strcpy(this->stringValue , other.getStringValue());
            this->intValue = other.getIntValue();
            this->doubleValue = other.getDoubleValue();
            this->isEmpty = false;
        }
    }
    return *this;
}


//STREAM OPERATORS
std::ostream& operator<< (std::ostream& os , const Cell& obj)
{
    switch (obj.getDataType())
    {
        case integer:
            os << obj.getIntValue();
            break;
        case doubleFloat:
            os<< obj.getDoubleValue();
            break;
        case charString:
            os << obj.getStringValue();
            break;

    }
    return os;
}
std::istream& operator>> (std::istream& is , Cell& obj)
{
    /*
    QUESTION
    some sort of parser is needed here.
    value is entered into a char* via is.getline(),
    char* gets parsed via a method object(???)
    value gets stored into a correct var type
    and then setValue() is called with the correct
    variable type
    */
    return is;
}





