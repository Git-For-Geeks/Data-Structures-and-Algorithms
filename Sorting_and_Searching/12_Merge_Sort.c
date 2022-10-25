// C program for Merge Sort 
#include <stdio.h>
#include <stdlib.h>


//function to merge two subarrays 
//left subarray is a[lb....mid]
//right subarray is b[mid+1....ub]

void merge(int a[], int lb, int mid, int ub)
{ int i=lb; //i=lowerbound
int j=mid+1;  
int k=lb;
int b[ub]; //a temp array having same size as array a
//traverse the left and right subarrays till they have elements in them
while(i<=mid && j<=ub)
{//compare elements
    if(a[i]<=a[j]){
        //put them in b array
        b[k]=a[i];
        i++;
    }
    else{
        b[k]=a[j];
        j++;
    }
    k++;
}
//left subarray has been traversed and now empty
if(i>mid){
    //check if right subarray has elements
    while(j<=ub){
        //if it has elements than put them in b array

        b[k]=a[j];
        j++;
        k++;
    }
}
else
//when right subarray is empty
{  //check if elements present in left subarray
    while(i<=mid){
        //if it has elements than put them in b array
        b[k]=a[i];
        i++;
        k++;
    }
}
//finally copy the b array into a array
for(k=lb;k<=ub;k++){
    a[k]=b[k];
   // printf("%d ",a[k]);
    ;
}
}
// lb is lowerbound which is for left index and ub is upperbound which is for 
//right index of the sub-array of arr to be sorted 

void mergeSort(int array[],int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);
        merge(array,lb,mid,ub);
    }
}
