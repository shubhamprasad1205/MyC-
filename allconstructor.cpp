#include<iostream>
using namespace std;

class intarray{
    int len;
    int *arr;

public:
    intarray(){
        cout << "\n default constructor";
        len = 5;
        arr = new int[len];
    }
    intarray(int l){
        cout << "\n para constructor";
        len = l;
        arr = new int[len];
    }
    ~intarray(){
        cout << "\n destructor called";
        delete []arr;
    }
    intarray(intarray &c){
        cout<<"\n copy constructor";
        len = c.len;
        arr = new int[len];
        for(int i=0; i<len; i++){
            arr[i] = c.arr[i];
        }
    }
    intarray(intarray &&c){
        cout<<"\n move constructor";
        len = c.len;
        arr = c.arr;

        c.len = 0;
        c.arr = nullptr;

    }
    intarray operator=(intarray &c){
        cout << " assignment operator";
        delete []arr;
        len = c.len;
        arr = new int[len];
        for(int i=0; i<len; i++){
            arr[i] = c.arr[i];
        }
        return *this;
    }
    void acceptArray(){
        for(int i=0; i<len; i++){
            cout << "\nEnter a number";
            cin >> arr[i];
        }
    }
    void display(){
        for(int i=0; i<len; i++){
            cout <<" "<<arr[i];
        }
    }
};

int main(){
    intarray obj1;
    obj1.acceptArray();

    intarray obj2(5);
    obj2.acceptArray();

    intarray obj3(obj2);

    intarray obj4 = move(obj1);

    cout<<"\nobj1 : ";
    obj1.display();
    cout<<"\nobj2: ";
    obj2.display();
    cout<<"\nobj3 : ";
    obj3.display();
    cout<<"\nobj4 : ";
    obj4.display();


}
