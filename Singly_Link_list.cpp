#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"The memory is freed for -> "<<value<<endl;
    }
};

void insertAthead(node* &head,int d){
    //Perfect
    node* temp=new node(d);

    temp->next=head;
    head=temp;
}

void insertAttail(node* &tail,int d){
    //This is OK using tail
    node* temp=new node(d);

tail->next=temp;
    tail=temp;

    //SEE ANOTHER FILE TO CHECK IMPLEMENTATION USING { HEAD } ONLY
}

void inseretAtposition(node* &head,node* &tail, int pos,int d){
    //Insereting in first position 
    if(pos==1){
        insertAthead(head,d);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    //Inserting in last position 
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }
    node* NodetoInsert=new node(d);
    NodetoInsert->next=temp->next;
    temp->next=NodetoInsert;

}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Delete(node* &head,int pos){
    if(pos==1){
        node* temp=head;
        head=head->next;
         //IMPORTANT
        temp->next=NULL;
       
        delete temp;
    }
    node* curr=head;
    node* prev=NULL;
    int cnt=1;
   while(cnt<pos){
    prev=curr;
        curr=curr->next;
        cnt++;
   }
   prev->next=curr->next;
   // Important 
   curr->next=NULL;
   delete curr;

}

int main(){
    node* n1=new node(66);

    node* head=n1;
    node* tail=n1;

    insertAthead(head,457);insertAthead(head,56);insertAthead(head,78);

    print(head);
    insertAttail(tail,78);insertAttail(tail,23);
    print(head);
    inseretAtposition(head,tail,4,3475);

    print(head);
    Delete(head,4);
    print(head);
    Delete(head,1);
    print(head);

}