//tc->O(n)
//sc->O(1)
class Solution {
public:
    int firstUniqChar(string s) {
         int n = s.length();
         vector<int> idx(26,0);
         for(int i =0 ; i< n ; i++){
             idx[s[i]-'a']++;
         }
         int ans = -1;
         for(int i =0 ; i< n ; i++){
             if(idx[s[i]-'a'] == 1){
                  ans = i;
                  break ;
             }
         }
         return ans ;
    }
};
