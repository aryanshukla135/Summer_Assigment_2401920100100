//tc->O(n)
//sc->O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i =1 ; i< n ; i++){
             nums[i] = nums[i]+nums[i-1];
        }
        
        int i =0;  
        int j =0 ;
        double maxavg  = INT_MIN;

        while(j<n){
            if((j-i+1)>=k){
                double val1= nums[j];
                double val2 =0;
                if(i==0){
                    val2=0;
                }else{
                    val2=nums[i-1];
                }
                double avg = (val1-val2)/k;
                maxavg = max(maxavg , avg);
                i++;  
            }
            j++;
        }
        return maxavg;
    }
};
