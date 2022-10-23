#include <iostream>

using namespace std;

int main()
{
     void selectionSort(int arr[], int n)
    {
      
       for(int i=0;i<n;i++){
           int mini=i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<arr[mini]) mini=j;
           }
           swap(arr[i],arr[mini]);
       }

    return 0;
}