// If k is on the left part of the string, we do nothing.
// If K is right in the middle, we return flip directly.
// If k is on the right part of the string,
// find it's symeric postion k = l + 1 - k.
// Also we toggle flip ^= 1

// -----------------------------------------------------------------
//  O(N) solution - by @lzl124631x
// The length of the string len is 2^n - 1.

// If k - 1 == len / 2, then this is the middle of the string, return 1 unless n == 1.

// If k - 1 < len / 2, this is at the left part of Sn, which is the same as findKthBit(n - 1, k).

// If k - 1 > len / 2, this is the i = k - (len / 2 + 1) - 1-th bit in the right part, which is the invert of findKthBit(n - 1, len / 2 - i).
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int len = pow(2, n) - 1;
        if (k - 1 == len / 2) return '1';
        if (k - 1 < len / 2) return findKthBit(n - 1, k);
        int i = k - (len/2 + 1) - 1;
        return findKthBit(n - 1, len/2-i) == '0' ? '1' : '0';
    }
};

// // Brute Force
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        int i=2;
        while(i<=n){
            string t = s;
            reverse(t.begin(),t.end());
            for(int i=0;i<t.length();i++){
                if(t[i] == '0') t[i] = '1';
                else t[i] = '0';
            }
            s+="1";
            s+=t;
            i++;
        }
        return s[k-1];
    }
};
