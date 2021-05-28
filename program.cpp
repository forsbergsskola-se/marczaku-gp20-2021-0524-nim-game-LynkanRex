//
// Created by Lynkan on 2021-05-28.
//

#include "program.h"
#include <iostream>

#include "binaryconverter.h"
#include "nim.h"

using namespace std;

int main(){
    int programRunning = 1;
    int choice = 0;

    cout << "Enter a number; " << endl;
    cout << "1. Nim" << endl;
    cout << "2. Tic Tac Toe" << endl;
    cout << "3. Binary Converter" << endl;

    cin >> choice;

    while(programRunning){
        if(choice == 1){
            nimGame();
        }
        if(choice == 2){

        }
        if(choice == 3){
            binaryConverter();
        }
        else{
            break;
        }
    }

    return 0;
}