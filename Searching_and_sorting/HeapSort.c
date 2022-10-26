
//firstly we will build a max heap
void heapify(int arr[], int n, int i)
{
    // Find largest among parent, left child and right child
 
    // Initializing largest as parent
    int largest = i;  
    int l = 2 * i ;  //left = 2*i   
    int r = 2 * i + 1;  //right = 2 * i + 1
    //when left index is less than equal to n 
    // and left child is greater than ele at largest index
   if(l<n && arr[l] > arr[largest]) 
        {largest = l;}  //largest = left;
 
    //when right index is less than equal to n 
    //and right child is greater than largest
  
   if(r<n && arr[r] > arr[largest]) 
       { largest = r;}  //largest = right;
 
    // if parent  is not largest
    //then swap and continue heapify
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursive call to  heapify 
        heapify(arr, n, largest);
    }
}
 

//then after every insertion we will check for max heap property
 void buildHeap(int arr[], int n)
{
 
    // Building max heap
    for (int i = n / 2 - 1; i >= 0; i--)
 
        heapify(arr, n, i);
 
    // delete element 
    for (int i = n-1  ; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // again heapify parent element to obtain highest element at root again
        heapify(arr, i, 0);
    }
}

