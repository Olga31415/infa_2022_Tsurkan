#include <iostream>
#include <cmath>
#include "extension.hpp"
using namespace std;

struct phone_book{
    char surname[20];
    char name[20];
    int phone;
};

void serch(phone_book list[7], int a){
    char m[20];
    int k;
    int chek=0;
    if(a==1){
        cout<<"enter surname:";
        cin>>m;
        for(int i=0; i<7;++i){
            if(list[i].surname[0]==m[0]){
                cout<<list[i].surname<<" "<<list[i].name<<" "<<list[i].phone<< endl;
                chek+=1;
            }
        }
        if(chek==0){
            cout<<"not found";
        }
    }
    if(a==2){
        cout<<"enter name:";
        cin>>m;
        for(int i=0; i<7;++i){
            if(list[i].name[0]==m[0]){
                cout<<list[i].surname<<" "<<list[i].name<<" "<<list[i].phone<< endl;
                chek+=1;
            }
        }
        if(chek==0){
            cout<<"not found";
        }
    }
    if(a==3){
        cout<<"enter phone number:";
        cin>>k;
        for(int i=0; i<7;++i){
            if(list[i].phone==k){
                cout<<list[i].surname<<" "<<list[i].name<<" "<<list[i].phone<< endl;
                chek+=1;
            }
        }
        if(chek==0){
            cout<<"not found";
        }
    }
}

int main(){
    phone_book list[7]={
            {"A","I", 235},
            {"B", "S", 412},
            {"C","A", 544},
            {"B","N", 111},
            {"D","A",909},
            {"T","M",981},
            {"M","T",522}
    };
    int a;
    cin>>a;
    if(a==1 or a==2 or a==3){serch(list,a);}
    else{cout<<"error";}
    return 0;
}