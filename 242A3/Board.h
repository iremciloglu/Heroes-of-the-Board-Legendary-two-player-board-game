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
    Pieces** p;
    int mage_count;
    int knight_count;
    int elf_count;
    int ranger_count;
public:
    Board();
    Board(Pieces**, int, int);
    int getRowNum();
    void setRowNum(int);
    int getColumnNum();
    void setColumnNum(int);
    Pieces** getPieces(void);
    void setPieces(Pieces**);
    void showPiece(int, int);
    // Pieces getPieceInfo(int x, int y);
    void printBoard(int, int);
    bool isEmptyCoordinate(int, int);
    bool addPiece(int, int, char);
    bool checkCharacter(char);
    int getMageCount(void);
    int getElfCount(void);
    int getKnightCount(void);
    int getRangerCount(void);
    ~Board();
    Board& operator=(const Board&);
};

#endif //FINALGAME_BOARD_H