package Arrays;

import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("No. of elements in nums array=");
        int n = sc.nextInt();
        
        System.out.println("nums=");
        int nums[] = new int[n];
        //taking input of element of nums array
        for(int k=0; k<n; k++){
            nums[k]= sc.nextInt();
        }
        
        System.out.println("target=");
        //taking input of target
        int target = sc.nextInt();
        int sol[] = new int [2];
        //sol array will store indices of the two numbers of nums array such that they add up to target.
       
        for(int i=0; i<nums.length; i++){
            for(int j=0; j<nums.length; j++){
                if(i!=j && nums[i] + nums[j] == target){
                    sol[0] = i;
                    sol[1] = j;
                }
            }
        }
        System.out.println(Arrays.toString(sol));
        
    }
}