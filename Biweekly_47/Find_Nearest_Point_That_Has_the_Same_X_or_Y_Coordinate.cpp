class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1,manhat=INT_MAX,i=0;
        for(auto v:points){
            if((v[0] == x )|| (v[1] == y)){
                int mht = abs(v[0] - x) + abs(v[1] - y);
                if(mht < manhat){
                    manhat = mht;
                    ans = i;
                }
            }
            i++;
        }
        return ans;
    }
};
