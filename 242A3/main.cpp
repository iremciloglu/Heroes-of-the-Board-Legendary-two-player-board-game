#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Board.h"
#include "Pieces.h"
using namespace std;

Pieces** hit(Pieces**, Pieces, int, int);
void Menu();
void print2Boards(Board, Board, int);

int main() {
    cout << "Heroes of the Board: Legendary two-player board game!!" << endl;
    int player1 = 10, player2 = 10, turn, coordinate_num;
    char coordinate_char, character_char;
    Board p1_board = Board();
    Board p2_board = Board();
    
    srand(time(0));

    if (rand() % 2 == 0) {
        cout << "Player 1 starts" << endl;
        turn = 0;
    } //Turn%2==0 is always player 1's turn
    else {
        cout << "Player 2 starts" << endl;
        turn = 1;
    }//Turn%2==1 is always player 2's turn

    while (1) {//Main loop works until program finished

        if (turn % 2 == 0) {//Player ones turn

            print2Boards(p1_board, p2_board, 1);
            Menu();

            do {//to check if char input is valid
                cout << "Select the character you want:";
                cin >> character_char;
                if (p1_board.checkCharacter(character_char) == 1)
                    break;
                cout << "No such character exists!!\n";
            } while (p1_board.checkCharacter(character_char) != 1);

            do {
                cout << "Please select a coordinate on the board to put your piece:(Ex:A1-C3)";
                cin >> coordinate_char >> coordinate_num;
                int row;
                //to check if coordinate input is valid

                if (coordinate_num > 0 && coordinate_num < p1_board.getColumnNum() + 1 &&
                    (coordinate_char == 'A' || coordinate_char == 'a' || coordinate_char == 'B' || coordinate_char == 'b'
                        || coordinate_char == 'C' || coordinate_char == 'c' || coordinate_char == 'D' || coordinate_char == 'd')) {

                    if (coordinate_char == 'A' || coordinate_char == 'a')// to convert row char to int
                        row = 0;
                    else if (coordinate_char == 'B' || coordinate_char == 'b')
                        row = 1;
                    else if (coordinate_char == 'C' || coordinate_char == 'c')
                        row = 2;
                    else
                        row = 3;
                      
                       if (p1_board.isEmptyCoordinate(row, coordinate_num - 1)) {// to check if entered coordinate is empty or not
                            p1_board.addPiece(row, coordinate_num - 1, character_char);
                            break;
                        }
                        else
                            cout << "The coordinates given has already has a piece!" << endl;
                        p1_board.addPiece(row, coordinate_num - 1, character_char);

                }
                cout << "Please write a proper coordinate!\n";
            } while (1);

            for (int i = 0; i < p1_board.getRowNum(); i++) {// trying to implement hit
                for (int j = 0; j < p1_board.getColumnNum(); j++) {
                    cout << "check3";
                    p2_board.setPieces(hit(p2_board.getPieces(), p1_board.getPieces()[i][j], player2, i));
                }
            }
        }

        if (turn % 2 == 1) {//Player twos turn

            print2Boards(p1_board, p2_board, 2);
            Menu();

            do {//to check if char input is valid
                cout << "Select the character you want:";
                cin >> character_char;
                if (p2_board.checkCharacter(character_char) == 1)
                    break;
                cout << "No such character exists!!\n";
            } while (p2_board.checkCharacter(character_char) != 1);

            do {
                cout << "Please select a coordinate on the board to put your piece:(Ex:A1-C3)";
                cin >> coordinate_char >> coordinate_num;
                int row;
                //to check if coordinate input is valid
                if (coordinate_num > 0 && coordinate_num < p2_board.getColumnNum() + 1 &&
                    (coordinate_char == 'A' || coordinate_char == 'a' || coordinate_char == 'B' || coordinate_char == 'b'
                        || coordinate_char == 'C' || coordinate_char == 'c' || coordinate_char == 'D' || coordinate_char == 'd')) {

                    if (coordinate_char == 'A' || coordinate_char == 'a')// to convert row char to int
                        row = 0;
                    else if (coordinate_char == 'B' || coordinate_char == 'b')
                        row = 1;
                    else if (coordinate_char == 'C' || coordinate_char == 'c')
                        row = 2;
                    else
                        row = 3;

                   if (p2_board.isEmptyCoordinate(row, coordinate_num - 1)) {// to check if entered coordinate is empty or not
                        p2_board.addPiece(row, coordinate_num - 1, character_char);
                        break;
                    }
                    else
                        cout << "The coordinates given has already has a piece!" << endl;
                    p2_board.addPiece(row, coordinate_num - 1, character_char);
                }
                cout << "Please write a proper coordinate!\n";
            } while (1);

            for (int i = 0; i < p2_board.getRowNum(); i++) {// trying to implement hit
                for (int j = 0; j < p2_board.getColumnNum(); j++) {
                    cout << "check3";
                    p1_board.setPieces(hit(p1_board.getPieces(), p2_board.getPieces()[i][j], player1, i));
                }
            }
            //Ataklar olucak
        }
        turn++;
    }
    return 0;
}

void print2Boards(Board p1_board, Board p2_board, int player) {

    cout << "Player " << player << "'s turn" << endl;
    cout << " 1     2     3                       3     2     1" << endl;

    for (int i = 0; i < p1_board.getRowNum(); i++) {//For printing the board properly
        p1_board.printBoard(i, 1);//printing one row each time according to player1
        cout << "                  ";
        p2_board.printBoard(i, 2);//printing one row each time according to player2
        cout << endl;
    }
}

void Menu() {

    cout << "                         Ranged Pieces\n";
    cout << "           Life      Damage     Char      Number that can be used " << endl;
    cout << "Bowman      12        3         B        Infinite" << endl;
    cout << "Elf         8         6         E        3 " << endl;
    cout << "Mage        4         8         M        2" << endl;
    cout << "                         Meele Pieces\n";
    cout << "           Life     Damage     Char      Number that can be used" << endl;
    cout << "Sperman     6         3         S         Infinite" << endl;
    cout << "Ranger      8         6         R         2 " << endl;
    cout << "Swordsman   6         4         W         Infinite" << endl;
    cout << "Knight      10        10        K         1" << endl;

}

Pieces** hit(Pieces** enemy_board, Pieces myPiece, int enemy_player, int row) {
    int tempHit = myPiece.getDamagePerHit();

    for (int i = 2; i >= 0; i--) {// it enters the loop 3 times with the same coordinate i guess, idk why!!!!
        if (enemy_board[row][i].getCharacter() != ' ' || enemy_board[row][i].getLife() != 0) {
            cout << "Check: r:  " << row << "   c:" << i << endl;
            if (tempHit <= enemy_board[row][i].getLife()) {
                int newLife = enemy_board[row][i].getLife() - tempHit;
                enemy_board[row][i].setLife(newLife);
            }
            else {
                tempHit = tempHit - enemy_board[row][i].getLife();
                enemy_board[row][i + 1].setCharacter(' ');
                enemy_board[row][i + 1].setLife(0);
            }
        }
        else if (i == 0) {
            enemy_player = enemy_player - tempHit;
        }
    }

    return enemy_board;
}
