/* Irem Ciloglu 2385292
I read and accept the submission rules and the important section
specified in assignment file.This is my own work that is done by myself
and my team - mate only */
#include<iostream>
#include "Bowman.h"

Bowman::Bowman() : Ranged() {
    this->life = 12;
    this->character = 'B';
    this->damage_per_hit = 3;
}
Bowman::Bowman(int life, char ch, int damage, char row, int column) : Ranged(life, ch, column, row) {
    this->damage_per_hit = damage;
}
void Bowman::setDamagePerHit(int damage) {
    this->damage_per_hit = damage;
}
int Bowman::getDamagePerHit() {
    return this->damage_per_hit;
}
int Bowman::hit(Pieces** board2, int player) {

    int row = this->getRow();
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
        else {// if it is empty then it will hit the player
            player = player - tempHit;
        }

    }


    return player;
}
