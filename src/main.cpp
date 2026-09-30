#include "DynamicArray.h"

int main(){
    DynamicArray arr(5);
    cout << "Test ex 1" << endl;
    cout << "Begin: ";
    arr.print();

    arr.set(0, 20);
    arr.set(1, 15);
    arr.set(2, 100);
    arr.set(3, -100);
    arr.set(4, 0);
    cout << "Last: ";
    arr.print();

    cout << "0: " << arr.get(0) << endl;
    cout << "1: " << arr.get(1) << endl;
    cout << "2: " << arr.get(2) << endl;
    cout << "3: " << arr.get(3) << endl;
    cout << "4: " << arr.get(4) << endl;

    try{
        arr.set(5, 20);
    } catch(exception& e){
        cout << e.what() << endl;
    }

    try{
        arr.set(3, 150);
    } catch(exception& e){
        cout << e.what() << endl;
    }

    try{
        arr.get(6);
    }catch(exception& e){
        cout << e.what() << endl;
    }
    cout << endl;
    cout << "Test ex 2" << endl << endl;
    DynamicArray arr1(5);
    arr1.set(0, 1);
    arr1.set(1, 2);
    arr1.set(2, 3);
    arr1.set(3, 4);
    arr1.set(4, 5);

    cout << "Begin arr1: ";
    arr1.print();

    DynamicArray arr2 = arr1;
    arr2.set(0, 6);
    cout << "arr2: ";
    arr2.print();

    cout << "Last arr1: ";
    arr1.print();

    cout << "Test ex 3" << endl << endl;
    DynamicArray arr3(3);
    arr3.set(0, 1);
    arr3.set(1, 2);
    arr3.set(2, 3);
    cout << "Begin: ";
    arr3.print();
    arr3.push_back(4);
    cout << "Last: ";
    arr3.print();

    cout << "3: " << arr3.get(3) << endl;

    try{
        arr3.push_back(200);
    }catch(exception& e){
        cout << e.what() << endl;
    }
    
    cout << "Test ex 4 Summ" << endl << endl;

    DynamicArray arrA(3);

    cout << "arrA Begin: ";
    arrA.set(0, 1);
    arrA.set(1, 2);
    arrA.set(2, 3);
    arrA.print();

    DynamicArray arrB(5);

    cout << "arrB Begin: ";
    arrB.set(0, 10);
    arrB.set(1, 20);
    arrB.set(2, 30);
    arrB.set(3, 40);
    arrB.set(4, 50);
    arrB.print();

    cout << "arrA Last: ";
    arrA.add(arrB);
    arrA.print();

     cout << "Test ex 4 Raznost" << endl;

    DynamicArray arrA2(5);

    cout << "arrA2 Begin: ";
    arrA2.set(0, 1);
    arrA2.set(1, 2);
    arrA2.set(2, 3);
    arrA2.set(3, 4);
    arrA2.set(4, 5);
    arrA2.print();

    DynamicArray arrB2(3);

    cout << "arrB2 Begin: ";
    arrB2.set(0, 10);
    arrB2.set(1, 20);
    arrB2.set(2, 30);
    arrB2.print();

    cout << "arrA2 Last: ";
    arrA2.sub(arrB2);
    arrA2.print();

    return 0;
}
