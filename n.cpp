#include<iostream>
using namespace std;
int main(){
   int val,*ptr1,**ptr2;
   val=5;
   ptr1=&val;
   ptr2=&ptr1;
   cout<<val<<" "<<*ptr1<<" "<<**ptr2<<endl;
    cout<<&val<<" "<<ptr1<<" "<<*ptr2<<endl;
    return 0;
}