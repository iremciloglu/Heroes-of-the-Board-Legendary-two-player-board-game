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

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            p[i][j] = new Pieces(); // Allocate memory for a new Pieces object
        }
    }

}

void Board::showPiece(int x, int y) {

    //if(p[x][y]->getLife()==0)
      //  cout<<"   ";
   // else
    cout<<p[x][y]->getCharacter()<<"("<<p[x][y]->getLife()<<")"<<" ";

}



void Board::printBoard(int i) {

    for(int j=0;j<3;j++) {

        showPiece(i, j);


    }
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

if(p[x][y]->getCharacter()==' ')
    return true;
else
    return false;


}

void Board::addPiece(int x, int y,char c) {

  if(c=='B')
  {
      p[x][y]=new Bowman;
  }
  else if(c=='E')
  {
      p[x][y]=new Elf;
  }
  else if(c=='M')
  {
      p[x][y]=new Mage;
  }
  else if(c=='S')
  {
      p[x][y]=new Spearman;
  }
  else if(c=='R')
  {
      p[x][y]=new Ranger;
  }
  else if(c=='W')
  {
      p[x][y]=new Swordsman;
  }
  else if(c=='K')
  {
      p[x][y]=new Knight;
  }


}


void Board::show_All_Pieces() {

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

    if(c=='B')
    {
        return true;
    }
    else if(c=='E')
    {
        return true;
    }
    else if(c=='M')
    {
        return true;
    }
    else if(c=='S')
    {
        return true;
    }
    else if(c=='R')
    {
        return true;
    }
    else if(c=='W')
    {
        return true;
    }
    else if(c=='K')
    {
        return true;
    }
    else
        return false;


}

int Board::hit(Pieces** board2, int player,int row) {


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
}