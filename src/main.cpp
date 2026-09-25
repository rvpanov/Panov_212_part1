#include "DynamicArray.h"

int main(){
    DynamicArray arr(5);
    cout << "Begin: ";
    arr.print();

    arr.set(0, 20);
    arr.set(1, 15);
    arr.set(2, 100);
    arr.set(3, -100);
    arr.set(4, 0);
    cout << "Last: ";
    arr.print();
    cout << endl;

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
    
    return 0;
}
