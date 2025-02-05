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

class List {
    private :
    Node* head ;
    Node* tail ; 

    public : 
    List(){
        head = tail = NULL ;
    };
        void push_front(int val){
            Node* newNode = new Node(val);
            if(head== NULL){
                head = tail = newNode;
                return ; 
            } else {
                newNode->next = head ;
                head = newNode ; 
            }

        }

        void push_back(int val){
            Node* newNode = new Node(val);
            if(head==NULL){
                head=tail = newNode ; 
                return ; 

            } else {
                newNode->next = tail ; 
                tail = newNode ; 
            }
        }

        void pop_front(int val ){
            if(head==NULL){
                return ; 
            }
            Node* temp = head ;  // store the head to temp 
            head = head-> next ; //assign the head to next 
            temp-> next = NULL ; //break the connection 
            delete temp ;

        }

        void pop_back(int val){
            if(head==NULL){
                return ; 
            }
            Node* temp = head ; 
            while (temp->next != tail ){
                temp = temp-> next ;

            }
            temp-> next = NULL ; 
            delete tail ; //delete the heap storage
            tail = temp ;
           
            

        }

        void insertM(int val , int pos){
            if(pos<0){
                return ; 
            }
            if(pos==0 ){
                push_front(val);
            }

            Node* temp = head ; 
            for(int i=0 ; i<pos-1 ; i++){ // for getting prev val 
                if(temp == NULL){
                    return ;
                }
                temp = temp-> next ;
            }
            Node* newNode = new Node(val); // create new node 
            newNode -> next = temp-> next; // build connection with next node
            temp -> next = newNode ;  // build connection with prev 

        }

        int search(int key){
            Node* temp = head ; 
            int idx=0 ; 

            while(temp != NULL){
                if(temp-> data == key){
                    return idx ; 
                }

                temp = temp-> next ; 
                idx++ ; 
            }
            return -1 ;
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

int main (){
    List ll ;

    ll.push_front(1);
     ll.push_front(2);
      ll.push_front(3);


      ll.printLL();
    return 0 ;
}
