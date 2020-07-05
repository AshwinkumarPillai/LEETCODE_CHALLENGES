class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size() == 0 && right.size() == 0) return 0;
        int ans = 0;
        if(left.size()){
            int maxIndex = *max_element(left.begin(),left.end());
            ans = maxIndex;
        }
        if(right.size()){
            int maxIndex = *min_element(right.begin(),right.end());
            ans = max(ans,n-maxIndex);
        }
        return ans;
    }
};