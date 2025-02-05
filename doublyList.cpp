#include <iostream>
using namespace std ;

class Node {
    public : 
    int data ;
    Node* next ;
    Node* prev ; 

    Node(int val){
        data = val ;
        next = prev = NULL ; 
    }
}; 

class DoublyList {
    Node* head ;
    Node * tail ;

    public : 
    DoublyList(){
        head=tail = NULL ;
    }

     void push_front(int val){
            Node* newNode = new Node(val);
            if(head== NULL){
                head = tail = newNode;
                return ; 
            } else {
                newNode->next = head ;
                head-> prev = newNode ; 
                head = newNode ; 
            }

        }
         void push_back(int val){
            Node* newNode = new Node(val);
            if(head==NULL){
                head=tail = newNode ; 
                return ; 

            } else {
                 
                newNode->prev = tail ; 
                tail-> next  = newNode ; 
                tail = newNode ; 
            }
        }
        
        void pop_front(int val ){
           if(head==NULL){
            return ; 
           }
            Node* temp = head ;  // store the head to temp 
            head = head-> next ; //assign the head to next 

             if(head!=NULL){
                  head-> prev = NULL ; ; 
            }
          
            temp-> next = NULL ; //break the connection 
            delete temp ;

        }

        void pop_back(int val){
            if(head==NULL){
                return ;
            }
            Node* temp = tail ;
            tail = tail->prev ;

            if(tail!= NULL){ // if we have only single elm which pt to head & tail 
                 tail-> next = NULL ;

            }

           
            temp -> prev = NULL ;

            delete temp ;
        }
           void printLL(){
        Node* temp = head ; 
        while(temp!= NULL){
            cout << temp->data << ' ';
            temp = temp->next ; 
        }
        cout<< "NULL\n" ; 
      }
};



int main(){
    DoublyList dll ;

    dll.push_front(1);
     dll.push_front(2);
      dll.push_front(3);

      dll.printLL();
    return 0;
}