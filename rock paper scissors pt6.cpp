// rock paper scissors pt6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//create a new branch that uses a file to store the results of each new session along
//with previous sessions.
//When starting you should provide a menu that
//that lets the user start a new session, display previous sessions for yourself of any others.
//Name: Yochanan Allen 

#include <iostream>
#include <string>
#include <fstream>   
#include <cstdlib>   
#include <ctime>     

using namespace std;


int getComputerChoice() {
    return (rand() % 3 + 1);  
}


string choiceToString(int choice) {
    if (choice == 1) return "rock";
    else if (choice == 2) return "paper";
    else return "scissors";
}


string getUserChoice() {
    string userChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors), or type 'exit' to quit: ";
        cin >> userChoice;
        if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors" || userChoice == "exit") {
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'rock', 'paper', 'scissors', or 'exit'." << endl;
        }
    }
    return userChoice;
}


string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "tie";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "user";
    }
    else {
        return "computer";
    }
}


void playGame(string playerName) {
    int userWins = 0;
    int computerWins = 0;
    int ties = 0;

    
    ofstream sessionFile("session_results.txt", ios::app);

   
    sessionFile << "Session started for player: " << playerName << " at " << time(0) << endl;

    while (true) {
        int computerChoiceNum = getComputerChoice();
        string computerChoice = choiceToString(computerChoiceNum);

        string userChoice = getUserChoice();

        if (userChoice == "exit") {
            break;
        }

        cout << "Computer chose " << computerChoice << "." << endl;
        cout << playerName << " chose " << userChoice << "." << endl << endl;

        string winner = determineWinner(userChoice, computerChoice);

        if (winner == "tie") {
            cout << "It's a tie!" << endl;
            ties++;
        }
        else if (winner == "user") {
            cout << playerName << " wins!" << endl;
            userWins++;
        }
        else {
            cout << "Computer wins!" << endl;
            computerWins++;
        }

        cout << "Current Score:" << endl;
        cout << playerName << " Wins: " << userWins << endl;
        cout << "Computer Wins: " << computerWins << endl;
        cout << "Ties: " << ties << endl << endl;
    }

    
    sessionFile << "Game Over!" << endl;
    sessionFile << "Final Score:" << endl;
    sessionFile << playerName << " Wins: " << userWins << endl;
    sessionFile << "Computer Wins: " << computerWins << endl;
    sessionFile << "Ties: " << ties << endl;
    sessionFile.close();

    cout << "Game Over!" << endl;
    cout << "Final Score:" << endl;
    cout << playerName << " Wins: " << userWins << endl;
    cout << "Computer Wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl;
}


void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Start a new session" << endl;
    cout << "2. View previous sessions" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
}


void displayPreviousSessions() {
    ifstream sessionFile("session_results.txt");

    if (!sessionFile) {
        cout << "No previous sessions found." << endl;
        return;
    }

    string line;
    while (getline(sessionFile, line)) {
        cout << line << endl;
    }

    sessionFile.close();
}

int main() {
    srand(time(0));  

    string playerName;
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Please enter your name: ";
    cin >> playerName;

    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            playGame(playerName);
        }
        else if (choice == 2) {
            displayPreviousSessions();
        }
        else if (choice == 3) {
            cout << "Thanks for playing! Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file