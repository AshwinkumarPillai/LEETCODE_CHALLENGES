class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n = p.size();
        vector<int>ans;
        int flag = 0;
        for(int i = 0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(p[i] >= p[j]){
                    flag = 1;
                    ans.emplace_back(p[i] - p[j]);
                    break;
                }
            }
            if(flag == 0){
                ans.emplace_back(p[i]);
            }else{
                flag = 0;
            }
        }
        return ans;
    }
};