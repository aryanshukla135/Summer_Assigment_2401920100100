class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nums(n);
        stack<int> st ;
        for(int i = n-1 ; i>=0 ; i--){
            int val = temperatures[i];
            while(!st.empty() && temperatures[st.top()]<=val){
                st.pop();
            }
            if(st.empty()){
                nums[i]=0;
            }else{
                int idx = st.top()-i;
                nums[i] = idx;
            }
            st.push(i);
        }
        
        return nums;
    }
};
