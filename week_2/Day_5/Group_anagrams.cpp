class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         int n = strs.size();
         unordered_map<string,vector<string>> m ;
         vector<vector<string>> ans ;

         for(int i =0 ; i < n ; i++){
            string word = strs[i];
            vector<int> freq(26,0);

            for(int j = 0; j<word.length() ; j++){
                char ch = word[j];
                freq[ch-'a']++;
            }
            string s ="";

            for(int k = 0 ; k<26 ; k++){
                while(freq[k] !=0){
                    s+=(k+'a');
                    freq[k]--;
                }
            }
            m[s].push_back(word);
         }
         for(auto str : m){
            vector<string> temp = str.second; 
            ans.push_back(temp);
         }
         return ans ;
    }
};
