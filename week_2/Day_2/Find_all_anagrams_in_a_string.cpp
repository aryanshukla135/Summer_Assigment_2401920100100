//tc->O(n +k)
//sc->O(1)
class Solution {
private:
    bool allzero(vector<int> &freq){
        for(int i =0 ; i<26 ; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true ;
    }
public:
    vector<int> findAnagrams(string s, string p) {
          int n = s.length();
          int k = p.length();
          vector<int> freq(26,0);

          for(int i =0 ;i<k ; i++){
              freq[p[i]-'a']++;
          }

          int i =0 ; 
          int j = 0;
          vector<int> ans ;
          while(j<n){
            freq[s[j]-'a']--;
            if(j-i+1==k){
                if(allzero(freq)){
                    ans.push_back(i);
                }
                freq[s[i]-'a']++;
                i++;
            }
            j++;
          }
          return ans ;
    }
};
