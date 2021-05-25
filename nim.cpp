#include <iostream>

int game_running = 1;
int player_turn = 0;
int matches = 24;

int print_game_state(int matches_left){
    std::cout << "Here's how many matches are left;" << std::endl;
    for (int i = 0; i < matches_left; ++i) {
        std::cout << "|";
    }

    return 0;
}

int run_turn(int player_number, int matches_left){
    std::cout << "It's player " << player_number << "'s turn now!" << std::endl;

    std::cout << "Please enter a number between 1 and 3" << std::endl;

    int valid_choice = 0;
    int choice = 0;
    std::cin >> choice;

    while(!valid_choice){
        if(std::cin.fail())
            std::cout << "Incorrect entry, please enter a number" << std::endl;

        if(choice >= 0 || choice <= 3){
            if(choice > matches)
                std::cout << "You cannot take more matches than what are left" << std::endl;
            break;
        }

    }

    if(!player_turn) {
        player_turn = !player_turn;
    }
    return choice;
}

int main(){

    std::cout << "Welcome to Nim! The aim of the game is to pick between 1-3 matchsticks" << std::endl;
    std::cout << "you lose by picking the last one." << std::endl;

    while(game_running){
        if(matches <= 0)
            break;
        int matches_to_remove = 0;

        print_game_state(matches);
        matches_to_remove = run_turn(player_turn, matches);

        matches -= matches_to_remove;
    }

    std::cout << "That was fun! Thank you for playing" << std::endl;
    return 0;
}