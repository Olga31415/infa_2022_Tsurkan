#include <iostream>
#include <cstring>
using namespace std;


struct forward_list {
    int distance;
    forward_list *last;
    forward_list *next;
};

forward_list *create_node( int dist) {
    auto node = new forward_list;
    node->distance = dist;
    node->last= nullptr;
    node->next = nullptr;
    return node;
}

forward_list *insert_front(forward_list *head, forward_list *node) {
    node->next = head;
    if(head!= nullptr){
        head->last=node;}
    return node;
}

forward_list *insert_after(forward_list *after, forward_list *node) {
    if (after == nullptr)
        return insert_front(after, node);
    node->next = after->next;
    after->next = node;
    (node->next)->last = node;
    node->last=after;
    return node;
}

forward_list *insert_before(forward_list *head, forward_list *before, forward_list *node) {
    if (head == before)
        return insert_front(head, node);

    node->next = before;
    auto it = head;
    for (;it != nullptr && it->next != before;
          it = it->next){
    }

    if (it == nullptr){
        cerr << "Wrong insert!" << endl;
        exit(-10);
    }

    it->next = node;
    node->last=it;
    before->last=node;
    return node;
}

void num_filling(forward_list* first, forward_list* back, int N){
    auto it=back;
    float check=1000.0f;
    while(check>1.0f){
        check=(float)(it->distance-first->distance)/N;
        if(check>1){
            it=it->last;
        }
    }
    if(it->distance==first->distance){
        cout<<"error";
    }
    if(it->distance==back->distance){
        first->next=back;
        back->last=first;
        cout<<it->distance;
    }
    if(it->distance!=first->distance and it->distance!=back->distance){
        first->next=it;
        it->last=first;
        cout<<it->distance<<endl;

        num_filling(it, back, N);
    }

}


int main(){
    int N=0;
    cin>>N; // сколько можно проехать с полным баком
    auto fil_0 = create_node(0);
    auto fil_1 = create_node(5);
    auto fil_2 = create_node(11);
    auto fil_3 = create_node(12);
    auto fil_4 = create_node(19);
    auto fil_5 = create_node(28);
    auto fil_6 = create_node(30);
    insert_front(fil_6,fil_5);
    insert_front(fil_5,fil_4);
    insert_front(fil_4,fil_3);
    insert_front(fil_3,fil_2);
    insert_front(fil_2,fil_1);
    insert_front(fil_1,fil_0);
    num_filling(fil_0,fil_6,N);

    return 0;
}
