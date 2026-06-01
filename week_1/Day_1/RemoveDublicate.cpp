// tc->O(n)
//sc->O(1) 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =1;
        int j = 1;
        while(j<n){
            if(nums[j]==nums[j-1]){
                j++;
            }else{
                nums[i]=nums[j];
                j++;
                i++;
            }
        }
        return i;
    }
};
