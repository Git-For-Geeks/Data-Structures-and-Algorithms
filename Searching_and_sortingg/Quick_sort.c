int partition(int a[],int lb,int ub){
    int pivot = a[lb]; //starting/lowerbound index element as pivot
    int start = lb; //assigning lowerbound to start
    int end = ub;   ////assigning upperbound to end
    while(start<end){
        // element at start is less than/equal to pivot increment start
        while(a[start]<=pivot){start++;}
        //element at end is greater than pivot so decrement end
        while(a[end]>pivot){end--;}
        //when start is less than end swap elements at start and end
        if(start<end){
            //swap(a[start],a[end]);
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            }
    }

    //while start is not less than end
    //swap(a[lb],a[end])
            int temp1 = a[lb];
            a[lb] = a[end];
            a[end] = temp1;

            return end;
}

void Quicksort(int a[],int lb,int ub){
    //when elements are present in array
    if(lb<ub){
        // store result of partition function in pos  
        int pos = partition(a,lb,ub);
        //recursively apply quicksort to the sub-arrays
        Quicksort(a,lb,pos-1);
        Quicksort(a,pos+1,ub);
    }
    //empty array
    if(lb>=ub){return;}
}
