#include <iostream>
#include <Windows.h>
#include <ctime>//using this library to for srand to generate random values
#include <cstdlib>

using namespace std;
//Declaring an abstract class
class Game {
protected:
// Declaring a character type array for the game board
    char board[3][3];
//Declaring a character type variable to switch between players 
    char currentPlayer;

public:
// using pure virtual function to avoid diamond problem
    virtual void initializeBoard() = 0;
    virtual void displayBoard() = 0;
    virtual bool isValidMove(int row, int col) = 0;
    virtual void makeMove(int row, int col) = 0;
    virtual bool isGameOver() = 0;
    virtual char getWinner() = 0;
    virtual void play() = 0;
};
//Making another class for P vs P and inheriting game class in it
class PlayerVsPlayer : public Game {
public:
//Making a constructor and initializing current player
    PlayerVsPlayer() {
        currentPlayer = 'X';
//Calling the function so that it could be called along with constructor
//at the time of compilation
        initializeBoard();
    }
//
    void initializeBoard()  {
        // Initializing the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }
    //Making a function to display the board 
    void displayBoard()  {
        // Adding grid numbers along columns 
    cout << "   0    1    2 " << endl; 
    cout << "  -------------" << endl;
    for (int i = 0; i < 3; ++i) {
        // Adding grid numbers along columns
        cout << i << " | "; 
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "  -------------" << endl;
    }
}

//using boolean to verify whether the entered number is in the range from (0 to 2)
    bool isValidMove(int row, int col)  {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col)  {
        //If the move is verified then storing it in the current player variable
        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
        //Using ifelse to switch between players
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
                } else {
                     currentPlayer = 'X';
                }
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    bool isGameOver()  {
        // Checking rows 
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
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

    char getWinner()  {
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
    }

    void play() {
        //Declaring 2 integer type variable to take input for the grid
        int row, col;
        //calling display board function
        displayBoard();
        //using while that if game is not over take input from the palyer for next move 
        while (!isGameOver()) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            //Taking input for the grid
            cin >> row >> col;
            //Sending values to make move and calling the function
            makeMove(row, col);
            //again calling display board to show the current move
            displayBoard();
        }
        //Declaring another character type variable and storing the value of chracter
        //from getwinner function
        char winner = getWinner();
        //using if else to Get the winning player
        if (winner != ' ') {
            cout << "Player " << winner << " wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
};
//Declaring another class for P vs C game and inheriting the Game class in it

    class PlayerVsComputer : public Game {
private:
    char playerSign;
    char computerSign;

public:
    PlayerVsComputer() {
        currentPlayer = 'X';
        initializeBoard();
    }

    void initializeBoard() {
        // Initializing the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() {
        // Displaying the board
        cout << "   0    1    2 " << endl; 
        cout << "  -------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i << " | "; 
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl << "  -------------" << endl;
        }
    }
void getComputerMove() {
    int row, col;
    do {
        //generate random moves 
        row = rand() % 3;
        col = rand() % 3;
    } 
    while (board[row][col] != ' ');//checking for empty spaces
     board[row][col] = computerSign;//placing computer sign
    currentPlayer = playerSign; // switching the current player 
}


    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }


   void makeMove(int row, int col) {
    if (isValidMove(row, col)) {
        board[row][col] = currentPlayer;

        if (currentPlayer == playerSign) {
            currentPlayer = computerSign;
            // Call the function to let the computer make its move
            getComputerMove();
        } else {
            // Switch currentPlayer  for the next move
            currentPlayer = playerSign;
        }
    } else {
        cout << "Invalid move! Please try again." << endl;
    }
}

      bool isGameOver()  {
        // Checking rows 
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
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

   char getWinner()  {
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
    }


   void play() {
    //Declaring 2 integer type variable to take input for the grid
    int row, col;
    //calling display board function
    displayBoard();
    //using while that if game is not over take input from the player for next move 
    while (!isGameOver()) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        //Taking input for the grid
        if (currentPlayer == playerSign) {
            cin >> row >> col;
            //Sending values to make move and calling the function
            makeMove(row, col);
        } else {
            // Computer's turn
            getComputerMove();
        }
        //again calling display board to show the current move
        displayBoard();
    }
    //Declaring another character type variable and storing the value of character
    //from getwinner function
    char winner = getWinner();
    //using if else to Get the winning player
    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

    //using setter because we have declared private members in this class
    void setSigns(char player, char computer) {
        playerSign = player;
        computerSign = computer;
    }

   
};


int main() {
    //using srand to genertate random values for computer
    srand(time(0));
    //Declaring a pointer for Game class so we could access functions 
    Game* game;
    //Declaring integer type variable for Gamemode
    int gameMode;
    //Declaring character type variable for Gamemode
    char playerSign, computerSign;
    //Using this to change the colour of compiler
    system("COLOR 4");
    cout<<  "\t\t       WELCOME TO TIC TAC TOE!"<<endl;
    cout << "\n\t\t\t| TIC |\t X  |  O  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  X  |\tTAC |  X  |" << endl;
    cout << "\t\t\t-------------------" << endl;
    cout << "\t\t\t|  O  |\t X  | TOE |" << endl;
    cout << endl;

    //Taking input from the user for play the mode
    cout<<"PLEASE CHOOSE YOUR MODE"<<endl;
    cout << "\t\t\t  1. Player vs Player" << endl;
    cout << "\t\t\t  2. Player vs Computer" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> gameMode;
    //Using this to clear the compiler
    system("cls");
    //Using if else to pick between the game modes
    if (gameMode == 1) {
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
        // Storing address of the P vs P function dynamically in the pointer 
        game = new PlayerVsPlayer();
        cout << "Player 1, choose your sign ('O' or 'X'): ";
        cin >> playerSign;
        //using while to verify the sign
        while (playerSign != 'O' && playerSign != 'X') {
            cout << "Invalid input. Please enter 'O' or 'X': ";
            cin >> playerSign;
        }
        //calling the play function using the pointer
        game->play();
    } else if (gameMode == 2) {
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
// Storing the address of  P vs C function dynamically in the pointer        
        game = new PlayerVsComputer();
        cout << "Player, choose your sign ('O' or 'X'): ";
        cin >> playerSign;
        while (playerSign != 'O' && playerSign != 'X') {
            cout << "Invalid input. Please enter 'O' or 'X': ";
            cin >> playerSign;
        }
           if (playerSign == 'O') {
          computerSign = 'X';
          }else {
           computerSign = 'O';
          }
        //Using dynamic casting to access the set sign function 
        dynamic_cast<PlayerVsComputer*>(game)->setSigns(playerSign, computerSign);
        //calling the play function using the pointer        
        game->play();
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    //Deleting the dynamically allocated memory
    delete game;
    return 0;
}
