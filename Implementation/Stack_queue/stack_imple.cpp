#include <bits/stdc++.h>
using namespace std;


class Stack_by_arr {
private:
    int* arr;
    int topIndex; // need to track the top of the stack everytime
    int capacity;

    void resize( int newCapacity){
        int* newarr = new int[newCapacity]; // make a new array of that size

        for( int i= 0; i<=topIndex ; i++){ // copy previous array element to the new array
            newarr[i] = arr[i];
        } 
        delete[] arr;
        arr = newarr;
        capacity = newCapacity;
    }

    public:
        Stack_by_arr(int size = 2 ) : capacity(size) , topIndex(-1){
            arr = new int[capacity];
        };

        ~Stack_by_arr(){
            delete[] arr;
        }

        bool isFull(){
            return topIndex == capacity -1;
        }

        bool isEmpty(){
            return topIndex == -1;
        }

        int size(){
            return topIndex+1;
        }

        void push( int val){
            if(isFull()){
                resize(capacity * 2);
            }
            arr[++topIndex] = val;
        }


        int  top(){
            if(isEmpty()){
                throw runtime_error("Stack is empty");
            }
            return arr[topIndex];
        }

        int pop(){
            if(isEmpty()){
                throw runtime_error("Stack UnderFlow");
            }
            return arr[topIndex--];
        }



};


class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack_by_LL {
private:
    Node* top; // Points to the top of the stack
    int stackSize;

public:
    Stack_by_LL() : top(nullptr), stackSize(0) {}

    ~Stack_by_LL(){
        while(!isEmpty()){
            pop();
        }
    }

    bool isEmpty(){
        return top == nullptr;
    }

    int pop(){
         if (isEmpty()) {
            throw std::runtime_error("Stack Underflow");
        }

        Node* temp = top;

        int val = temp -> data;
        top = top -> next; // Think like top is head and everytime new element is added in head.
        delete temp;
        stackSize--;
        return val;
        
    }

    void push(int val){
        Node* temp = new Node(val);
       
        temp -> next = top;
        top = temp;
        stackSize++;
    }

    int peek(){
        if( isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        return top -> data;
    }

};