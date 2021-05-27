#include <iostream>
#include <sstream>
using namespace std;

int game_running = 1;
int player_turn = 0;
int matches = 24;

int print_game_state(int matches_left){
    for (int i = 0; i < matches_left; ++i) {
        cout << "|";
    }
    cout << endl;
    cout << "There's currently " << matches << " matches left." << endl;
    return 0;
}

int validate_input(string input){

    cout << "Input is: " << input << endl;

    if(input == "1" || input == "2" || input == "3"){
        return 1;
    }

    return 0;
}

int run_turn(int player_number, int matches_left){
    string choice_string = "";
    int choice = 0;


    if(!player_number){
        std::cout << "It's your turn now!" << std::endl;

        int player_entry = 0;

        while(!player_entry){
            cout << "Please enter a number between 1 and 3" << endl;
            cin >> choice;

            stringstream ss;
            ss<<choice;
            string s;
            ss>>s;

            if(validate_input(s))
            {
                if(choice >= 1 && choice <= 3){
                    if(choice > matches)
                        cout << "You cannot take more matches than what are left" << endl;
                    player_entry = 1;
                }
            }
            else{
                cout << "Incorrect entry, please enter a number" << endl;
            }
        }
    }
    else{
        cout << "It's the AI's turn now" << endl;

        if(matches_left <= 1){
            choice = 1;
        }
        else if(matches_left == 2){
            choice = 1;
        }
        else if(matches_left == 3){
            choice = 2;
        }
        else{
            choice = rand() % 2+1;
        }

        cout << "The AI picked " << choice << " match(es)!" << endl;
    }

    player_turn = !player_turn;
    return choice;
}

int decide_who_won(){
    if(!player_turn)
        cout << "You won!" << endl;
    else
        cout << "You lost!" << endl;

    return 0;
}

int mainn(){

    cout << "Welcome to Nim! The aim of the game is to pick between 1-3 matchsticks" << endl;
    cout << "you lose by picking the last one." << endl;

    while(game_running){
        if(matches <= 0)
            break;
        int matches_to_remove = 0;

        print_game_state(matches);
        matches_to_remove = run_turn(player_turn, matches);

        matches -= matches_to_remove;
    }

    decide_who_won();

    cout << "That was fun! Thank you for playing" << endl;
    cout << "Enter any character and press RETURN to quit" << endl;
    char choice;
    cin >> choice;
    return 0;
}