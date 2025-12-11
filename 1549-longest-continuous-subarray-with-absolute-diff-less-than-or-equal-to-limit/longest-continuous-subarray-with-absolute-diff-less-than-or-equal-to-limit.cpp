#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int >maxii;
        deque<int>mini;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!maxii.empty() && nums[right] > maxii.back())
                maxii.pop_back();
            maxii.push_back(nums[right]);

            while (!mini.empty() && nums[right] < mini.back())
                mini.pop_back();
            mini.push_back(nums[right]);

            
            while (maxii.front() - mini.front() > limit) {
                if (maxii.front() == nums[left]) maxii.pop_front();
                if (mini.front() == nums[left]) mini.pop_front();
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};