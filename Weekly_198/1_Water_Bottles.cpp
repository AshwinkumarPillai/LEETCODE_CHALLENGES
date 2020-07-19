class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int ans = 0,empty=0,prev=0;
        while(nb){
            ans += nb;
            if(nb+empty < ne)break;
            prev = empty;
            empty = (nb+empty)%ne;
            nb = (nb+prev) / ne;
        }
        return ans;
    }
};
