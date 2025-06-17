#include <bits/stdc++.h>
using namespace std;


class SinglyLinkedList{
    private:
        class Node
        {
        public:
            int data ;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
    Node* head;
    Node* tail;
    int size;


    public:
        SinglyLinkedList() : head(nullptr) ,tail(nullptr) ,size(0){}; // constructor
    
        ~SinglyLinkedList(){ // destructor
            Node* current = head;

            while(current != nullptr){
                Node* next = current -> next;
                delete current;
                current = next;
            }
            head = tail = nullptr;
        }

        void insert_at_head(int value){
            Node* newNode = new Node(value);

            newNode -> next = head;
            head = newNode;

            if (tail == nullptr){ // This means that linked list is empty.
                tail =  head;
            }
            size++;
            
        }
        // In a correctly implemented singly linked list 
        // with both head and tail pointers, the tail pointer should never be nullptr if the list is not empty

        void display(){
            Node* temp = head;
            while(temp != nullptr){
                cout << (temp -> data) <<" ";
                // we shouldn't do the head = head -> next as it will change real head
                // that's why we use temp = head instead make a temp variable
                temp = temp -> next;
            }
        }
        void insert_at_end(int value){
            Node* newNode = new Node(value);
            if( tail == nullptr){
                head = tail  = newNode; // means if teh list is empty 
            }
            tail -> next = newNode;
            // tail should be always in the last node so 

            tail = newNode;
            size++;

        }

        void insert_at_indx(int idx , int val){
            Node* newNode = new Node(val);

            int count = 0;
            if (idx < 0 || idx > size) {
            return; // or throw an exception, or handle as you prefer
            }


            if(idx ==0){
                insert_at_head(val);
                return;
            }
            if(idx == size){
                insert_at_end(val);
                return;
            }
            Node* temp = head;
            while(count < idx-1){
                temp = temp -> next;
                count++;
            }
            // by this loop we will go one index before that loop on which we have to insert.

            Node* temp2 = temp -> next;
            temp -> next = newNode;
            newNode -> next = temp2;

        }

        int  delete_at_head(){
        if (head == nullptr) {
            throw std::runtime_error("List is empty");
            }

            int val = head->data;
            Node* temp  = head;
            head = head -> next;

          
            delete temp;

            size --;
            return val;
        }

int delete_at_last() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    int val = tail->data;
    if (head == tail) { // Only one node
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    size--; // Assuming you have a size member
    return val;
}

int delete_At_index(int index){
    Node* temp = head;
    for(int i = 1; i< index ; i++){
        temp = temp -> next;
    }

    if (index < 0) {
        throw std::runtime_error("Negative index not allowed");
    }

    if(index ==0){
        delete_at_head();
    }

    int valt = temp -> next -> data;
    Node* newt = temp -> next;
    temp-> next = temp -> next -> next;
    delete newt;

    size --;
    return valt;

}
};

class DoublyLinkedList{
    private:
        class Node{
            public:
                int data;
                Node* next;
                Node* prev;
                Node(int val) : data(val), next(nullptr),prev{nullptr} {};
        };
    Node* head;
    Node* tail;
    int size;

    public:
   
    DoublyLinkedList() : head(nullptr) ,tail(nullptr) ,size(0){}; // constructor
    
    ~DoublyLinkedList() { // destructor
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    }

    void insert_value_at_head( int value){
       
        Node* new_node = new Node(value);
        new_node ->next = head;
        new_node -> prev = nullptr;
        if( head  != nullptr){
            head -> prev = new_node;
        }
        else{
            tail = new_node;
        }
        head = new_node;
        size++;
    }



    void display(){
        Node* temp = head;
        
        while( temp != nullptr){
            cout << temp -> data << " ";
            temp = temp  -> next;
        }
        cout << endl;
    }

    void insert_at_last(int value){
        Node* new_node =  new Node(value);
        Node* last = head;

        if( head == nullptr){
            new_node -> prev  = nullptr;
            head = new_node;
            
        
        }
        else{
        
        while(last -> next != nullptr){
            last  = last -> next;
        }

        last -> next = new_node;
        new_node -> prev = last;
    }
    size++;
    }

    void insertion_at_index(int val , int index){
        if(index == 0 ){
            insert_value_at_head(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp  = head;
        for(int i = 0; i< index ; i++){
            temp = temp -> next;
        }

        Node* temp2 = temp -> next;
        temp -> next = newNode;
        newNode -> prev = temp;
        newNode -> next = temp2;

        if(temp2) temp2 -> prev = newNode;
        size++;
    }

};

// One thing in circular linked list is we only want to do something in 
// in only one cycle so it is better to use the do while loop 
// as it will do atlest one time
class   CircularLinkedList{
    private:
        class Node
        {
        public:
            int data ;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };
    Node* head;
    Node* tail;
    int size;

    public:
        CircularLinkedList() : head(nullptr) ,tail(nullptr) ,size(0){}; // constructor
    
        ~CircularLinkedList(){ // destructor
            Node* current = head;

            do{
                Node* next = current -> next;
                delete current;
                current = next;
            }
            while(current != head);
            head = tail = nullptr;
        }

    void insert_at_tail( int val){

        Node* node = new Node(val);

        if ( head == nullptr){
            head = node ;
            tail = node;
            return;
        }

        tail -> next = node;
        node -> next = head;
        tail = node;
        size++;
    }

    void display() {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
    }

   
};