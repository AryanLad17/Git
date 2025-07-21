#include<iostream>
using namespace std;
void zero(int a[],int n){
 int nonzero=n-1;
 for(int i=0;i<n;i++){
    if(a[i]==0){
        swap(a[i],a[nonzero]);
        nonzero--;
    }
 }
}
int main(){
    int a[10],n;
    cout<<"Enter the number elements in array:";
    cin>>n;
    cout<<"Enter the array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    zero(a,n);

    cout<<"Array after moving zeros to the end:"<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
return 0;
}