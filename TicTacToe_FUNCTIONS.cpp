#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;
char sign;

void initializeBoard() {
    // Initialize the board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    // Seting initial player
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

char Player1Sign() {
    cout << "Player 1, choose your sign ('O' or 'X'): ";
    cin >> sign;

    while (sign != 'O' && sign != 'X') {
        cout << "Invalid input."<<endl; 
        cout<<"Please enter 'O' or 'X': ";
        cin >> sign;
    }
    return sign;
}

char Player2Sign(char sign) {
    
    if (sign == 'O') {
        cout<<"Player 1 -- O"<<endl;
        cout<<"Player 2 -- X"<<endl;
        return 'X';
    } else {
        cout<<"Player 1 -- X"<<endl;
        cout<<"Player 2 -- O"<<endl;
        return 'O';
    }
}

// Function to check if the move is valid
bool isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to make a move
void makeMove(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = currentPlayer;
        // Switch player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    } else {
        cout << "Invalid move! Please try again." << endl;
    }
}


// Function to check if the game is over
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
}

// Function to get the winner
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
    
    
    return ' ';
}

// Function to play the game
void play() {
    int row, col;
    initializeBoard();
    displayBoard();
    while (!isGameOver()) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        makeMove(row, col);
        displayBoard();
    }
    char winner = getWinner();
    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

int main(){
    cout << endl;
    cout << "\t\t\t| TIC |\t X  |  O  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  X  |\tTAC |  X  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  O  |\t X  | TOE |" << endl;

    Player1Sign();
    Player2Sign(sign);
    play();

    return 0;
}