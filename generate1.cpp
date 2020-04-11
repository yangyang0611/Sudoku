#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
    srand(time(NULL));  // every time rand no same
    int ini[9][9]={0},a[9][9],aa,b,c,bb,cc,z;
    ifstream in("text",ios::in);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            in>>ini[9][9];

    aa = rand()%6+3;
    while(aa!=0){
        b = rand()%5+1, c = rand()%4+6;
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++){
                if(ini[i][j]==b)
                    ini[i][j]=c;
                else if(ini[i][j]==c)
                    ini[i][j]=b;
            }
        aa=aa-1;
    }
    aa=rand()%2+1;
    while(aa!=0){
        b = rand()%3+0, c = rand()%3+0;
        for(int i=0; i<9; i++)
            for(int j=0,bb=3*b,cc=3*c; j<3; j++,bb++,cc++){
                int temp=ini[i][bb];
                ini[i][bb]=ini[i][cc];
                ini[i][cc]=temp;
            }
        aa=aa-1;
    }

    aa=rand()%3+1;
    while(aa!=0){
        for(int i=0;i<9;i++)
            for(int j=0;j<9; j++)
                a[i][j]=ini[i][j];

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                ini[j][z]=a[i][j];
            }
        aa=aa-1;
    }

    for(int i=0;i<9;i++){
        aa=rand()%3+4;
        for(int j=aa; j>0; j--){
            z=rand()%9+0;
            ini[i][z]=0;
        }
    }

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(j==8)
                cout<<ini[i][j]<<endl;
            else
                cout<<ini[i][j]<<' ';
        }
}
