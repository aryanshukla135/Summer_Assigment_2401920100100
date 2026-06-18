class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> nums(n);
        stack<int> st;
        for(int i = n-1 ; i>=0; i--){
            int val = heights[i];
            while(!st.empty() && heights[st.top()]>=val){
                st.pop();
            }
            if(st.empty()){
                nums[i] = -1 ;
            }else{
                nums[i] = st.top();
            }
            st.push(i);
        }
        return nums ;
    }

    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> nums(n);
        stack<int> st;
        for(int i = 0 ; i<n; i++){
            int val = heights[i];
            while(!st.empty() && heights[st.top()]>=val){
                st.pop();
            }
            if(st.empty()){
                nums[i] = -1 ;
            }else{
                nums[i] = st.top();
            }
            st.push(i);
        }
        return nums ;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nxtSmaller(n);
        vector<int> prvSmaller(n);

        nxtSmaller = nextSmaller(heights);
        prvSmaller = prevSmaller(heights);
        int maxlen = INT_MIN ;
        
        for(int i =0 ; i<n ; i++){
            int len = heights[i];
            if(nxtSmaller[i]== -1){
                nxtSmaller[i] = n;
            }
            int wid = nxtSmaller[i]-prvSmaller[i]-1;

            maxlen = max(maxlen,len*wid);
        }
        return maxlen ;
    }
};
