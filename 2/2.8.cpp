#include <iostream>
using namespace std;



int main(){
    unsigned long long sum = 0;

    for(int i=0;i<2;++i){
        char n = '0';
        unsigned long long m= 0;
        while(cin>>n and n!='@'){
            if('A'<=n and n<='F'){
                m = m*16+(n -'A'+10);
            }
            if('0'<=n and n<='9'){
                m=m*16+(n-'0');
            }
        }
        sum+=m;
    }
    cout<<sum;
    return 0;
}


