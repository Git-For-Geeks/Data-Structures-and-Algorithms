class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   

            
        vector<int> nums;                           //variable declaration
        for(int i=0; i<nums1.size(); i++)
            nums.push_back(nums1[i]);               //creation of array1
        
        for(int i=0; i<nums2.size(); i++) 
            nums.push_back(nums2[i]);                //creation of array2
        
        sort(nums.begin(), nums.end());             //sorting of the array
        
        int mid = nums.size()/2;                    // finding medain
        double ans;
        
        if(nums.size()%2 == 0) ans = double(nums[mid] + nums[mid - 1])/2; //answer
        else ans = nums[mid];
        
        return ans;
        
    }
          
};