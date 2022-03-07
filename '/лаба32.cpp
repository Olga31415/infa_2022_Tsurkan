#include <iostream>
using namespace std;

void traffic(bool crustal[400], int size, unsigned long long &chek){
    cout << endl;
    for(int i =0; i<size;++i){
            if(crustal[i]==1  and i!=0 and i!=size-1 and crustal[i+1]!=1 and crustal[i-1] != 1){
                int traf = rand() % 3 +1;

                if(traf==1){
                    if(crustal[i+1]==0){
                        crustal[i]=0;
                        crustal[i+1]=11;
                        chek+=1;
                    }
                    else{
                        traf = 2;
                    }
                }
                if(traf==2){
                    if(crustal[i-1]==0) {
                        crustal[i] = 0;
                        crustal[i-1] = 11;
                        chek+=1;
                    }
                }
                /*if(traf==3){
                    crustal[i]=11;
                }*/
            }

        }

    for(int i =0; i<size;++i) {
            if (crustal[i] == 11) {
                crustal[i] = 1;
            }
            cout << crustal[i]  << ' ';
        }
    }

int main(){
    int s =0;
    for(int m=0;m<5;++m) {
        srand(time(NULL));
        unsigned long long chek = 0;
        unsigned long long chek2 = 1;
        int num = 0;
        int size = 400;
        bool crystal[400] = {0};
        int count = 300;
        while (num != count) {
            int x = rand() % 400 + 1;
            if (crystal[x] != 1) {
                crystal[x] = 1;
                num += 1;
            }
        }
        int aboba = 0;
        while (chek != chek2) {
            chek2 = chek;
            traffic(crystal, size, chek);
            aboba++;
        }
        s+=aboba;
        cout << "moves " << aboba << endl;

    }

    cout<<s;
    return 0;
}


