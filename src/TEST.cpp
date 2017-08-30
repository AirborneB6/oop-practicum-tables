#include "include/Table.h"
#include "include/TablePrinter.h"
#include <stdlib.h>
#include <cstdio>

const int ROWS_NUM = 5;
const int COLS_NUM = 5;

int main ()
{
    Table sample(3 , 2);

    sample.getCell(0 , 0).setValue("ayy lmao");
    sample.getCell(0 , 1).setValue(5.43);
    sample.getCell(1 , 0).setValue("firetruck");
    sample.getCell(1 , 1).setValue(1337);
    sample.getCell(2 , 0).setValue(42);
    sample.getCell(2 , 1).setValue(5.5583);

    TablePrinter printer;

    printer.printTable(sample);

    std::cout << std::endl;
    std::cout << sample.getCell(0 , 0).getDataType() << " ";
    std::cout << sample.getCell(0 , 1).getDataType() << " ";
    std::cout << sample.getCell(1 , 0).getDataType() << " ";
    std::cout << sample.getCell(1 , 1).getDataType() << " ";
    std::cout << sample.getCell(2 , 0).getDataType() << " ";
    std::cout << sample.getCell(2 , 1).getDataType() << " ";

    std::cout << std::endl;
    std::cout << printer.getCellCharCount(sample.getCell(0 , 0)) << " ";
    std::cout << printer.getCellCharCount(sample.getCell(0 , 1)) << " ";
    std::cout << printer.getCellCharCount(sample.getCell(1 , 0)) << " ";
    std::cout << printer.getCellCharCount(sample.getCell(1 , 1)) << " ";
    std::cout << printer.getCellCharCount(sample.getCell(2 , 0)) << " ";
    std::cout << printer.getCellCharCount(sample.getCell(0 , 1)) << " ";


}
