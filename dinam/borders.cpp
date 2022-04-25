#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b){
    int c;
    if(a<b){
        c=a;
    } else{c=b;}
    return c;
}

int max(int a, int b){
    int c;
    if(a>b){
        c=a;
    } else{c=b;}
    return c;
}

int main(){
    int N=10;
    int arr[N][N]={{1,1,1,1,2,2,2,2,2,2},
                   {1,1,1,1,1,2,2,2,3,3},
                   {1,1,1,1,1,1,2,2,3,3},
                   {1,1,1,1,1,1,2,3,3,3},
                   {1,1,1,1,1,1,2,2,3,3},
                   {1,1,1,2,2,2,2,3,3,3},
                   {1,1,3,2,2,2,2,3,3,3},
                   {1,1,2,2,2,2,2,3,3,3},
                   {1,1,3,3,3,3,3,3,3,3},
                   {3,3,3,3,3,3,3,3,3,3}};
    int FL[N][N];
    int FR[N][N];
    int F[N][N];
    for(int i=0; i<N;++i){
        for(int j=0; j<N;++i){
            if(i==0 or j==0){
                FL[i][j]=0;
                FR[i][j]=0;
            }
            if(i!=0 and j!=0) {
                if (arr[i - 1][j] != arr[i][j] or arr[i][j - 1] != arr[i][j]) {
                    FL[i][j] = 0;
                } else{
                    FL[i][j]=1+min(arr[i-1][j],arr[i][j-1]);
                }
            }
            if(i!=0 and j!=0) {
                if (arr[i + 1][j] != arr[i][j] or arr[i][j + 1] != arr[i][j]) {
                    FR[i][j] = 0;
                } else{
                    FR[i][j]=1+min(arr[i+1][j],arr[i][j+1]);
                }
            }
            F[i][j]=min(FL[i][j], FR[i][j]);
        }
    }
    int check=0;
    for(int i=0; i<N;++i){
        for(int j=0; j<N;++i){
            if(arr[i][j]==1){
                check=max(check,F[i][j]);}

        }
    }
    cout<<check<<endl;

    check=0;
    for(int i=0; i<N;++i){
        for(int j=0; j<N;++i){
            if(arr[i][j]==2){
                check=max(check,F[i][j]);}
        }
    }
    cout<<check<<endl;


    check=0;
    for(int i=0; i<N;++i){
        for(int j=0; j<N;++i){
            if(arr[i][j]==3){
                check=max(check,F[i][j]);}
        }
    }
    cout<<check<<endl;
    return 0;
}
