class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            int mod = n%3;
            if(mod == 2) return false;
            n /= 3;
        }
        return true;
    }
};
