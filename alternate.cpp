#include<iostream>
#include<vector>
using namespace std;
void posneg(int a[],int n){
    vector<int> pos, neg;
    for(int i=0;i<n;i++){
        if(a[i]>0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }
    int i=0,p=0,q=0;
    for(int i=0;i<n;i++){
    while(p<pos.size() && q<neg.size()){
        if(i&2==0)
            a[i++]=pos[p++];
        else
            a[i++]=neg[q++];

        }
    }
    while(p<pos.size()) 
    a[i++]=pos[p++];
    while(q<neg.size()) 
    a[i++]=neg[q++];


}
int main(){
    int a[10],n;
    cout<<"Enter the number elements in array:";
    cin>>n;
    cout<<"Enter the array:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    posneg(a,n);

    cout<<"Array after moving zeros to the end:"<<endl;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
return 0;
}