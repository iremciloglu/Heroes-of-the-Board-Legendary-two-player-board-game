//
// Created by Turgut on 6/2/2023.
//

#include "Board.h"
#include "Knight.h"
#include "Pieces.h"
#include "Bowman.h"
#include "Elf.h"
#include "Mage.h"
#include "Spearman.h"
#include "Ranger.h"
#include "Swordsman.h"

Board::Board() {

    this->row_num = 4;
    this->column_num = 3;
    p =new Pieces ** [row_num];

    for (int i = 0; i < row_num; i++) {
        p[i] = new Pieces*[column_num];
    }
   for (int i = 0; i < row_num; i++){
    for (int j = 0; j < column_num; j++) {
        p[i][j] =  new Pieces();
    }}
    elf_count=3;
    mage_count=2;
    ranger_count=2;
    knight_count=1;
}

Board::Board(Pieces** pieces_list, int row, int column) {
    this->row_num = row;
    this->column_num = column;
    *p = new Pieces * [row_num];

    for (int i = 0; i < row_num; i++) {
        *p[i] = new Pieces[column_num];
        for (int j = 0; j < this->column_num; j++) {
            *p[i][j] = pieces_list[i][j];
        }
    }
}

int Board::getRowNum() {
    return row_num;
}

void Board::setRowNum(int row) {
    this->row_num = row;
}

int Board::getColumnNum() {
    return column_num;
}

void Board::setColumnNum(int column) {
    this->column_num = column;
}

Pieces*** Board::getPieces(void) {
    return p;
}

void Board::setPieces(Pieces** pieces_list) {
    for(int i=0;i<row_num;i++)
        for(int j=0;j<column_num;j++)
            this->p[i][j]->operator=(pieces_list[i][j]);
}

void Board::showPiece(int x, int y) {
      if(p[x][y]->getLife()!=0)
    cout << p[x][y]->getCharacter() << "(" << p[x][y]->getLife() << ")" << " ";
      else
          cout << "(" << p[x][y]->getLife() << ")" << " ";
}

void Board::printBoard(int i, int player) {

    if (player == 1)
        for (int j = 0; j < this->column_num; j++)
            showPiece(i, j);

    else
        for (int j = this->column_num - 1; j >= 0; j--)
            showPiece(i, j);


    if (i == 0)
        cout << " A";

    else if (i == 1)
        cout << " B";

    else if (i == 2)
        cout << " C";

    else
        cout << " D";
}

bool Board::isEmptyCoordinate(int x, int y) {

    if (p[x][y]->getLife()==0)
        return true;
    else
        return false;
}

bool Board::addPiece(int x, int y, char c) { //if else açıp boardda o piece için yeterli sayı yoksa baştan karakter seçtirsin

    if (c == 'B' || c == 'b') {
        if(y==0 || y==1)
        { p[x][y] = new Bowman();
        return true;}
        else
            return false;

    }
    if (c == 'E' || c == 'e') {
        if(y==0 || y==1)
        {  p[x][y] = new Elf();
            elf_count--;
            return true;}
        else
            return false;

    }






     if (c == 'M' || c == 'm')

     {
         if(y==0 || y==1)
         { p[x][y] = new Mage();
             mage_count--;
             return true;}
         else
             return false;

     }






     if (c == 'S' || c == 's')
     {
         if(y==1 || y==2)
         { p[x][y] = new Spearman();
             return true;}
         else
             return false;

     }

     if (c == 'R' || c == 'r')
     {
         if(y==2 || y==1)
         {  p[x][y] = new Ranger();
             ranger_count--;;
             return true;}
         else
             return false;

     }






     if (c == 'W' || c == 'w')
     {
         if(y==2 || y==1)
         { p[x][y] = new Swordsman();
             return true;}
         else
             return false;

     }

    if(c=='K' || c=='k')
    {
        if(y==2 || y==1)
        { p[x][y] = new Knight();
            knight_count--;
            return true;}
        else
            return false;

    }




return false;
}

bool Board::checkCharacter(char c) {

    if (c == 'B' || (c == 'E' && getElfCount()!=0) || (c == 'M' && getMageCount()!=0) || c == 'S' || (c == 'R' && getRangerCount()!=0) || c == 'W' || (c == 'K' && getKnightCount()!=0))
        return true;

    else if (c == 'b' || (c == 'e' && getElfCount()!=0) || (c == 'm' && getMageCount()!=0) || c == 's' || (c == 'r' && getRangerCount()!=0) || c == 'w' || (c == 'k' && getKnightCount()!=0))
        return true;

    else
        return false;
}

Board::~Board() {
    // Deallocate memory for each row
    for (int i = 0; i < row_num; i++) {
        delete[] p[i];
    }
    // Deallocate memory for the rows
    delete[] p;
}

Board& Board::operator=(const Board& std) {
    if (this == &std)
    {
        return *this;
    }

    for (int i = 0; i < row_num; i++) {
        delete[] p[i];
    }
    delete[] p;

    *p = new Pieces * [row_num];

    for (int i = 0; i < row_num; i++)
        *p[i] = new Pieces[column_num];

    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < column_num; j++) {
            p[i][j] = std.p[i][j];
        }
    }

    this->row_num = std.row_num;
    this->column_num = std.column_num;
    return *this;
}

int Board::getElfCount() {

    return elf_count;

}

int Board::getKnightCount() {
    return knight_count;
}

int Board::getMageCount() {
    return mage_count;;
}

int Board::getRangerCount() {
    return ranger_count;
}