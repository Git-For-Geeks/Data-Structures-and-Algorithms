#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
ll* MaxSumSubArray(ll arr[],ll l, ll h);
ll* MaxCrossingSubArrray(ll arr[],ll l,ll mid,ll h);
//driver code
int main()
{
  //user input
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
 //function call
    ll* SubArr=MaxSumSubArray(arr,0,n-1);
    cout<<SubArr[2]<<endl;
    
  
}
//function to calculate maximum of left sum, right sum and cross sum subarray
ll* MaxSumSubArray(ll arr[],ll l, ll h)
{
    //when lower index is greater than higher index, return -infinity
    if(l>h){ 
        ll* RangeArr=new ll[3];
        RangeArr[2]=LLONG_MIN;
        RangeArr[0]=LLONG_MIN;
        RangeArr[1]=LLONG_MIN;
        return RangeArr;
    }
    //when lower index = higher index return value of lower/higher index
    if (l==h){
        ll* RangeArr=new ll[3];
        RangeArr[0]=l;
        RangeArr[1]=h;
        RangeArr[2]=arr[l];
        return RangeArr;
    }
    //when array contains more than one element, recursively call the function MaxSumSubArray 
    //to calculate leftsum and rightsum and for centre sum call MaxCrossingSubArrray
    else{
        ll mid=(l+h)/2;
        ll *La=MaxSumSubArray(arr,l,mid-1); //max sum of left subarray
        ll *Ra=MaxSumSubArray(arr,mid+1,h); //max sum of right subarray
        ll *Ca=MaxCrossingSubArrray(arr,l,mid,h); //max sum of crossing subarray
        //when leftsum is greater than rightsum and crossing sum return leftsum
        if (La[2]>Ca[2] && La[2]>Ra[2])
            return La;
             //when rightsum is greater than leftsum and crossing sum return rightsum
        else if(Ra[2]>Ca[2] && Ra[2]>La[2])
            return Ra;
            //else return centre crossing sum
        else
            return Ca;
    }
}
//function to calculate crossing sum
ll* MaxCrossingSubArrray(ll arr[],ll l,ll mid,ll h){
    ll *Ca=new ll[3];
    ll sum=0,leftsum=-LLONG_MAX,max_left=mid;
    //to calculate left part of the array
    //traverse from mid downto lower index
    for(ll i=mid;i>=l;i--){
        sum+=arr[i];
        if(sum > leftsum){
            leftsum=sum;
            max_left=i;
        }
    }

    sum=0;
    ll rightsum=-LLONG_MAX,max_right=mid+1;
    //to calculate right part of the array
    //traverse from mid upto higher index
    for(ll i=mid;i<=h;i++){
        sum+=arr[i];
        if(sum> rightsum){
            rightsum=sum;
            max_right=i;
        }
    }
        Ca[0]=max_left; //to store starting index of subarray
        Ca[1]=max_right; //to store ending index of subarray
        //in leftsum+rightsum, arr[mid] occurs twice so subtract once
        Ca[2]=max(leftsum+rightsum-arr[mid],max(leftsum,rightsum));
    return Ca;
}