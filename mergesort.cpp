#include <iostream>
#include <cstdlib>

using namespace std;
void merge(int a[],int start, int end ,int mid ){
    int len1=mid -start+1;
    int len2=end-mid;
    int* left=new int[len1];
    int* right= new int[len2];
    for(int i=0;i<len1;i++){
        left[i]=a[start+i];
        for(int j=0;j<len2;j++){
            right[j]=a[mid+1+j];
        }
    }
    int i=0,j=0,k=start;
    while(i<len1 && j<len2){
        if(left[i]<right[j]){
            a[k++]=left[i++];
        }
        else if(right[j]<left[i]){
                a[k++]=right[j++];
        }
        else{
            a[k++]=left[i++];
            a[k++]=right[j++];
        }
    }
    while(i<len1){
        a[k++]=left[i++];
    }
    while(j<len2){
        a[k++]=right[j++];
    }
    // Free memory for left and right arrays
    delete[] left;
    delete[] right;
}

void mergesort(int a[], int start, int end){
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(a, start, mid);      // Left half
        mergesort(a, mid + 1, end);    // Right half
        merge(a, start, end, mid);     // Merge them
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