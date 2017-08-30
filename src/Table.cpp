#include "include/Table.h"

//CONSTRUCTORS
Table::Table(unsigned int _rows , unsigned int _cols)
{
    this->rows = _rows;
    this->cols = _cols;

    initTableMem();
}
Table::Table()
{
    this->rows = 1;
    this->cols = 1;
    initTableMem();
}


//DESTRUCTOR
Table::~Table()
{
    freeTableMem();
}


//PRIVATE MEMORY HANDLING
void Table::freeTableMem()
{
    /*
    std::cout<<"entered freeMEM!\n";

    for (int r = 0 ; r < this->rows ; r++)
    {
        for (int c = 0 ; c < this->cols ; c++)
        {
            std::cout << "row :" << r << " col:" << c << " value:" << cellMatrix[r][c] << std::endl;

            cellMatrix[r][c] . ~Cell();
        }
        std::cout<<std::endl;
    }

    std::cout<<"called CELL destructors!\n";

    for (int i = 0 ; i < this->rows ; i++)
    {
        std::cout<<"entering row clearing!!\n";
        free(cellMatrix[i]);
    }

    std::cout<<"freed column blocks!\n";

    free (this->cellMatrix);
    this->cellMatrix = NULL;
    */

    for(int i = 0; i < this->rows; i++)
    {
        delete cellMatrix[i];
    }

    delete[] cellMatrix;
}
void Table::initTableMem()
{
    /*
    std::cout<<"entered initMEM!\n";
    this->cellMatrix = (Cell**) malloc(this->rows * sizeof(Cell*));
    std::cout<<"malloc 1 complete!\n";
    for (int i = 0 ; i < this->rows ; i++)
    {
        this->cellMatrix[i] = (Cell*) malloc(this->cols * sizeof(Cell*));
    }
    std::cout<<"malloc 2 complete!\n";
    std::cout<<"object initialization\n";
    for (int r = 0 ; r < this->rows ; r++)
    {
        for (int c = 0 ; c < this->cols ; c++)
        {
            //cellMatrix[r][c] = new Cell();

            new (&cellMatrix[r][c]) Cell( r + c );
            //! WORKS
        }
    }
    for (int r = 0 ; r < this->rows ; r++)
    {
        for (int c = 0 ; c < this->cols ; c++)
        {
            std::cout << "row :" << r << " col:" << c << " value:" << cellMatrix[r][c] << std::endl;
        }
        std::cout << std::endl;
    }
    */

    this->cellMatrix = new Cell*[this->rows];
    for(int i = 0; i < this->rows; i++)
    {
        cellMatrix[i] = new Cell[this->cols];
    }

    for (int r = 0 ; r < this->rows ; r++)
    {
        for (int c = 0 ; c < this->cols ; c++)
        {
            cellMatrix[r][c].setValue(1337);
        }
    }
}


//SETTERS
void Table::setCell(const Cell& _cell , const int& posR , const int& posC)
{
    this->cellMatrix[posR][posC]  =  _cell;
}
void Table::setRows(const int& _rows)
{
    this->freeTableMem();

    this->rows = _rows;

    this->initTableMem();

}
void Table::setCols(const int& _cols)
{
    this->freeTableMem();

    this->cols = _cols;

    this->initTableMem();
}
void Table::setDetails(const char* _details)
{
    delete[] this->details;
    strcpy(this->details , _details);
}


//GETTERS
Cell& Table::getCell(const int& posR , const int& posC) const
{
    if (posR <= this->rows  &&  posC <= this->cols)
    {
        return this->cellMatrix[posR][posC];
    }
    else
    {
        //! WARNING: CALL OUT OF TABLE BOUNDS
    }
}
const int Table::getRows() const
{
    return this->rows;
}
const int Table::getCols() const
{
    return this->cols;
}
const char* Table::getDetails() const
{
    return this->details;
}


//OPERATORS
const Table& Table::operator= (const Table& other)
{
    if (this == &other)
    {
        return *this;
    }

    this->freeTableMem();

    this->rows = other.getRows();
    this->cols = other.getCols();

    this->initTableMem();

    for (int currRow = 0 ; currRow < this->rows ; currRow++)
    {
        for (int currCol = 0 ; currCol < this->cols ; currCol++)
        {
            this->cellMatrix[currRow][currCol] = other.getCell(currRow , currCol);
        }
    }

    delete[] this->details;

    this->details = new char[strlen(other.getDetails()) + 1];
    strcpy(this->details , other.getDetails());

}







