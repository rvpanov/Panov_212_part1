#include "DynamicArray.h"

void DynamicArray::print() const{
    for(size_t i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

DynamicArray::DynamicArray(size_t n){
    size = n;
    data = new int[size];

}

DynamicArray::~DynamicArray(){
    delete[] data;
    cout << "67";
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
