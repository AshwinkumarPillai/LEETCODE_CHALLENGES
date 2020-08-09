class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        map<int,int>prefix;
        prefix[0] = -1;
        int sum = 0,right = -1,count=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(prefix.find(sum-target) != prefix.end()){
                int left = prefix[sum-target];
                if(right<=left){
                    count++;
                    right =i;
                }
            }
            prefix[sum] = i;
        }
        return count;
    }
};
