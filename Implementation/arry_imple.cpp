#include <bits/stdc++.h>
using namespace std;

class dynamic_arr{
    private:
        int* arr;
        int capacity;
        int size;
    
    void resize(int new_capacity){
        int* temp = new int[new_capacity];

        for(int i =0; i < size ; i++ ){
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        capacity = new_capacity;
    }   

    public:
        dynamic_arr(int initial_capacity = 2) {
        arr = new int[initial_capacity];
        capacity = initial_capacity;
        size = 0;
    }

    ~dynamic_arr() {
    delete[] arr;
    }

    void PushBack(int value){
        if(size == capacity){
            capacity = capacity * 2;
            resize(capacity);
        }

        arr[size++] = value;
    }

    int get(int index){
        if( index < 0 || index >= size){
            cout <<"Index Out of range";
        }
        return arr[index];
    }

    int size(){
        return size;
    }
};