class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n = nums2.size();
            vector<int> nextgreater(n) ;
            stack<int> s ;

            for(int i = n-1 ; i>=0 ; i--){
                int val = nums2[i];
                while(!s.empty() && val>=s.top()){
                    s.pop();
                }
                if(s.empty()){
                    nextgreater[i] = -1 ;
                }else{
                    nextgreater[i] = s.top();
                }
                s.push(val);
            }
            int m = nums1.size();
            vector<int> result(m) ;
            unordered_map<int,int> mp ;

            for(int i =0 ; i< n ; i++){
                mp[nums2[i]]=i;
            }

            for(int i = 0 ; i< m ; i++){
                int val = nums1[i];
                result[i] = nextgreater[mp[nums1[i]]];
            }
            
            return result; 
    }
};
