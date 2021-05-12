#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int gtan[9][9],tgtan[9][9],i,j,k,a,b,c,temp,tb,tc;

    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            cin>>gtan[i][j];
            tgtan[i][j]=gtan[i][j];
        }
    }
    while(cin>>a && a!=0) {
        switch(a) {

        case 1: {
            cin>>b>>c;
            for(i=0; i<9; i++)
                for(j=0; j<9; j++) {
                    if(gtan[i][j] == b) gtan[i][j] = c;
                    else if(gtan[i][j] == c) gtan[i][j] = b;
                }
            break;
        }
        case 2:
            cin>>b>>c;
            for(j=0; j<9; j++) {
                temp = gtan[3*b][j];
                gtan[3*b][j]=gtan[3*c][j];
                gtan[3*c][j] = temp;

                temp = gtan[3*b+1][j];
                gtan[3*b+1][j]=gtan[3*c+1][j];
                gtan[3*c+1][j] = temp;

                temp = gtan[3*b+2][j];
                gtan[3*b+2][j]=gtan[3*c+2][j];
                gtan[3*c+2][j] = temp;
            }
            break;
        case 3:
            cin>>b>>c;
            for(i=0; i<9; i++)
                for(tb=3*b,tc=3*c,j=0; j<3; j++,tb++,tc++) {
                    temp = gtan[i][tb];
                    gtan[i][tb]=gtan[i][tc];
                    gtan[i][tc] = temp;
                }
            break;
        case 4:
            cin>>b;
            while(b!=0) {
                for(i=0; i<9; i++)
                    for(j=0; j<9; j++)
                        tgtan[i][j]=gtan[i][j];


                for(i=0,k=8; i<9; i++,k--)
                    for(j=0; j<9; j++) {
                        gtan[j][k]= tgtan[i][j];
                    }
                b--;
            }
            break;
        case 5:
            cin>>b;
            if(b==0) {
                for(i=0,j=8; i<4; i++,j--)
                    for(k=0; k<9; k++) {
                        temp = gtan[i][k];
                        gtan[i][k]= gtan[j][k];
                        gtan[j][k]= temp;
                    }
            }
            if(b==1) {
                for(i=0; i<9; i++)
                    for(j=0,k=8; j<4; j++,k--) {
                        temp = gtan[i][j];
                        gtan[i][j]=gtan[i][k];
                        gtan[i][k]=temp;
                    }
            }

            break;
        }
    }
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++)
            if(j==8)cout<<gtan[i][j]<<endl;
            else cout<<gtan[i][j]<<' ';
    }

}

