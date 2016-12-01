// Sam Swanke

#include "game.hpp"
#include <iostream>
using namespace std;

Game::Game(){
    Board board;
}

int Game::isOver(){
    string state = board.getState();
    string row1 = state.substr(0,3);
    string row2 = state.substr(3,3);
    string row3 = state.substr(6,3);
    int i;
    for(i=0;i<3;i++){
        if(row1[i]==row2[i] && row1[i]==row3[i]&& row1[i]!=' '){
            if(row1[i] == 'x'){
                return 1;
            } else {
                return 2;
            }
        }
    }
    if(row1[0]==row1[1] && row1[0]==row1[2]&& row1[0]!=' '){
        if(row1[0] == 'x'){
            return 1;
        } else {
            return 2;
        }
    }
    if(row2[0]==row2[1] && row2[0]==row2[2]&& row2[0]!=' '){
        if(row2[0] == 'x'){
            return 1;
        } else {
            return 2;
        }
    }
    if(row3[0]==row3[1] && row3[0]==row3[2]&& row3[0]!=' '){
        if(row3[0] == 'x'){
            return 1;
        } else {
            return 2;
        }
    }
    if((row1[0]==row2[1] && row1[0]==row3[2]&& row1[0]!=' ') ||
       (row3[0]==row2[1] && row3[0]==row1[2]&& row3[0]!=' ')){
        if(row2[1] == 'x'){
            return 1;
        } else {
            return 2;
        }
    }
    bool isFull = true;
    int j;
    for(j=0;j<9;j++){
        if(state.at(i)==' '){
            isFull = false;
        }
    }
    if(isFull){
        return 3;
    }
    return 0;
    
}

void Game::turn(string s){
    cout << board << endl;
    printf("Place an %s, in the form \"xy\": ", s.c_str());
    string input;
    getline(cin, input);
    int x = input.at(0) - '0';
    int y = input.at(1) - '0';
    if(x<0 || x>2){
        printf("x must be between 0 and 2.\n");
        turn(s);
        return;
    }
    if(y<0 || y>2){
        printf("y must be between 0 and 2.\n");
        turn(s);
        return;
    }
    if(!board.isValid(x,y)){
        printf("That place is already taken!\n");
        turn(s);
        return;
    }
    board.move(x, y, s);
}

void Game::end(int i){
    cout << board << endl;
    if(i == 1){
        printf("Congrats x's win!\n");
    } else if (i==2){
        printf("Congrats o's win!\n");
    }else{
        printf("Its a tie!\n");
    }
    exit(0);
}

void Game::start(){
    int i = 0;
    while(!isOver()){
        if(i % 2 == 0){
            turn("x");
        } else {
            turn("o");
        }
        i++;
    }
    end(isOver());
}
