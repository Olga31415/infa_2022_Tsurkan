#include <iostream>
#include <cstring>
using namespace std;

struct forward_list {
    int distance;
    int cost;
    int sum;
    forward_list *last;
};

forward_list *create_node( int dist, int cost) {
    auto node = new forward_list;
    node->distance = dist;
    node->cost=cost;
    node->last= nullptr;
    return node;}

forward_list *insert_front(forward_list *head, forward_list *node) {
        if(head!= nullptr){
            head->last=node;}
        return node;
    }

forward_list* cheapest_way(forward_list * hostels_list[8]){
    hostels_list[0]->sum=0;
    hostels_list[1]->sum=hostels_list[1]->cost;
    for(int i=2; i<8;++i){
        if(hostels_list[i]->cost+hostels_list[i-2]->sum<hostels_list[i]->cost+hostels_list[i-1]->sum){
            hostels_list[i]->last=hostels_list[i-2];
            hostels_list[i]->sum=hostels_list[i]->cost+hostels_list[i-2]->sum;
            }
        if(hostels_list[i]->cost+hostels_list[i-2]->sum>hostels_list[i]->cost+hostels_list[i-1]->sum){
            hostels_list[i]->sum=hostels_list[i]->cost+hostels_list[i-1]->sum;
            }
        }
    return hostels_list[7];
    }



int main(){
    auto hostel_0 = create_node(0, 0);
    auto hostel_1 = create_node(500, 20);
    auto hostel_2 = create_node(1000,31);
    auto hostel_3 = create_node(1500,18);
    auto hostel_4 = create_node(2000, 22);
    auto hostel_5 = create_node(2500, 35);
    auto hostel_6 = create_node(3000,28);
    auto hostel_7= create_node(3500,0);
    insert_front(hostel_7,hostel_6);
    insert_front(hostel_6,hostel_5);
    insert_front(hostel_5,hostel_4);
    insert_front(hostel_4,hostel_3);
    insert_front(hostel_3,hostel_2);
    insert_front(hostel_2,hostel_1);
    insert_front(hostel_1,hostel_0);
    forward_list* hostels_list[8]={hostel_0,
                                  hostel_1,
                                  hostel_2,
                                  hostel_3,
                                  hostel_4,
                                  hostel_5,
                                  hostel_6,
                                  hostel_7};
    auto it = cheapest_way(hostels_list);
    while (it->distance!= 0){
        cout<<it->distance<<','<<it->cost<<endl;
        it=it->last;
    }


    return 0;
}