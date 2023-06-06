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
Pieces *p[4][3];
public:
    Board();
    void getPiece(void);
void showPiece(int x,int y);
Pieces getPieceInfo(int x,int y);
void printBoard(int i);
bool isEmptyCoordinate(int x,int y);
void addPiece(int x,int y,char c);
void show_All_Pieces(void);
bool checkCharacter(char character);
int hit(Pieces** board2, int player,int row);
};







#endif //FINALGAME_BOARD_H
