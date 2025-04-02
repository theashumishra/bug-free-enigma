class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                long long maxi = 0;  // reset maxi for each j
                for (int k = j + 1; k < n; k++){
                    maxi = max(maxi, (long long)(nums[i] - nums[j]) * nums[k]);
                }
                ans = max(ans, maxi);
            }
        }
        return ans;
    }
};
