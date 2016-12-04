// Sam Swanke

#include "game.hpp"
#include <iostream>
using namespace std;

Game::Game(){
    Board board;
}

void Game::turn(int x, int y, bool player){
    // cout << board << endl;
    // printf("Place an %s, in the form \"xy\": ", s.c_str());
    // string input;
    // getline(cin, input);
    // if(input.at(0)=='s'){
    //     fileService.save(board.getState());
    //     return;
    // }
    // if(input.at(0)=='l'){
    //     board.set(fileService.load());
    //     return;
    // }
    // int x = input.at(0) - '0';
    // int y = input.at(1) - '0';
    // if(x<0 || x>2){
    //     printf("x must be between 0 and 2.\n");
    //     turn(s);
    //     return;
    // }
    // if(y<0 || y>2){
    //     printf("y must be between 0 and 2.\n");
    //     turn(s);
    //     return;
    // }
    // if(!board.isValid(x,y)){
    //     printf("That place is already taken!\n");
    //     turn(x,y,player);
    //     return;
    // }
    if(player){
        board.move(x, y, "x");
    } else {
        board.move(x, y, "0");
    }
    
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
    printf("Press s to save and l to load.\n");
    int i = 0;
    while(!gameService.isOver(board.getState())){
        if(i % 2 == 0){
            // turn("x");
        } else {
            // turn("o");
        }
        i++;
    }
    end(gameService.isOver(board.getState()));
}
