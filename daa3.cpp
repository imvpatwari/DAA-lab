#include <iostream>
#define n 5 
using namespace std;
class nqueens
{
public:
    void Queen(int board[n][n], int col);
    bool place(int board[n][n], int row, int col);
    void display(int board[n][n]);
};
void nqueens::Queen(int board[n][n], int col)
{
    if (col >= n)
    {
        display(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (place(board, i, col))
        {
            board[i][col] = 1;
            Queen(board, col + 1);
            board[i][col] = 0;
        }
    }
}
bool nqueens::place(int board[n][n], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}
void nqueens::display(int board[n][n])
{
    cout << endl
         << "***************************************************************************************";
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "   " << board[i][j];
        cout << "\n";
    }
}
int main()
{
    nqueens nq;
    int board[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    nq.Queen(board, 0);
    return 0;
}
