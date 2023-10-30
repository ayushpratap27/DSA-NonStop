#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=18;
    float y=7.9;
    //Create a pointer that can store address of x
    // As x is an integer variable, so we need a pointer
    // that can store address of integer type

    int *ptr=&x;
    cout<<"Address stored inside ptr: "<<ptr<<endl;
    cout<<"Value present at the address stored in ptr: "<<*ptr<<endl; //deference

    //Create a pointer that can store address of y
    // y is a float variable, so we need to store it in a
    // float pointer
    float *ptrf= &y;
    cout<<"Address stored inside ptrf: "<<ptrf<<endl;
    cout<<"Value present at the address stored in ptrf: "<<*ptrf<<endl;

    x=23; // The bucket x updated the value from 18-->23
    // But ptr is still pointing to same bucket
    // now if we dereference ptr, we will get 23

    cout<<"New updated value of x "<<x<<endl;
    cout<<"New value pointed by ptr "<<*ptr<<endl;

    int valueAtX= *ptr;
    cout<<valueAtX<<endl;

    return 0;
}