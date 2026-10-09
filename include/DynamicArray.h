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
public:
    DynamicArray(size_t n) : size(n){ 
    data = new T[size]();
    }

    ~DynamicArray(){
        delete[] data;
        cout << "67.";
    }

    DynamicArray(const DynamicArray& other) : size(other.size){
        data = new T[size]();
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

    void push_back(T value){
        if constexpr(is_integral_v<T>){
            if(value < -100 || value > 100){
                throw invalid_argument("Value Error!");
            }
        }
        size_t new_size = size + 1;
        T* new_data = new T[new_size];
        for(size_t i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        new_data[size] = value;
        size = new_size;
        delete[] data;
        data = new_data;
        size = new_size;
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
