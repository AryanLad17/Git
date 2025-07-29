#include<iostream>
using namespace std;
void most(int a[],int n){
 


}
int main(){
    int a[100],n;
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"Enter the elements :";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    most(a,n);
   
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}