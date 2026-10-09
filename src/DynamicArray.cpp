#include "DynamicArray.h"

void DynamicArray::print() const{
    for(size_t i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl << endl;
}

DynamicArray::DynamicArray(size_t n){
    size = n;
    capacity = n;
    data = new int[size];

}

DynamicArray::~DynamicArray(){
    delete[] data;
    cout << "67.";
}

void DynamicArray::set(size_t index, int value){
    if(index >= size){
        throw out_of_range("Index Error!");
    }

    if(value < -100 || value > 100){
        throw invalid_argument("Value Error!");
    }

    data[index] = value;
}

int DynamicArray::get(size_t index) const{
    if(index >= size){
        throw out_of_range("Index Error!");
    }
    return data[index];
}

DynamicArray::DynamicArray(const DynamicArray& other){
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

void DynamicArray::push_back(int value){
    if(value < -100 || value > 100){
        throw invalid_argument("Value Error!");
    }
    if(size == capacity){
        capacity = capacity*2;
        if(capacity == 0){
            capacity = 1;
        }
    int* new_data = new int[capacity]();
    for(size_t i = 0; i < size; i++){
        new_data[i] = data[i];
        }
    delete[] data;
    data = new_data;
    }
    data[size] = value;
    size++;
}

void DynamicArray::add(const DynamicArray& other){
    size_t limit;
    if(size <= other.size){
        limit = size;
    }else{
        limit = other.size;
    }

    for(size_t i = 0; i < limit; i++){
        data[i] += other.data[i];
    }
}

void DynamicArray::sub(const DynamicArray& other){
    size_t limit;
    if(size <= other.size){
        limit = size;
    }else{
        limit = other.size;
    }

    for(size_t i = 0; i < limit; i++){
        data[i] -= other.data[i];
    }
}
