
//Function to sort the array using bubble sort algorithm.
void bubbleSort(int arr[], int n)
{
    // Your code here    
        int i, j;
        //traverse the array upto the last second element
  for (i = 0; i < n - 1; i++)
    { 
      for (j = 0; j < n - i - 1; j++)
	{//when element at previous index is greater than element at next index
	  if (arr[j] > arr[j + 1])
	    {//swap those two elements
	      int temp = arr[j];
	      arr[j] = arr[j + 1];
	      arr[j + 1] = temp;
	    }
	}
    }

}