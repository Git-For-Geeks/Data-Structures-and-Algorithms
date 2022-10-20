#include<bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n; int arr[n];

    int count = 0;

    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n; i++){

        if(arr[i] != -1){

                int temp = arr[i];
                count ++;

                for(int j= i+1; j<n; j++){

                    if(arr[j]% temp == 0){
                        arr[j] = -1;
                        }
                }

            
        }
    }

    cout << count << endl;



    return 0;
}

/*                  *** Explanation ***
 * Sort the array in increasing order
 * Iterate through 0 to n-1 and mark all multiple of arr[i] to -1 
 *          because now we can paint all that multiple with one color 
 *
 * And if arr[i] != -1 then we can say that arr[i] is not a multiple of any number present on left side 
 *          then we make count++
 *
 * Now we print count
 *
 *
 */
