//tc->O(n + m)
//sc->O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
          int n = ransomNote.size();
          int m = magazine.size();

          vector<int> freq(26,0);
          for(int i =0 ;i<m ; i++){
              freq[magazine[i]-'a']++;
          }
          for(int i =0 ; i<n ; i++){
             if(freq[ransomNote[i]-'a']==0){
                return false;
             }else{
                freq[ransomNote[i]-'a']--;
             }
          }
          return true ;
    }
};
