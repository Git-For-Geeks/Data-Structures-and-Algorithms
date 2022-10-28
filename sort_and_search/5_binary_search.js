class Solution {
    binarysearch(arr, n, k) {
        let begin = 0;
        let last = n - 1;
        
        while( begin <= last ){
            let middle = Math.floor((begin + last) / 2);
            
            if(arr[middle] == k){
                return middle;  //key is found
            }
            else if(arr[middle] < k){
                begin = middle + 1;
            }
            else {
                last = middle - 1;
            }
        }
        return -1;
    }
}