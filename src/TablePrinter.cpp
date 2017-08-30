#include "include/TablePrinter.h"

//CONSTRUCTORS
TablePrinter::TablePrinter()
{

}

TablePrinter::TablePrinter(const Table& tableToPrint)
{
    this->tempTable = tableToPrint;
}

//DESTRUCTOR
TablePrinter::~TablePrinter()
{

}


void TablePrinter::printTable(const Table& _table) const
{
    for (int ROW = 0 ; ROW < _table.getRows() ; ROW++)
    {
        for (int COL = 0 ; COL < _table.getCols() ; COL++)
        {
            std::cout<<_table.getCell(ROW , COL) << " ";
        }
    }
}

void TablePrinter::printDetails(const Table& _table) const
{
    std::cout<<_table.getDetails();
}

//COLUMN SPACING
int* TablePrinter::updateSpacings()
{
    int maxCols = tempTable.getCols(); //avoid multiple getter calls
    int maxRows = tempTable.getRows();

    delete[] this->spacings;
    this->spacings = new int[maxCols];

    int buffer = 0;

    for (int i = 0 ; i < maxRows ; i++)
    {
        for (int j = 0 ; j < maxCols ; j++)
        {
                spacings[i] = getCellCharCount(tempTable.getCell(i , j));
        }
    }
}




int TablePrinter::getCellCharCount(const Cell& _cell) const
{
    if (_cell.getDataType() == charString ||
        _cell.getDataType() == operation)

    {
        return (strlen(_cell.getStringValue()));
    }
    else if (_cell.getDataType() == integer)
    {
        char arr[64];
        sprintf(arr , "%d" , _cell.getIntValue());
        return strlen(arr);
    }
    else if (_cell.getDataType() == doubleFloat)
    {
        char arr[64];
        sprintf(arr , "%Lf" , _cell.getDoubleValue());
        return strlen(arr);
    }
}

