#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;


    Node(int val){
        data=val;
        next=NULL;
    }
};

class list{ 
    Node* head;
    Node* tail;
    public:
    list(){
        head=tail=NULL;
    }

    inline void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    inline void push_front(int val){
    Node* newNode= new Node(val);
    if(head==NULL){
        head=tail=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
    }

    inline void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }

    inline void pop_back(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp=head;
        while (temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;   
    }

    inline void pop_front(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    inline void insert(int val, int key){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
        Node* temp=head;
        for(int i=0;i<key-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;   
    }

    inline void pop_mid(int key){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp=head;
        for(int i=0;i<key-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }

    inline void deletell(){
        hare:
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        head=NULL;
        goto hare;
        
    }

    
};

int main(){
    system("clear");
    list a;
    
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);

    a.push_back(4);
    
    a.display();

    a.pop_back();

    a.pop_front();

    a.insert(4,1);

    a.pop_mid(1);
    a.display();

    a.deletell();

}




