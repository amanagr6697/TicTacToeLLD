#ifndef PLAYER_H

#define PLAYER_H

#include<iostream>

class Player{
    private:
    int player;

    public:
    int getPlayer(){
        return player;
    }

    void setPlayer(int value){
        player = value;
    }
};

#endif