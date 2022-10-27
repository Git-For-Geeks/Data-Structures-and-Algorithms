//this function finds maximum element of array
int getMax(int a[], int n) {
  int max = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];
  return max;
}
void countSort(int a[], int n,int pos){
      int b[n];
  int max = (a[0] / pos) % 10;

  for (int i = 1; i < n; i++) {
    if (((a[i] / pos) % 10) > max)
      max = a[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;
    //find count of all elements present in array
    for(int i=0;i<n;i++)
    ++count[(a[i]/pos)%10];
    //cumulative count array to get actual positions of elements
    for(int i=1;i<=10;i++)
    count[i]+=count[i-1];
    //updating b array using count array
    //this array is now sorted
    for(int i=n-1;i>=0;i--)
    b[--count[(a[i]/pos)%10]]=a[i];
    //copying b array into a array
    for(int i=0;i<n;i++)
    a[i]=b[i];


}
void radixSort(int a[], int n) 
{ 
     //obtain max element
    int max = getMax(a,n);
    int pos;
    //sort elements on basis of place value 
    //use counting sort
    for(pos=1;max/pos>0;pos*=10){
        countSort(a,n,pos);
    }
} 