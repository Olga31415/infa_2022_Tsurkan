#include <iostream>
using namespace std;

void traffic(bool crustal[1000], int size, int &x){
    int traf = rand() % 2 +1;

    if(traf==1){
        crustal[x]=0;
        x+=1;
        crustal[x]=1;
    }
    if(traf==2){
        crustal[x]=0;
        x-=1;
        crustal[x]=1;
    }

}

int main(){
    srand(time(NULL));
    int size =0;
    cin >> size;
    bool crystal[1000]={0};
    int x = (size-1)/2;
    crystal[x]=1;
    unsigned long long i = 0;
    while(x!=0 and x!=size-1 ){
        traffic(crystal,size,x);
        i+=1;
    }
    cout<<"moves "<<i << endl;
    cout<<"size "<<size;
    return 0;

}
