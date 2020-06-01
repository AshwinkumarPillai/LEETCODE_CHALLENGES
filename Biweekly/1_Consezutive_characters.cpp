class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        if(n == 1 || n==0){
            return n;
        }
        int maxlen = 1;
        int count = 1;
        char same = s[0];
        for(int i=1;i<n;i++){
            if(s[i] == same){
                count++;
                maxlen = max(count,maxlen);
            }
            else{
                same = s[i];
                count = 1;
            }
        }
        return maxlen;
    }
};