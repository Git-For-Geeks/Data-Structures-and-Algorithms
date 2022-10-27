#include <bits/stdc++.h>
using namespace std;
 
// Function to find the NGE
void printNGE(int A[], int n)
{
    // Formation of circular array
    int arr[2 * n];
    // Append the given array element twice
    for (int i = 0; i < 2 * n; i++)
        arr[i] = A[i % n];
    int next, i, j;
    // Iterate for all the elements of the array
    for (i = 0; i < n; i++) {
        // Initialise NGE as -1
        next = -1;
        for (j = i + 1; j < 2 * n; j++) {
            // Checking for next greater element
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        // Print the updated NGE
        cout << next << ", ";
    }
}
 
// Driver Code
int main()
{
    // Given array arr[]
    int arr[] = { 1, 2, 1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    // Function call
    printNGE(arr, N);
    return 0;
}