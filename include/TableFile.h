#ifndef TABLEFILE_H
#define TABLEFILE_H

#include <fstream>

#include "include/Table.h"

class TableFile
{

public:

    TableFile();
    ~TableFile();

    Table& open();
    void save (Table& currentTable);
    void saveAs (std::string path , Table& currentTable);



protected:



private:

    std::fstream file;
    bool fileExists;

};


#endif // TABLEFILE_H
