#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x):data(x),next(NULL) {}
};
class LinkedList{
    public:
    Node * head;
    LinkedList(){
        head=NULL;
    }
    void insertfront(int x){
        Node* newNode=new Node(x);
       newNode->next=head;
       head=newNode;
    }
    void insertend(int x){
         Node* newNode=new Node(x);
         Node* temp=head;
         if(head==NULL){
            head=newNode;
            return;
         }
         while(temp->next!=NULL){
            temp=temp->next;
         }
         temp->next=newNode;
     }
     void insertpos(int x,int pos){
        Node* newNode=new Node(x);
          if(pos==0){
         insertfront(x);
         return;
          }
           Node* temp=head;
         for(int i=0;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
         }
            if(temp == NULL) {
            delete newNode;
            return;
        }
        newNode->next=temp->next;
         temp->next=newNode;
     }
     void deletef(){
        if(head==NULL){return;}
          Node* temp=head;
          head=temp->next;
          delete temp;
     }
     void deleteb(){
        if(head==NULL){return;}
        if(head->next==NULL){
            delete(head);
            head=NULL;
            return;
        }
         Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
          delete temp->next;
           temp->next=NULL;
     }
     void deletepos(int pos){
        if(head==NULL){return;}
        if(pos==0){
            deletef();
        }
           Node* temp=head;
         for(int i=0;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
         }
         if(temp == NULL|| temp->next==NULL) {
            return;
        }
        Node* dele=temp->next;
        temp->next=dele->next;
        delete dele;
     }
     bool search(int x){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==x)return true;
            temp=temp->next;
        }
        return false;
     }
     int len(){
      int count=0;
       Node* temp=head;
      while(temp!=NULL){
       count++;
        temp=temp->next;
      }
      return count;
     }
    void dis(){
        Node* temp=head;
      while(temp!=NULL){
       cout<<temp->data<<" ";
        temp=temp->next;
      }
      cout<<"NULL"<<endl;
    }

};
int main() {
    LinkedList list;

    list.insertfront(10);
    list.insertend(20);
    list.insertend(30);
    list.insertpos(25, 2);

    list.dis();

    list.deletef();
    list.dis();

    list.deleteb();
    list.dis();

    list.deletepos(1);
    list.dis();

    cout << "Length: " << list.len() << endl;
    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}