#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Board.h"
#include "Pieces.h"
using namespace std;

Pieces** hit(Pieces**, Pieces, int, int);
void Menu(Board board);
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

            cout << "Player " << 1 << "'s turn" << endl;
            cout << " 1     2     3                       3     2     1" << endl;

            for (int i = 0; i < p1_board.getRowNum(); i++) {//For printing the board properly
                p1_board.printBoard(i, 1);//printing one row each time according to player1
                cout << "                  ";
                p2_board.printBoard(i, 2);//printing one row each time according to player2
                cout << endl;

            }


            cout << "Life of p[0][0] is" << p1_board.getPieces()[0][0].getLife();
            cout << "                         Ranged Pieces\n";
            cout << "           Life      Damage     Char      Number that can be used " << endl;
            cout << "Bowman      12        3         B        Infinite" << endl;
            cout << "Elf         8         6         E        " << p1_board.getElfCount() << endl;
            cout << "Mage        4         8         M        " << p1_board.getMageCount() << endl;
            cout << "                         Meele Pieces\n";
            cout << "           Life     Damage     Char      Number that can be used" << endl;
            cout << "Spearman    6         3         S         Infinite" << endl;
            cout << "Ranger      8         6         R         " << p1_board.getRangerCount() << endl;
            cout << "Swordsman   6         4         W         Infinite" << endl;
            cout << "Knight      10        10        K        " << p1_board.getKnightCount() << endl;
            cout << "Life of p[0][0] is" << p1_board.getPieces()[0][0].getLife();
            do {//to check if char input is valid
                cout << "Select the character you want:";
                cin >> character_char;
                if (p1_board.checkCharacter(character_char) == 1)
                    break;
                cout << "No such character exists!!\n";
            } while (p1_board.checkCharacter(character_char) != 1);
            cout << "Life of p[0][0] is" << p1_board.getPieces()[0][0].getLife();
            do {
                cout << "Please select a coordinate on the board to put your piece:(Ex:A1-C3)";
                fflush(stdin);
                cin >> coordinate_char >> coordinate_num;
                int row;
                //to check if coordinat e input is valid

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
                    cout << "Life of p[0][0] is" << p1_board.getPieces()[0][0].getLife();
                    if (p1_board.isEmptyCoordinate(row, coordinate_num - 1)) {// to check if entered coordinate is empty or not
                        p1_board.addPiece(row, coordinate_num - 1, character_char);
                        break;
                    }
                    else
                        cout << "The coordinates given has already has a piece!" << endl;
                    p1_board.addPiece(row, coordinate_num - 1, character_char);

                }
                cout << "Please write a proper coordinate!\n";
            } while (1);// here the placement of the character is done

            for (int i = 0; i < p1_board.getRowNum(); i++) {// trying to implement hit
                for (int j = 0; j < p1_board.getColumnNum(); j++) {
                    cout << "check3";


                    int tempHit = p1_board.getPieces()[i][j].getDamagePerHit();

                    for (int k = 2; k >= 0; k--) {// it enters the loop 3 times with the same coordinate i guess, idk why!!!!
                        if (p2_board.getPieces()[i][k].getCharacter() != ' ' || p2_board.getPieces()[i][k].getLife() != 0) {
                            cout << "Check: r:  " << i << "   c:" << i << endl;
                            if (tempHit <= p2_board.getPieces()[i][k].getLife()) {
                                int newLife = p2_board.getPieces()[i][k].getLife() - tempHit;
                                p2_board.getPieces()[i][k].setLife(newLife);
                            }
                            else {
                                tempHit = tempHit - p2_board.getPieces()[i][k].getLife();
                                p2_board.getPieces()[i][k + 1].setCharacter(' '); //This means its dead
                                p2_board.getPieces()[i][k + 1].setLife(0);
                            }
                        }
                        else if (i == 0) {
                            player2 = player2 - tempHit;
                        }
                    }




                }
            }
        }

        if (turn % 2 == 1) {//Player twos turn

            cout << "Player " << 2 << "'s turn" << endl;
            cout << " 1     2     3                       3     2     1" << endl;

            for (int i = 0; i < p1_board.getRowNum(); i++) {//For printing the board properly
                p1_board.printBoard(i, 1);//printing one row each time according to player1
                cout << "                  ";
                p2_board.printBoard(i, 2);//printing one row each time according to player2
                cout << endl;

            }
            cout << "                         Ranged Pieces\n";
            cout << "           Life      Damage     Char      Number that can be used " << endl;
            cout << "Bowman      12        3         B        Infinite" << endl;
            cout << "Elf         8         6         E        " << p2_board.getElfCount() << endl;
            cout << "Mage        4         8         M        " << p2_board.getMageCount() << endl;
            cout << "                         Meele Pieces\n";
            cout << "           Life     Damage     Char      Number that can be used" << endl;
            cout << "Spearman    6         3         S         Infinite" << endl;
            cout << "Ranger      8         6         R         " << p2_board.getRangerCount() << endl;
            cout << "Swordsman   6         4         W         Infinite" << endl;
            cout << "Knight      10        10        K        " << p2_board.getKnightCount() << endl;

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

            for (int i = 0; i < p1_board.getRowNum(); i++) {// trying to implement hit
                for (int j = 0; j < p1_board.getColumnNum(); j++) {
                    cout << "check3";


                    int tempHit = p1_board.getPieces()[i][j].getDamagePerHit();

                    for (int k = 2; k >= 0; k--) {// it enters the loop 3 times with the same coordinate i guess, idk why!!!!
                        if (p2_board.getPieces()[i][k].getCharacter() != ' ' || p2_board.getPieces()[i][k].getLife() != 0) {
                            cout << "Check: r:  " << i << "   c:" << i << endl;
                            if (tempHit <= p2_board.getPieces()[i][k].getLife()) {
                                int newLife = p2_board.getPieces()[i][k].getLife() - tempHit;
                                p2_board.getPieces()[i][k].setLife(newLife);
                            }
                            else {
                                tempHit = tempHit - p2_board.getPieces()[i][k].getLife();
                                p2_board.getPieces()[i][k + 1].setCharacter(' '); //This means its dead
                                p2_board.getPieces()[i][k + 1].setLife(0);
                            }
                        }
                        else if (i == 0) {
                            player2 = player2 - tempHit;
                        }
                    }




                }
            }
            //Ataklar olucak
        }
        turn++;
    }
    return 0;
}

/*void print2Boards(Board p1_board, Board p2_board, int player) {

    cout << "Player " << player << "'s turn" << endl;
    cout << " 1     2     3                       3     2     1" << endl;

    for (int i = 0; i < p1_board.getRowNum(); i++) {//For printing the board properly
        p1_board.printBoard(i, 1);//printing one row each time according to player1
        cout << "                  ";
        p2_board.printBoard(i, 2);//printing one row each time according to player2
        cout << endl;

    }

}*/

/*void Menu(Board board) { // Player?n turuna göre boardu input olarak at?p ELF-MAGE-RANGER-KNIGHT say?lar?n? boarda atmak ?

    cout << "                         Ranged Pieces\n";
    cout << "           Life      Damage     Char      Number that can be used " << endl;
    cout << "Bowman      12        3         B        Infinite" << endl;
    cout << "Elf         8         6         E        "<<board.getElfCount() << endl;
    cout << "Mage        4         8         M        "<<board.getMageCount() << endl;
    cout << "                         Meele Pieces\n";
    cout << "           Life     Damage     Char      Number that can be used" << endl;
    cout << "Spearman    6         3         S         Infinite" << endl;
    cout << "Ranger      8         6         R         "<<board.getRangerCount() << endl;
    cout << "Swordsman   6         4         W         Infinite" << endl;
    cout << "Knight      10        10        K        "<<board.getKnightCount() << endl;

}*/

/ Pieces * hit(Pieces * *enemy_board, Pieces myPiece, int enemy_player, int row) {
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
                enemy_board[row][i + 1].setCharacter(' '); //This means its dead
                enemy_board[row][i + 1].setLife(0);
            }
        }
        else if (i == 0) {
            enemy_player = enemy_player - tempHit;
        }
    }

    return enemy_board;
} */