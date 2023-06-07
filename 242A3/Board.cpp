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
    this->p = new Pieces* [row_num];
    
    for (int i = 0; i < row_num; i++) {
        p[i] = new Pieces[column_num];
        for (int j = 0; j < column_num; j++) {
            p[i][j] = Pieces(); 
        }
    }
}

Board::Board(Pieces** pieces_list, int row, int column) {
    this->row_num = row;
    this->column_num = column;
    this->p = new Pieces * [row_num];

    for (int i = 0; i < row_num; i++) {
        p[i] = new Pieces[column_num];
        for (int j = 0; j < this->column_num; j++) {
            p[i][j] = pieces_list[i][j];
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

Pieces** Board::getPieces(void) {
    return this->p;
}

void Board::setPieces(Pieces** pieces_list) {
    this->p = pieces_list;
}

void Board::showPiece(int x, int y) {

    //if(p[x][y]->getLife()==0)
      //  cout<<"   ";
   // else
    cout << p[x][y].getCharacter() <<"("<<p[x][y].getLife()<<")" <<" ";

}

void Board::printBoard(int i) {// take a look irem

    for(int j=0;j<3;j++) 
        showPiece(i, j);

    if(i==0)
        cout<<" A";

    else if(i==1)
        cout<<" B";

    else if(i==2)
        cout<<" C";

    else
        cout<<" D";

    }

bool Board::isEmptyCoordinate(int x, int y) {

if(p[x][y].getCharacter()==' ')
    return true;
else
    return false;


}

void Board::addPiece(int x, int y,char c) {

  if(c=='B' || c == 'b')
      p[x][y]= Bowman();
  
  else if(c=='E' || c == 'e')
      p[x][y]= Elf();

  else if(c=='M' || c == 'm')
      p[x][y]= Mage();

  else if(c=='S' || c == 's')
      p[x][y]= Spearman();

  else if(c=='R' || c == 'r')
      p[x][y]= Ranger();

  else if(c=='W' || c == 'w')
      p[x][y]= Swordsman();

  else 
      p[x][y]= Knight();
}

void Board::showAllPieces() {// bence bunu maine koyabiliriz

    cout<<"                         Ranged Pieces\n";
    cout<<"           Life      Damage     Char      Number"<<endl;
    cout<<"Bowman      12        3         B        Infinite"<<endl;
    cout<<"Elf         8         6         E        getnum() "<<endl;
    cout<<"Bowman      4         8         M        getnum"<<endl;
    cout<<"                         Meele Pieces\n";
    cout<<"           Life     Damage     Char      Number"<<endl;
    cout<<"Sperman     6         3         S         Infinite"<<endl;
    cout<<"Ranger      8         6         R         getnum() "<<endl;
    cout<<"Swordsman   6         4         W         Infinite"<<endl;
    cout<<"Knight      10        10        K         getnum"<<endl;




}

bool Board::checkCharacter(char c) {

    if(c=='B' || c == 'E' || c == 'M' || c == 'S' || c == 'R' || c == 'W' || c == 'K')
        return true;
    
    else if(c == 'b' || c == 'e' || c == 'm' || c == 's' || c == 'r' || c == 'w' || c == 'k')
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

    this->p = new Pieces * [row_num];

    for (int i = 0; i < row_num; i++) 
        p[i] = new Pieces[column_num];

    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < column_num; j++) {
            p[i][j] = std.p[i][j];
        }
    }

    this->row_num = std.row_num;
    this->column_num = std.column_num;
    return *this;
}


/*int Board::hit(Pieces** board2, int player, int row) {


    int tempHit = damage_per_hit;

    //to hit the enemy
    for (int i = 2; i >= 0; i--) {
        if (board2[row][i].getCharacter() != ' ' && board2[row][i].getLife() != 0) {//to check if there is an enemy piece in the same row with it
            Pieces Enemy;// if it is not empty then it will hit the pieces
            Enemy = board2[row][i];
            if (tempHit <= Enemy.getLife()) {//to decrease enemy life
                int newLife = Enemy.getLife() - tempHit;
                Enemy.setLife(newLife);
            }
            else {// to decrease the damage per hit and kill enemy
                tempHit = tempHit - Enemy.getLife();
                Enemy.setLife(0);
            }
        }
        else if(i==0) {// if it is empty then it will hit the player
            player = player - tempHit;
        }
        else


    }


    return player;
}*/