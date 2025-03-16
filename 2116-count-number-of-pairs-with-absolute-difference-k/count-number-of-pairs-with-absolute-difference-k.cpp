class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        //for(auto it: nums) mpp[it]++;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            int ans1 = nums[i]-k;
            int ans2 = nums[i]+k;
            mpp[nums[i]]++;
            if(mpp.find(ans1)!=mpp.end() || mpp.find(ans2)!=mpp.end()) 
                cnt+=mpp[ans1]+mpp[ans2];
            /////\/\/\/\ else if() cnt++;
             
        } return cnt;
    }
};