//tc->O(n)
//sc->O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
         int n = s.length();
         int m = t.length();

         if(m!=n){
            return false;
         }

         vector<int> freq(26,0);

         for(int i =0 ;i<n ; i++){
             freq[s[i]-'a']++;
         }
         for(int i =0 ; i< m ; i++){
             char ch = t[i];
             if(freq[ch-'a']==0){
                return false;
             }else{
                freq[ch-'a']--;
             }
         }
         return true ;
    }
};
