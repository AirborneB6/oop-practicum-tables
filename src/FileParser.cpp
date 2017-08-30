#include "include/FileParser.h"


FileParser::FileParser() : tempTable(1 , 1)
{

}



//GET FROM FILE
Table FileParser::parseToTable(std::ifstream& file)
{
    char lineBuffer[128];
    char wordBuffer[64];

    short int commaCount = -1;

    while (file.getline(lineBuffer , 64 , '\n')) //get line from file
    {
        for (char* c = lineBuffer ; *c != '\n' ; c++) //walk the line
        {



        }

    }

}


//OUTPUT TO FILE
std::ofstream parseToFile(const Table& _table)
{

}
