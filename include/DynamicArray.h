#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include<type_traits>

using namespace std;

template <typename T>

class DynamicArray{
private:
    T* data;
    size_t size;
    size_t capacity
public:
    DynamicArray(size_t n) : size(n), capacity(n){ 
    data = new T[capacity]();
    }

    ~DynamicArray(){
        delete[] data;
        cout << "67.";
    }

    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity){
        data = new T[capacity]();
        for(size_t i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }

    void set(size_t index, T value){
        if(index >= size){
            throw out_of_range("Index Error!");
        }
        if constexpr (is_integral_v<T>){
            if(value < -100 || value > 100){
                throw invalid_argument("Value Error!");
            }
        }
        data[index] = value;
    }

    T get(size_t index){
        if(index >= size){
            throw out_of_range("Index Error!");
        }
        return data[index];
    }

    void push_back(T value) {
        if constexpr (is_integral_v<T>) {
            if (value < -100 || value > 100) {
                throw invalid_argument("Value Error!");
            }
        }
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* new_data = new T[capacity]();  
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        
        data[size] = value;
        size++;
    }

    void add(const DynamicArray& other){
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
    
    void sub(const DynamicArray& other){
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

    double distance(const DynamicArray& other){
        if(size != other.size){
            throw invalid_argument("Size Error!");
        }

        if constexpr(is_arithmetic_v<T>){
            double sum = 0.0;
            for(size_t i = 0; i < size; i++){
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff*diff;
            }
            return sqrt(sum);
        }else{
            throw bad_typeid();
        }
    }
    
    friend ostream& operator<<(ostream& os, DynamicArray& arr){
        for(size_t i = 0; i < arr.size; i++){
            os << arr.data[i] << " ";
        }
        return os;
    }
};
