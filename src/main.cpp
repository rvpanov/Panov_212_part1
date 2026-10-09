#include "DynamicArray.h"
#include <new>
#include<string>

int main(){
    cout << "PART 3" << endl << endl;

    cout << "INT" << endl << endl;

    DynamicArray<int> arrInt(3);
    arrInt.set(0, 1);
    arrInt.set(1, 2);
    arrInt.set(2, 3);

    cout << arrInt << endl;

    try{
        arrInt.set(0, 150);
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }

    DynamicArray<int> arrInt2(3);
    arrInt2.set(0, 4);
    arrInt2.set(1, 5);
    arrInt2.set(2, 6);

    cout  << "distance: " << arrInt.distance(arrInt2) << endl << endl;

    cout << "STRING" << endl << endl;

    DynamicArray<string> arrStr(2);
    arrStr.set(0, "Hello");
    arrStr.set(1, "World");

    cout << arrStr << endl;

    DynamicArray<string> arrStr2(2);

    try{
        double d = arrStr.distance(arrStr2);
        cout << d;
    }catch(const bad_typeid& e){
        cout << e.what() << endl;
    }

    DynamicArray<int> arrInt3(2);

    arrInt3.set(0, 1);
    arrInt3.set(1, 2);

    try{
        double d = arrInt.distance(arrInt3);
        cout << d;
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }

    return 0;
}
