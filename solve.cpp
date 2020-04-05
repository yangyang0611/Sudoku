#include <iostream>
#include <fstream>
#define undefine 0
#define N 9
using namespace std;


bool F(int g[N][N], int &row, int &col);


bool S(int g[N][N], int row, int col, int num);


bool Solve(int g[N][N]) {
    int row, col;
    if (!F(g, row, col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (S(g, row, col, num)) {
            g[row][col] = num;
            if (Solve(g))
                return true;
            g[row][col] = undefine;
        }
    }
    return false;
}


bool F(int g[N][N], int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (g[row][col] == undefine)
                return true;
    return false;
}


bool checkRow(int g[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
        if (g[row][col] == num)
            return true;
    return false;
}


bool checkCol(int g[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
        if (g[row][col] == num)
            return true;
    return false;
}


bool checkBox(int g[N][N], int b_row, int b_col, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (g[row+b_row][col+b_col] == num)
                return true;
    return false;
}


bool S(int g[N][N], int row, int col, int num) {

    return !checkRow(g, row, num) &&
           !checkCol(g, col, num) &&
           !checkBox(g, row - row%3, col - col%3, num)&&
           g[row][col]==undefine;
}


int main() {

    int g[N][N],place=0,i,j;
    for( i=0; i<9; i++) {
        for( j=0; j<9; j++) {
            cin>>g[i][j];
        }
    }

    for(i=0; i<9; i++)
        for(j=0; j<9 ; j++)
            if(g[i][j] == 0)place=place+1;

    if(place < 65) {

        if (Solve(g) == true) {
            cout<<'1'<<endl;
            for (i = 0; i < N; i++) {
                for (j  = 0; j < N; j++) {
                    if(j==8)cout<<g[i][j]<<endl;
                    else cout<<g[i][j]<<' ';
                }
            }
        } else
            cout<<'0';
    } else
        cout<<'2';
    return 0;

}

