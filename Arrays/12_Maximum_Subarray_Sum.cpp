#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int* MaxSumSubArray(int arr[],int l, int h);
int* MaxCrossingSubArrray(int arr[],int l,int mid,int h);
int main()
{

   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    int* SubArr=MaxSumSubArray(arr,0,n-1);

    cout<<SubArr[2]<<endl;
   
}

int* MaxSumSubArray(int arr[],int l, int h){
    if (l==h){
        int* RangeArr=new int[3];
        RangeArr[0]=l;
        RangeArr[1]=h;
        RangeArr[2]=arr[l];
        return RangeArr;
    }
    else{
        int mid=(l+h)/2;
        int *La=MaxSumSubArray(arr,l,mid);
        int *Ra=MaxSumSubArray(arr,mid+1,h);
        int *Ca=MaxCrossingSubArrray(arr,l,mid,h);
        if (La[2]>Ca[2] && La[2]>Ra[2])
            return La;
        else if(Ra[2]>Ca[2] && Ra[2]>La[2])
            return Ra;
        else
            return Ca;
    }
}

int* MaxCrossingSubArrray(int arr[],int l,int mid,int h){
    int *Ca=new int[3];
    int sum=0,leftsum=-INT_MAX,max_left=mid;
    for(int i=mid;i>=l;i--){
        sum+=arr[i];
        if(sum > leftsum){
            leftsum=sum;
            max_left=i;
        }
    }

    sum=0;
    int rightsum=-INT_MAX,max_right=mid+1;
    for(int i=mid+1;i<=h;i++){
        sum+=arr[i];
        if(sum> rightsum){
            rightsum=sum;
            max_right=i;
        }
    }
        Ca[0]=max_left;
        Ca[1]=max_right;
        Ca[2]=leftsum+rightsum;
    return Ca;
}