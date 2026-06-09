//tc->O(n)
//sc->O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
         unordered_map<char,int> m;
         int i =0;
         int j=0;
         int maxlen =INT_MIN;

         while(i<n){
            char ch  = s[i];
            m[ch]++;
            if(m[ch]>1){
                maxlen = max(maxlen,i-j);
            }

            while(m[ch]>1){
                maxlen = max(maxlen,i-j);
                m[s[j]]--;
                j++;
            }
            i++;
         }
        maxlen = max(maxlen ,i-j);
       
         return maxlen ;
    }
};
