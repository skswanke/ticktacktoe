// Sam Swanke

#include "gameService.hpp"
using namespace std;

int GameService::isOver(){
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
        if(state.at(j)==' '){
            isFull = false;
        }
    }
    if(isFull){
        return 3;
    }
    return 0;
    
}

void GameService::end(int i){
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
