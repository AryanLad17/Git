#include<iostream>
using namespace std;
void merge(int a[],int start,int end){
    int n=end-start+1;
    if(n==1) return; // No need to merge if only one element
    int mid=(start+end)/2;
     int len1=mid -start+1;
    int len2=end-mid;
    int* leftarray=new int[len1];
    int* rightarray=new int[len2];
    int i=0;
    int j=0;
    for(;i<n;i++){
        if(i<mid){
        leftarray[i]=a[start+i];
        }
        else{
        rightarray[j]=a[mid+1+  j];
        j++;}
    }
   
    while(i<len1 && j<len2){
        if(leftarray[i]<rightarray[j]){
            a[start++]=leftarray[i++];
            
        }
        else if(rightarray[j]<leftarray[i]){
            a[start++]=rightarray[j++];

        }
        else{
            a[start++]=leftarray[i++];
              a[start++]=rightarray[j++];
        }
    }
    while(i<len1){
        a[start++]=leftarray[i++];
    }
    while(j<len2){
        a[start++]=rightarray[j++];
    }
}
void mergesort(int a[],int start,int end){
    int mid=(start+end)/2;
    if(start<end){
        mergesort(a,start,mid);  // Left half
        mergesort(a,mid+1,end);  // Right half
        merge(a,start,end);

    }
}
int main(){
    int a[100],n;
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"Enter the elements :";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"Sorted array is :";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}