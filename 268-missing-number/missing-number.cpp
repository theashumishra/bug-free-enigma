class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum=(n*(n+1))/2;
        int arr_sum=0;
        for(int i=0; i<n; i++){
            arr_sum+=nums[i];
        }
        int ans = total_sum-arr_sum;
        return ans;
    } 
};