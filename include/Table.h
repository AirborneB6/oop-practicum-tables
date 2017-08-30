#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include <cstdio>
#include <string.h>

#include "include/Cell.h"
#include "include/ValueConverter.h"

/*
    is memory fragmentation an issue?
*/


class Table
{
public:

    //CTORS
    Table();
    Table(unsigned int _rows , unsigned int _cols);

    //DTOR
    ~Table();

    //SETTERS
    void setCell(const Cell& _cell , const int& posR , const int& posC);
    void setRows(const int& _rows);
    void setCols(const int& _cols);
    void setDetails(const char* _details);

    //GETTERS
    Cell& getCell(const int& posR , const int& posC) const;
    const int getRows() const;
    const int getCols() const;
    const char* getDetails() const;

    //OPERATORS
    const Table& operator= (const Table& other);

protected:
private:

    Cell** cellMatrix;
    char* details;

    int cols;
    int rows;

    //MEMORY HANDLING
    void initTableMem();
    void freeTableMem();

};

std::ostream& operator<< (std::ostream& os , const Table& obj);

std::istream& operator>> (std::istream& is , Cell& obj);

#endif // TABLE_H
