//
// Created by Turgut on 6/2/2023.
//
#include "Pieces.h"
#ifndef FINALGAME_BOARD_H
#define FINALGAME_BOARD_H
using namespace std;
#include <iostream>

class Board {
private:
    int row_num;
    int column_num;
    Pieces **p;
public:
    Board();
    Board(Pieces**, int, int);
    int getRowNum();
    void setRowNum(int);
    int getColumnNum();
    void setColumnNum(int);
    Pieces** getPieces(void);
    void setPieces(Pieces**);
    void showPiece(int x, int y);
   // Pieces getPieceInfo(int x, int y);
    void printBoard(int i);
    bool isEmptyCoordinate(int x,int y);
    void addPiece(int x,int y,char c);
    void showAllPieces(void);
    bool checkCharacter(char character);
   // int hit(Pieces** board2, int player,int row);
    ~Board();
    Board& operator=(const Board& std);
};







#endif //FINALGAME_BOARD_H
