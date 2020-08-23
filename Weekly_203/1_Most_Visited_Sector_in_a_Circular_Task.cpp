class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int>ans;
        vector<int>freq(n+1);
        int N = rounds.size();
        for(int i=0;i<N-1;i++){
            if(rounds[i] < rounds[i+1]){
                for(int j = rounds[i];j<rounds[i+1];j++) freq[j]++;
            }else{
                for(int j = rounds[i];j<=n;j++) freq[j]++;
                for(int j = 1; j<rounds[i+1];j++) freq[j]++;
            }
        }
        freq[rounds[N-1]]++;
        int maxval = 0;
        unordered_map<int,vector<int>>m;
        for(int i=1;i<=n;i++){
            m[freq[i]].push_back(i);
            maxval = max(maxval,freq[i]);
        }
        ans = m[maxval];
        return ans;
    }
};
