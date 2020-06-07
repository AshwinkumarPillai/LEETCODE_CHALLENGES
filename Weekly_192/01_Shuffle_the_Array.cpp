class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i =0,j=n;
        vector<int>ans;
        int lim = nums.size();
        while(j<lim){
            ans.emplace_back(nums[i++]);
            ans.emplace_back(nums[j++]);
        }
        return ans;
    }
};