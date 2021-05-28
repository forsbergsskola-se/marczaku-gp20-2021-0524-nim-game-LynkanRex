//
// Created by Lynkan on 2021-05-28.
//

#include <iostream>
#include <sstream>
#include <array>
#include "tictactoe.h"

using namespace std;

void PrintGameState(char* currentArray);


array<char,9> InitializeGameState(array<char,9> currentArray[]){
    array<char,9> newArray;
    for (int i = 0; i < 9; ++i) {
        newArray[i]= ' ';
    }

    return newArray;
}

void PrintGameState(array<char,9> currentArray){
    int num = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "[ " << currentArray[num] << "]";
            num++;
        }
        cout << endl;
    }
}

bool CheckDiagonals(array<char,9> currentArray, bool playerTurn){
    char symbol;

    if(playerTurn)
        symbol = 'x';
    else
        symbol = 'o';

    if(currentArray[0] == symbol && currentArray[4] == symbol && currentArray[8] == symbol)
    {
        return 1;
    }
    else if(currentArray[2] == symbol && currentArray[4] == symbol && currentArray[6] == symbol){
        return 1;
    }

    return 0;
}

bool CheckColumns(array<char,9> currentArray, bool playerTurn){
    char symbol;

    if(playerTurn)
        symbol = 'x';
    else
        symbol = 'o';


    if(currentArray[0] == symbol && currentArray[3] == symbol && currentArray[6] == symbol)
    {
        return 1;
    }
    else if(currentArray[1] == symbol && currentArray[4] == symbol && currentArray[7] == symbol){
        return 1;
    }
    else if(currentArray[2] == symbol && currentArray[5] == symbol && currentArray[8] == symbol){
        return 1;
    }

    return 0;
}

bool CheckRows(array<char,9> currentArray, bool playerTurn){
    char symbol;

    if(playerTurn)
        symbol = 'x';
    else
        symbol = 'o';

    if(currentArray[0] == symbol && currentArray[1] == 'x' && currentArray[2] == symbol)
    {
        return 1;
    }
    else if(currentArray[3] == symbol && currentArray[4] == symbol && currentArray[5] == symbol){
        return 1;
    }
    else if(currentArray[6] == symbol && currentArray[7] == symbol && currentArray[8] == symbol){
        return 1;
    }

    return 0;
}

bool CheckIfBoardIsFull(array<char,9> currentArray) {
    for (int i = 0; i < 9; ++i) {
        if (currentArray[i] == ' ')
            return 0;
    }
    return 1;
}

bool CheckWinState(array<char,9> currentArray, bool playerTurn){

    bool boardIsFull = CheckIfBoardIsFull(currentArray);
    bool oneRowWins = CheckRows(currentArray, playerTurn);
    bool oneColumnWins = CheckColumns(currentArray, playerTurn);
    bool oneDiagonalWins = CheckDiagonals(currentArray, playerTurn);

    if(boardIsFull || oneRowWins || oneColumnWins || oneDiagonalWins)
        return 1;

    return 0;
}

array<char,9> ComputerDoMove(array<char,9> currentArray){

    // AI Stuff:
    // Could check column state of the array and look for for when 2 X's are nearby,
    // and feed an int back to the choice
    // Same with Row
    // Same with Diagonals..


    cout << "Computer's turn..." << endl;

    for (int i = 0; i < 9; ++i) {
        if(currentArray[i] == ' '){
            currentArray[i] = 'o';
            break;
        }
        else{
            continue;
        }
    }

    return currentArray;
}

array<char,9> DoMove(string input, array<char,9> currentArray){
    int num;
    stringstream ss;

    ss << input;
    ss >> num;

    currentArray[num-1] = 'x';

    return currentArray;
}

bool CellCheck(string input, array<char,9> currentArray){
    int num;
    stringstream ss;

    ss << input;
    ss >> num;

    if(currentArray[num-1] != ' '){
        cout << "You can't re-use the same box! Try another" << endl;
        return 0;
    }


    return 1;
}

int ValidateInput(string input){
    int num;
    stringstream ss;
    ss << input;
    ss >> num;

    if(num <= 0 ||num >= 10) {
        cout << "Wrong number entered, please enter a number between 1-9" << endl;
        return 0;
    }

    return 1;
}

int IsInputNumber(string input){
    if(input.empty()){
        cout << "Input was empty, please enter something" << endl;
        return 0;
    }
    else{
        for (int i = 0; i < input.length(); ++i) {
            if(!isdigit(input[i])){
                if(input[i] == '-')
                    continue;
                cout << "Input given contained something that was not a digit at " << input[i] << endl;
                return 0;
            }
        }
        return 1;
    }
}


void ticTacToe(){
    int gameRunning = 1;
    int playerTurn = 1;
    array<char,9> playField;

    cout << "Tic Tac Toe" << endl;

    playField = InitializeGameState(&playField);
    PrintGameState(playField);

    cout << "Pick a number between 1 and 9, you can always enter 'exit' to quit" << endl;

    while(gameRunning){
        PrintGameState(playField);

        if(playerTurn){
            string input = "";
            cin >> input;

            if(input == "exit"){
                break;
            }

            if(IsInputNumber(input))
                if((ValidateInput(input)))
                    if(CellCheck(input, playField))
                    {
                        playField = DoMove(input, playField);
                        playerTurn = !playerTurn;
                    }
        }
        else{
            playField = ComputerDoMove(playField);
            playerTurn = !playerTurn;
        }

        if(CheckWinState(playField, playerTurn)){
            cout << "The game is over!" << endl;
            PrintGameState(playField);
            gameRunning = 0;
        }
    }
}