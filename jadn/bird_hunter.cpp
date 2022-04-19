#include <iostream>
#include <cstring>
using namespace std;

struct birds{
    int amount_time;
    int start;
    int finish;
    birds* last;
    birds* next;
};


birds * create_bird(int amount_time, int start, int finish){
    auto node = new birds;
    node->amount_time=amount_time;
    node->start=start;
    node->finish=finish;
    node->last= nullptr;
    node->next= nullptr;
    return node;
}

void sort_birds(birds* arr[8], int first, int last){
    int mid;
    int f=first, l=last;
    mid=arr[(f+l)/2]->start;
    do{
        while (arr[f]->start<mid) f++;
        while (arr[l]->start>mid) l--;
        if (f<=l){
            swap(arr[f],arr[l]);
            f++;
            l--;
        }
    }
    while (f<l);

    if (first<l){sort_birds(arr, first, l);}
    if (f<last){sort_birds(arr, f, last);}

}

void birds_photo(birds* head){
    auto it = head->next;
    while(it != nullptr && it->start<head->finish){
            head->start=it->start;

        if(it->finish<head->finish){
            head->finish=it->finish;
        }
        it=it->next;
    }
    cout<<head->start<<endl;
    if(it!= nullptr){
        birds_photo(it);
    }
}

int main(){
    auto bird_1 = create_bird(5,1,6);
    auto bird_2 = create_bird(3,1,4);
    auto bird_3 = create_bird(3,2,5);
    auto bird_4 = create_bird(2,5,7);
    auto bird_5 = create_bird(6,6,12);
    auto bird_6 = create_bird(4,7,11);
    auto bird_7 = create_bird(2,8,10);
    auto bird_8 = create_bird(2,9,11);
    birds* arr[8]={bird_1,bird_2,bird_3,bird_4,bird_5,bird_6,bird_7,bird_8};
    sort_birds(arr,0,7);

    for(int i =0;i<8;++i){
        if(i!=0 && i!=7){
            arr[i]->next=arr[i+1];
            arr[i]->last=arr[i-1];
        }
        if(i==0){
            arr[i]->next=arr[i+1];
            arr[i]->last= nullptr;
        }
        if(i==7){
            arr[i]->next= nullptr;
            arr[i]->last= arr[i-1];
        }
    }
    birds_photo(arr[0]);
    return 0;
}

