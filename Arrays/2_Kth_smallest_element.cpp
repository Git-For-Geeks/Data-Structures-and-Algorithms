class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        // Here we are using a priority queue in which we push all the array elements .
        // To be precosed we are using the heap property of the priority queuue and the no would be sorted accordingly and the highest value would be at the top and the lowest element would be at the bottom of the priority queue F
        priority_queue<int> q;
        // We use the for loop which starts from beginning of the array upto the end of the array
        for (int i = l; i <= r; i++)
        {
            // We push all the array elements in the priority queue
            q.push(arr[i]);
            // In this if condition we ae cheking whether the size of the priority queue is greater thena the required kth smallest element then we will simple pop out until we reach to the k th element
            if (q.size() > k)
            { // We are popping out the element from the priority queue
                q.pop();
            }
        }
        // Here we return the top that is the kth smallest element as our answer.
        return q.top();
    }
};