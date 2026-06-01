//worst tc ->O(n^2)
//best tc ->O(n)
//sc->O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i=0;
        int maxi = 0 ;
        while(i<n){
           int j = i+1;
           while(j<n && (prices[j] > prices[i]) ){
               int diff=prices[j]-prices[i];
               maxi=max(maxi,diff);
               j++;

           }
           i++;
        }
        return maxi;
    }

};
