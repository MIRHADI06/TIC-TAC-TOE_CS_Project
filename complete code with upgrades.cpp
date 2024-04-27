#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

char board[3][3];
char currentPlayer;
char sign;
int gameMode; // 1 for player vs player, 2 for player vs computer

void initializeBoard() {
    // Initialize the board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    // Set initial player
    currentPlayer = 'X';
}

 void displayBoard() {
	cout << " 0    1    2 "<<endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void getComputerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}

char Player1Sign() {
	char b;
    cout << "Player 1, choose your sign ('O' or 'X'): ";
    cin >> sign;

    while (sign != 'O' && sign != 'X') {
        cout << "Invalid input." << endl;
        cout << "Please enter 'O' or 'X': ";
        cin >> sign;
    }
    if(sign =='X'){
    	b='O';
	}else if(sign =='O'){
		b='X';
	}
     cout << "Player 1 sign : "<<sign<<endl;
      cout << "Player 2 sign : "<<b<<endl;
    return sign;
}
char PlayercompSign() {
    cout << "Player sign = X "<<endl;
    cout <<"computer sign = O"<<endl;

}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void makeMove(int row, int col, char player) {
    if (isValidMove(row, col)) {
        board[row][col] = player;
    } else {
        cout << "Invalid move! Please try again." << endl;
        // Optionally, you could prompt the player to enter a new move here
    }
}
void makeMove1(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = sign;
        // Switch player
        if (sign == 'X') {
            sign = 'O';
        } else {
            sign = 'X';
        }
    } else {
        cout << "Invalid move! Please try again." << endl;
    }
}
bool isGameOver() {
	 // Checking rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
    }
    // Checking  columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return true;
        }
    }
    // Checking  diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }
    // Checking for a tie
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    // If no empty spaces left, it's a tie
    return true;
    // Checking rows, columns, and diagonals for a win
    // (Implementation remains the same as before)
}

char getWinner() {
   // Checking rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // Checking columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    
    // Checking  main diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    // Checking second diagonal
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    
    return ' '; // Checking rows, columns, and diagonals for a winner
    // (Implementation remains the same as before)
}

void play() {
    int row, col;
    initializeBoard();
    displayBoard();
    while (!isGameOver()) {
        cout << "Player " << sign << ", enter your move (row and column): ";
        cin >> row >> col;
        makeMove1(row, col);
        displayBoard();
    }
    char winner = getWinner();
    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

void playAgainstComputer() {
    initializeBoard();
    displayBoard();
    
    // Computer makes the first move
    cout << "Computer is making the first move..." << endl;
    getComputerMove();
    displayBoard();
    
    // Game loop
    while (!isGameOver()) {
        // Player's turn
        if (currentPlayer == 'X') {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            makeMove(row, col, currentPlayer);
            displayBoard();
        }
        
        // Check if player's move caused a win or tie
        if (isGameOver()) {
            break; // Exit the loop if the game is over
        }
        
        // Computer's turn
        cout << "Computer is making a move..." << endl;
        getComputerMove();
        displayBoard();
        
        // Check if computer's move caused a win or tie
        if (isGameOver()) {
            break; // Exit the loop if the game is over
        }
    }
    
    // Determine the winner or tie
    char winner = getWinner();
    if (winner == 'O') {
        cout << "Computer wins!" << endl;
    } else if (winner == 'X') {
        cout << "Player wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}


int main() {
	 srand(time(0));
    system("COLOR 5");
    cout << "\n\t\t\t| TIC |\t X  |  O  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  X  |\tTAC |  X  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  O  |\t X  | TOE |" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<"WELCOME TO TIC TAC TOE "<<endl;
    cout<<"PLEASE CHOSE YOUR MODE"<<endl;
    cout << endl;
    cout << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> gameMode;

    if (gameMode == 1) {
        
        system("COLOR 0e");
        system("cls");
        printf("\e[?25l");
        SetConsoleCP(437);
        SetConsoleOutputCP(437);
        int bar1 = 177, bar2 = 219;
        cout << "\n\n\n\t\t\t\t Loading...";
        cout << "\n\n\n\t\t\t\t";
        cout << "\r";
        cout << "\t\t\t\t";
        for (int i = 0; i < 25; i++) {
            cout << (char)bar2;
            Sleep(150);
        }
        system("cls");
        system("COLOR 2");
        Player1Sign();
        play();
    } else if (gameMode == 2) {
       
        system("COLOR 0e");
        system("cls");
        printf("\e[?25l");
        SetConsoleCP(437);
        SetConsoleOutputCP(437);
        int bar1 = 177, bar2 = 219;
        cout << "\n\n\n\t\t\t\t Loading...";
        cout << "\n\n\n\t\t\t\t";
        cout << "\r";
        cout << "\t\t\t\t";
        for (int i = 0; i < 25; i++) {
            cout << (char)bar2;
            Sleep(150);
        }
        system("cls");
        system("COLOR 2");
         PlayercompSign();
        playAgainstComputer();
    }

    return 0;
}
