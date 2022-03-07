#include <iostream>
using namespace std;

void traffic(bool crustal[400][400], int size, unsigned long long &chek){
    for(int i =0; i<size;++i){
        for(int j =0; j<size;++j){
            if(crustal[i][j]==1  and j!=0 and j!=size-1 and i!=0 and i!=size-1 and crustal[i+1][j]!=1 and crustal[i-1] [j]!= 1 and crustal[i][j+1]!=1 and crustal[i][j-1] != 1){
                int traf = rand() % 5 +1;

                if(traf==1){
                    if(crustal[i][j+1]==0){
                        crustal[i][j]=0;
                        j+=1;
                        crustal[i][j]=11;
                        chek+=1;
                    }
                    else{
                        traf = 2;
                    }
                }
                if(traf==2){
                    if(crustal[i][j-1]==0) {
                        crustal[i][j] = 0;
                        j -= 1;
                        crustal[i][j] = 11;
                        chek+=1;
                    }
                    else{
                        traf = 3;
                    }
                }

                if(traf==3){
                    if(crustal[i+1][j]==0) {
                        crustal[i][j]=0;
                        i+=1;
                        crustal[i][j]=11;
                        chek+=1;}
                    else{
                        traf = 4;
                    }
                }
                if(traf==4){
                    if(crustal[i-1][j]==0) {
                        crustal[i][j]=0;
                        i-=1;
                        crustal[i][j]=11;
                        chek+=1;}
                }
                if (traf==5){
                    crustal[i][j]=11;
                }

            }

        }
    }
    for(int i =0; i<size;++i) {
        for (int j = 0; j < size; ++j) {
            if (crustal[i][j] == 11) {
                crustal[i][j] = 1;
            }
            //cout << crustal[i][j]  << ' ';
        }
        //cout << endl;

    }
//    cout << endl;
}

int main(){
    int s =0;
    for(int m=0;m<5;++m){
        srand(time(NULL));
        unsigned long long chek =0;
        unsigned long long chek2 =1;
        int size =400;
        bool crystal[400][400]={0};
        int count = 1000;
        int num =0;
        while (num!=count){
            int x = rand()%400+1;
            int y = rand()%400+1;
            if (crystal[y][x]!=1){
                crystal[y][x]=1;
                num+=1;}
        }
        int aboba = 0;
        while (chek!=chek2){
            chek2=chek;
            traffic(crystal,size,chek);
            aboba++;
        }

        s+=aboba;
        cout<<"moves "<< aboba - 1 << endl;
        //cout<<"size "<<size*size<<endl;
    }
    //s=s/5;
    cout<<s;
    return 0;
}

