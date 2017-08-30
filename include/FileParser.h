#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "include/Table.h"

#include <fstream>


class FileParser
{
public:

    FileParser();
    ~FileParser();

    //GET FROM FILE
    Table parseToTable(std::ifstream& file);
    bool checkValidity(std::ifstream& file);

    //OUTPUT TO FILE
    std::ofstream parseToFile(const Table& _table);

    //VALIDITY
    bool checkForComments();


protected:
private:

    Table tempTable;

};


#endif // FILEPARSER_H


//! SAMPLE FILE
/*
    //comment lines are disregarded by the checks
    //but are put into the "details" field
    1 , 5 , 7
    ,,3
    1 , , 3
    , 2 , 3

*/


