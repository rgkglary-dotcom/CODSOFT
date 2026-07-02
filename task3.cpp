#include <iostream>
using namespace std;
char board[3][3];
void initBoard() 
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}
void displayBoard() 
{
    cout << "\n";
    for (int i = 0; i < 3; i++) 
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}
bool isValidMove(int row, int col) 
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;
    if (board[row][col] != ' ')
        return false;
    return true;
}
void updateBoard(int row, int col, char player) 
{
    board[row][col] = player;
}
bool checkWin(char player) 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}
int main() 
{
    char currentPlayer;
    char playAgain;
    do 
    {
        initBoard();
        currentPlayer = 'X';
        bool gameOver = false;
        while (!gameOver) 
        {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter row and column (1-3 1-3): ";
            cin >> row >> col;
            row--; col--;
            if (!isValidMove(row, col)) 
            {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            updateBoard(row, col, currentPlayer);
            if (checkWin(currentPlayer)) 
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) 
            {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else 
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } 
    while (playAgain == 'y' || playAgain == 'Y');
    cout << "Thanks for playing!\n";
    return 0;
}