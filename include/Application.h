#ifndef APPLICATION_H
#define APPLICATION_H

#include "include/TableFile.h"
#include "include/Table.h"
#include "include/TablePrinter.h"


class Application
{

public:

    Application();
    ~Application();

    void mainLoop();
    void exit();


protected:



private:

    Table currentTable;
    TablePrinter print;
    TableFile tFile;


    //include self-made Date class?
    //introduce a CommandLine class?
    //introduce a parser for operations in the printer?

};



//! MENU LOOK
/*
    > open C:\Temp\file.xml
    > close
    > save
    > saveas "C:\Temp\another file.xml"
    > exit

    > print
    > edit
*/



#endif // APPLICATION_H
