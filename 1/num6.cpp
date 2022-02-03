#include <iostream>
using namespace std;

int main() {
    int x = 0;
    int y =0;
    cin >> x;
    int K = 1;
    int max =1;
    while(cin >> y)  {
        if (y>x) {
            K+=1;
        }
        else if(K>max){
            max = K;
            K = 1;
        }
        else{
            K = 1;
        }
        x=y;
    }
    cout << max;
    return 0;
}