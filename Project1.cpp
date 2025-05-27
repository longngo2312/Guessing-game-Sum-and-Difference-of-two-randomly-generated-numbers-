/*Project 1: Guessing game (Sum and Difference of two randomly generated numbers)*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    //Project detail
    cout << "Computer Science and Engineering" << endl;
    cout << "CSCE 1030 - Computer Science I" << endl;
    cout << "Jack Ngo ltn0108 LongNgo2@my.unt.edu" << endl;
    // player total game point
    int game_point = 100;
    //game options enumeration
    enum menu{ADD = 1, SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};


    //User name checking 
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    //general checking loop
    while (true) {
        bool flag = true;
        // looping through the characters in the name
        for (int i = 0; i < name.size(); i++){
            // if your name isn't alphabet or space it is invalid 
            if (!isalpha(name[i]) && !isspace(name[i])){
                cout << "Your name can only have alphabets or spaces. Enter again." << endl;
                flag = false;
                break; // break the for loop 
            }
        }
        if (flag == true){
            for (int j = 0; j < name.size(); j++){ //first initial always capitalized
                if (j==0){
                    name[j] = toupper(name[j]);
                }
                else if ((j > 0) &&(isspace(name[j-1]))){ //second initial
                    name[j] = toupper(name[j]);
                }
            }
            cout << "Welcome, " << name << "!" << endl;
            break;
        }
        else {
            cout << "Enter your name: ";
            getline(cin, name);
        
        }
    }
    //random numbers generator
    srand(time(0));
    int randNum1, randNum2;
    bool checking = true;
    randNum1 = rand() % (150-100+1) + 100; 
    randNum2 = rand() % (150-100+1) + 100;
    while (checking == true){ //checking if the first random integer is less than the second
       
        if (randNum1 >= randNum2){
            randNum1 = rand() % (150-100+1) + 100;
            randNum2 = rand() % (150-100+1) + 100;
        }
        else {
            checking = false;
            
        }
    }
    cout << "Your two random numbers have been generated." << endl;
    
    //menu options | game loop 
    bool first_number = true;
    bool gamecmd = true; 
    int user_choice;
    int difference;
    char choice;
    while (gamecmd == true){
        cout << "1. ADD" << endl;
        cout << "2. SUBTRACT" << endl;
        cout << "3. DISPLAY" << endl;
        cout << "4. GIVEUP" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;
        user_choice = static_cast<menu>(user_choice);

        switch(user_choice){
            case ADD: {
                int sumGuess;
                int sum;
                sum = randNum1 + randNum2;
                cout << "Guess the sum of the two random numbers: "; 
                cin >> sumGuess;
                difference = abs(sumGuess - sum);
                if (difference < 5){
                    cout << "Correct guess!" << endl;
                    game_point += 5;
                    cout << "Your updated game points are " << game_point << endl;
                }
                else {
                    cout << "Wrong guess!" << endl;
                    game_point -= 1;
                    cout << "Your updated game points are: " << game_point << endl;
                }
                cout << "Do you want to play again? (y/n)"; 
                cin >> choice; 
                choice = toupper(choice);
                if (choice == 'Y'){
                    randNum1 = rand() % (150-100+1) + 100; 
                    randNum2 = rand() % (150-100+1) + 100;
                }
                else {
                    cout << "Thank you for playing the game! " << name << endl;
                    cout << "Final points are " << game_point << endl;
                    gamecmd = false;
                }
                break;
            }
            case SUBTRACT: {
                int subGuess;
                int subtraction = randNum2 - randNum1;
                cout << "Guess the difference between the two random numbers: ";
                cin >> subGuess;
                difference = abs(subGuess -subtraction);
                if (difference < 5){
                    cout << "Correct guess!" << endl;
                    game_point += 5;
                    cout << "Your updated game points are " << game_point << endl;
                }
                else {
                    cout << "Wrong guess!" << endl;
                    game_point -= 1;
                    cout << "Your updated game points are: " << game_point << endl; 
                }
                cout << "Do you want to play again? (y/n)"; 
                cin >> choice; 
                choice = toupper(choice);
                if (choice == 'Y'){
                    randNum1 = rand() % (150-100+1) + 100; 
                    randNum2 = rand() % (150-100+1) + 100;
                }
                else {
                    cout << "Thank you for playing the game! " << name << endl;
                    cout << "Final points are " << game_point << endl;
                    gamecmd = false;
                }
                break;
            }
            case DISPLAY: {
                if (first_number == true){
                    game_point -=3;
                    cout << "Current game_point is " << game_point << endl;
                    cout << "The first random number is " << randNum1 << endl;
                    first_number = false;
                }
                else {
                    cout << "You can only display the first random number." << endl;
                }
                break;
            }
            case GIVEUP: {
                cout << "First random number is: " << randNum1 << endl;
                cout << "Second random number is: " << randNum2 << endl;
                cout << "Do you want to play again? (y/n)";
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y'){
                    randNum1 = rand() % (150-100+1) + 100; 
                    randNum2 = rand() % (150-100+1) + 100;
                }
                else {
                    cout << "Thank you for playing the game! " << name << endl;
                    cout << "Final points are " << game_point << endl;
                    gamecmd = false;
                }
                break;
            }
            case EXIT: {
                cout << "Thank you for playing the game! " << name << endl;
                cout << "Your final points are: " << game_point << endl;
                gamecmd = false;
                break;
            }
            default: {
                cout << "Invalid choice. Enter again." << endl;
                break;
            }
        } 
    }
    return 0;
}
