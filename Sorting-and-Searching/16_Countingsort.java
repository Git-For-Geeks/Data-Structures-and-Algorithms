//{ Driver Code Starts
    import java.util.*;
    import java.lang.*;
    
    class CountSort
    {
        public static void main (String[] args) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            
            while(t-- > 0)
            {
                long n = sc.nextLong();
                String arr = "";
                arr = sc.next();
                Solution obj = new Solution();
                System.out.println(obj.countSort(arr));
            }
        }
    }
    
    // } Driver Code Ends
    
    
    class Solution
    {
        //Function to arrange all letters of a string in lexicographical 
        //order using Counting Sort.
        public static String countSort(String arr)
        {
            // code here
            
            //First we will convert string to array, so that it can apply Arrays.sort method
            char[]ch = arr.toCharArray();

            //Applying Arrays.sort method
            Arrays.sort(ch);
            //Now array of string is sorted and stored in ch array
            
            //return String by converting array of ch to string
            return new String(ch);
            
            
        }
    }
