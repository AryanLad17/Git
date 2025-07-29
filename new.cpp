#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int *a=new int[n];
    
    for(int i=0;i<n;i++){
        cout<<"Enter the grade of student"<<i+1<<":";
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
       
        cout<<*a<<" ";
    }
    cout<<endl;
    delete[] a;
}