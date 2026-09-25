#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

class DynamicArray{
private:
    int* data;
    size_t size;
public:
    void print() const; 
    DynamicArray(size_t n);
    ~DynamicArray();
    void set(size_t index, int value);
    int get(size_t index) const;
};
