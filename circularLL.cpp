#include <iostream>
using namespace std ;

class Node {
    public : 
    int data ; 
    Node* next ;

    Node(int val){
        data = val ;
        next = NULL ; 
    }
};

class DoublyList {
    Node* head ;
    Node * tail ;

    public : 
    DoublyList(){
        head=tail = NULL ;
    }
     void insertHead(int val){
            Node* newNode = new Node(val);
            if(head== NULL){
                head = tail = newNode;
                  tail->next = head ; 
                return ; 
            } else {
                newNode->next = head ;
                head = newNode ;
                  tail->next = head ; 
              
            }

        }
          void insertTail(int val){
            Node* newNode = new Node(val);
            if(head==NULL){
                head=tail = newNode ; 
                tail -> next = head ;
                return ; 

            } else {
                 
                newNode->next = head ; 
                tail-> next  = newNode ; 
                tail = newNode ; 
            }
        }

        void deleteAtHead(int val ){
           if(head==NULL){
            return ; 
           }
           else if (head==tail){
            delete head ;
            head= tail = NULL ; 

           } else {
             Node* temp = head ;  // store the head to temp 
            head = head-> next ; //assign the head to next 

        
            temp-> next = NULL ; //break the connection 
            delete temp ;


           }
           
        }

        void deleteTail (int val ){
            if(head== NULL){
                return ; 
            } else if(head==tail){
                delete head ; 
                head = tail = NULL ;
            } else {
                   
            Node* temp = tail ;
            Node* prev = head ;
            while(prev-> next != tail){
                prev= prev->next ; 
            }
            tail = prev ;
            tail-> next = head ;
            temp->next = NULL ; 
            delete temp ;

            }
            

        }
        void printLL(){

            if(head==NULL) return ; 

        Node* temp = tail  ; 
        while(temp!= head){ // coz tail points to head 
            cout << temp->data << ' ';
            temp = temp->next ; 
        }
        cout<< temp-> data << endl ; 
      }
};



int main(){

}