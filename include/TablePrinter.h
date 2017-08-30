#ifndef TABLEPRINTER_H
#define TABLEPRINTER_H

#include "include/Table.h"
#include "include/Cell.h"

/*
    functor class.
    keeps state of a temp Table, and updates on a cell by cell basis

    avoids re-calculation of spacings after the initialization.
    biggest issue is the first mandatory check for changed values,
    but implementing a bool Table::isCurrent would
    introduce class coupling.

    The temp table holds all the formula conversions,
    literal integers and doubles. The 2D spacings array
    holds spacing information, used in the object
    parentheses call (e.g. "print()").
*/

class TablePrinter
{
public:

    //CONSTRUCTORS
    TablePrinter();
    TablePrinter(const Table& tableToPrint);

    //DESTRUCTOR
    ~TablePrinter();

    //PRINT HELPER FUNCTIONS
    void printTable(const Table& table) const;
    void printDetails(const Table& _table) const;

    //COLUMN SPACING
    int* updateSpacings();
    int getCellCharCount(const Cell& _cell) const;

protected:
private:

    Table tempTable;

    int* maxColSpacing;
    int* spacings;

    void calculateOperations();

};


#endif // TABLEPRINTER_H

