#include <iostream>
using namespace std;

void traffic(bool crustal[1000][1000], int size, int &x, int &y){
    int traf = rand() % 4 +1;

    if(traf==1){
        crustal[y][x]=0;
        x+=1;
        crustal[y][x]=1;
    }
    if(traf==2){
        crustal[y][x]=0;
        x-=1;
        crustal[y][x]=1;
    }
    if(traf==3){
        crustal[y][x]=0;
        y+=1;
        crustal[y][x]=1;
    }
    if(traf==4){
        crustal[y][x]=0;
        y-=1;
        crustal[y][x]=1;
    }
}

int main(){
    srand(time(NULL));
    int size =0;
    cin >> size;
    bool crystal[1000][1000]={0};
    int x = (size-1)/2;
    int y = (size-1)/2;
    crystal[y][x]=1;
    unsigned long long i = 0;
    while(x!=0 and x!=size-1 and y!=0 and y!=size-1){
        traffic(crystal,size,x,y);
        i+=1;
    }
    cout<<"moves "<<i << endl;
    cout<<"size "<<size*size;
    return 0;

}
