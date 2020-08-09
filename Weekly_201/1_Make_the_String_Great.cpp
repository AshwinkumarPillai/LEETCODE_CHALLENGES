// Solution 1
class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while(i<s.length()){
            if((s[i]-'a' == s[i+1]-'A') || s[i]-'A' == s[i+1]-'a'){
                s.erase(i,2);
                if(i) i-=2;
                else i--;
            }
            i++;
        }
        return s;
    }
};
// Solution 2
class Solution {
public:
    string makeGood(string s, int sz = 0) {
        while (sz != s.size()) {
            sz = s.size();
            for (int i = 0; i + 1 < s.size(); ++i)
                if (s[i] != s[i + 1] && tolower(s[i]) == tolower(s[i + 1])) {
                    s = s.substr(0, i) + s.substr(i + 2);
                }
        }
        return s;
    }
};
