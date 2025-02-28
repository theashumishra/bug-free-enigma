#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        if (left == -1) return {-1, -1};
        int right = findRight(nums, target);
        return {left, right};
    }
    
private:
    int findLeft(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int left = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                left = mid;
                high = mid - 1; // Continue searching left for earlier occurrence
            }
        }
        return left;
    }
    
    int findRight(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int right = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                right = mid;
                low = mid + 1; // Continue searching right for later occurrence
            }
        }
        return right;
    }
};