#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "Board.h"
#include "Pieces.h"
int hit(Pieces** board2, int player,int row);
int main() {
    cout << "Heroes of the Board: Legendary two-player board game!!" << endl;
    int player1 = 100, player2 = 100, turn, coordinate_num;
    char coordinate_char, character_char;
    Board p1_board, p2_board;
    srand(time(0));
    if (rand() % 2 == 0) {
        cout << "Player 1 starts" << endl;
        turn = 0;
    }          //Turn%2==0 is always player 1's turn
    else {
        cout << "Player 2 starts" << endl;
        turn = 1;
    }         //Turn%2==1 is always player 2's turn

    while (1) { //Main loop works until program finished
        if (turn % 2 == 0) //Player ones turn
        {
            cout << "Player 1's turn" << endl;
            cout << " 1     2     3                       3     2     1" << endl;
            for (int i = 0; i < 4; i++) //For printing the board properly
            {
                p1_board.printBoard(i);
                cout << "                  ";
                p2_board.printBoard(i);
                cout << endl;
            }


            p1_board.show_All_Pieces();


            do {
                cout << "Select the character you want:";
                cin >> character_char;
                if (p1_board.checkCharacter(character_char) == 1)
                    break;
                else
                    cout << "No such character exists!!\n";

            } while (1);


            do {
                cout << "Please select a coordinate on the board to put your piece:(Ex:A1-C3)";
                cin >> coordinate_char >> coordinate_num;
                if (coordinate_char == 'A' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p1_board.isEmptyCoordinate(0, coordinate_num - 1)) {

                        p1_board.addPiece(0, coordinate_num - 1, character_char);
                        break;

                    } else
                        cout << "The coordinates given has already has a piece!" << endl;


                } else if (coordinate_char == 'B' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p1_board.isEmptyCoordinate(1, coordinate_num - 1)) {
                        p1_board.addPiece(1, coordinate_num - 1, character_char);;
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else if (coordinate_char == 'C' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p1_board.isEmptyCoordinate(2, coordinate_num - 1)) {
                        p1_board.addPiece(2, coordinate_num - 1, character_char);
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else if (coordinate_char == 'D' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p1_board.isEmptyCoordinate(3, coordinate_num - 1)) {
                        p1_board.addPiece(3, coordinate_num - 1, character_char);
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else
                    cout << "Please write a proper coordinate!\n";
            } while (1);

            for (int i = 0; i < 4; i++) {

                player2=hit(p2_board.getPieceInfo(),player2,i);


                }


        }

        if (turn % 2 == 1) //Player twos turn
        {
            cout << "Player 2's turn" << endl;
            cout << " 1     2     3                       3     2     1" << endl;
            for (int i = 0; i < 4; i++) //For printing the board properly
            {
                p1_board.printBoard(i);
                cout << "                  ";
                p2_board.printBoard(i);
                cout << endl;
            }


            p2_board.show_All_Pieces();


            do {
                cout << "Select the character you want:";
                cin >> character_char;
                if (p2_board.checkCharacter(character_char) == 1)
                    break;
                else
                    cout << "No such character exists!!\n";

            } while (1);


            do {
                cout << "Please select a coordinate on the board to put your piece:(Ex:A1-C3)";
                cin >> coordinate_char >> coordinate_num;
                if (coordinate_char == 'A' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p2_board.isEmptyCoordinate(0, coordinate_num - 1)) {

                        p2_board.addPiece(0, coordinate_num - 1, character_char);
                        break;

                    } else
                        cout << "The coordinates given has already has a piece!" << endl;


                } else if (coordinate_char == 'B' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p2_board.isEmptyCoordinate(1, coordinate_num - 1)) {
                        p2_board.addPiece(1, coordinate_num - 1, character_char);;
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else if (coordinate_char == 'C' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p2_board.isEmptyCoordinate(2, coordinate_num - 1)) {
                        p2_board.addPiece(2, coordinate_num - 1, character_char);
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else if (coordinate_char == 'D' && coordinate_num > 0 && coordinate_num < 4) {
                    if (p2_board.isEmptyCoordinate(3, coordinate_num - 1)) {
                        p2_board.addPiece(3, coordinate_num - 1, character_char);
                        break;
                    } else
                        cout << "The coordinates given has already has a piece!" << endl;
                } else
                    cout << "Please write a proper coordinate!\n";
            } while (1);

           //Ataklar olucak
        }


      turn++;
    }


}

int hit(Pieces** board2, int player,int row)
{
    int tempHit = 1;

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
            continue;

    }


    return player;

}