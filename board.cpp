// Sam Swanke

#include "board.hpp"
#include <iostream>
using namespace std;

Board::Board() : AbstractBoard() {
    int i;
    for(i=0;i<9;i++){
        board[i] = 0;
    }
}

Board::Board(string s){
    int i;
    for(i=0;i<9;i++){
        int num = s.at(i) - '0';
        board[i] = num;
    }
}

void Board::move(int x, int y, string s){
    int adjY = 2-y;
    int index = 3*adjY+x;
    int i;
    if(s=="x"){
        i=1;
    }else{
        i=2;
    }
    board[index] = i;
}

void Board::set(string s){
    int i;
    for(i=0;i<9;i++){
        int num = s.at(i) - '0';
        board[i] = num;
    }
}

string Board::getState(){
    string s = "";
    int i;
    for(i=0;i<9;i++){
        s.push_back(intToString(board[i]).at(0));
    }
    return s;
}

bool Board::isValid(int x, int y){
    bool valid = board[3*(2-y)+x];
    return !valid;
}

string Board::intToString(int i){
    if(i == 0){
        return " ";
    } else if (i == 1){
        return "x";
    } else {
        return "o";
    }
}

void Board::print(ostream &outs){
    /*
    |x|o|x|
    |o|x|o|
    |o|x|o|
    */
    outs << "|" << intToString(board[0]) << "|" << intToString(board[1]) << "|" << intToString(board[2]) << "|" << endl;
    outs << "|" << intToString(board[3]) << "|" << intToString(board[4]) << "|" << intToString(board[5]) << "|" << endl;
    outs << "|" << intToString(board[6]) << "|" << intToString(board[7]) << "|" << intToString(board[8]) << "|" << endl;
}

ostream& operator << (ostream& outs, Board b){
    b.print(outs);
    return outs;
}
