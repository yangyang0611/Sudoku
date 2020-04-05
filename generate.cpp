#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main() {
    srand(time(NULL));
    int a[9][9]= {0},ab[9][9],i=0,j=0,aa,b,c,bb,cc,z;
    ifstream in("text",ios::in);
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            in>>a[i][j];

    aa = rand()%6+3;
    while(aa!=0) {
        b = rand()%5+1, c = rand()%4+6;
        for(i=0; i<9; i++)
            for(j=0; j<9; j++) {
                if(a[i][j] == b) a[i][j] = c;
                else if(a[i][j] == c) a[i][j] = b;
            }
        aa=aa-1;
    }
    aa = rand()%2+1;
    while(aa!=0) {
        b = rand()%3+0, c = rand()%3+0;
        for(i=0; i<9; i++)
            for(bb=3*b,cc=3*c,j=0; j<3; j++,bb++,cc++) {
                int temp = a[i][bb];
                a[i][bb]=a[i][cc];
                a[i][cc] = temp;
            }
        aa=aa-1;
    }

    aa = rand()%3+1;
    while(aa!=0) {
        for(i=0; i<9; i++)
            for(j=0; j<9; j++)
                ab[i][j]=a[i][j];


        for(i=0,z=8; i<9; i++,z--)
            for(j=0; j<9; j++) {
                a[j][z]= ab[i][j];
            }
        aa=aa-1;
    }


    for(i=0; i<9; i++) {
        aa =rand()%3+4;
        for(j=aa; j>0; j--) {
            z = rand()%9+0;
            a[i][z] = 0;
        }
    }

    for(i=0; i<9; i++)
        for(j=0; j<9; j++) {
            if(j==8)cout<<a[i][j]<<endl;
            else cout<<a[i][j]<<' ';
        }


}


