
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
             int n = strs.size();
             sort(strs.begin() , strs.end());
             
             string s1 = strs[0];
             string s2 = strs[n-1];

            int len = min(s1.length(), s2.length());
             
             for(int i = 0 ; i<len ; i++){
                if(s1[i]!=s2[i]){
                    return s1.substr(0,i);
                }
             }
             return s1.substr(0,len);
    }
};
