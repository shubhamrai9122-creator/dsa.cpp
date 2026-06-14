// Implementation of Linkedlist Class
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    void InsertFront(int x){
        Node* new_Node = new Node(x);
        if(head==NULL){
            head=new_Node;
            tail=new_Node;
            return;
        }
        new_Node->next=head;
        head->prev=new_Node;
        head=new_Node;
    }
    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head=tail=newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }


    void deleteNode(int val) {
        Node* curr = head;
        while (curr && curr->data != val)
            curr = curr->next;
        if(!curr)
            return;
        if(curr == head)
            head = curr->next;
        if(curr == tail)
            tail = curr->prev;
        if(curr->prev)
            curr->prev->next = curr->next;
        if(curr->next)
            curr->next->prev = curr->prev;
        delete curr;
    }


    void displayForward(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


    void displayBackward(){
        Node* temp = tail;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
    }

};


// Leetcode Question 707
class Node{
public:
   int data;
   Node*next;
   Node(int val){
    data = val;
    next = NULL;
   }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = tail = NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size){
        return -1;
        }
        if(index == 0){
            return head->data;
        }
        if(index == size -1){
            return tail->data;
        }
        Node* temp = head;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(size==0){                           
          head = tail = newnode;
        }
        else{
        newnode->next = head;
        head = newnode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
         if(size==0){    
            head=tail=newnode;
        }else{
        tail->next = newnode;  
        tail = newnode;
        }      
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){   
            addAtTail(val);
            return;
        }
         Node* newnode = new Node(val);
        Node* temp = head;
        for(int i = 0;i<index-1;i++){
            temp = temp->next;
        }                           
        temp->next = newnode;       
        size++;   
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        if(index == 0){
            Node*temp = head;
            head = head->next;
            delete temp;
            if(size == 1) tail = NULL;
        }
        else{  
            Node* temp = head;
            for(int i = 0;i<index-1;i++){
                temp=temp->next;
            }
            Node*remove = temp->next;   
            temp->next = temp->next->next; 
            delete remove;                 
            if(index == size-1) tail = temp;   
        }
        size--;
    }
};
