#include <iostream>
#include <sstream>

using namespace std;

bool loop_active;

void convertNumber(string input){
    int num;
    int a[10];
    int i;
    stringstream ss;
    ss << input;
    ss >> num;

    if(num == 0){
        cout << "Your number is 0b0" << endl;
    }
    else{
        for (i = 0; num > 0; i++) {
            a[i]= num % 2;
            num = num / 2;
        }

        cout << "Your number is 0b";
        for (i = i-1; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
    }
}

int verify_inputIsNotTooBig(string input){
    int num;
    stringstream ss;
    ss << input;
    ss >> num;

    if(num >= 256) {
        cout << "Number is too large, please enter a number between 0-255" << endl;
        return 0;
    }

    return 1;
}

int verify_inputIsPositive(string input){
    if(input[0] == '-'){
        cout << "Entered number is negative, please enter a positive value" << endl;
        return 0;
    }

    return 1;
}

int verify_inputIsDigit(string input){
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

int verify_inputExit(string input) {
    if(input != "exit")
        return 0;
    return 1;
}

void do_loop(){
            cout << "Please enter a decimal number between 0 and 255, enter 'exit' to quit" << endl;
            string choice = "";

            cin >> choice;

            if(verify_inputExit(choice)){
                loop_active = 0;
                return;
            }

            if(verify_inputIsDigit(choice))
                if(verify_inputIsPositive(choice))
                   if(verify_inputIsNotTooBig(choice)){
                       convertNumber(choice);
                   }
}


int main(){
    loop_active = 1;

    cout << "Decimal- to Binary-number converter" << endl;

    while(loop_active){
        do_loop();
    }

    cout << "Exiting..." << endl;
    return 0;
}