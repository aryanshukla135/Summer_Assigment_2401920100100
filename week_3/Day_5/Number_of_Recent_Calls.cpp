class RecentCounter {
public:
    queue<int> q ;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        int lowb = t-3000;
        int upprb = t ;
        while(!q.empty() && q.front()<lowb){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
