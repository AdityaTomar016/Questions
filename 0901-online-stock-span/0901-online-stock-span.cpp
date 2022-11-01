class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
     
        int count=1;

        while(!st.empty() && st.top().second <= price){
            count += st.top().first;
            st.pop();
        }

        st.push({count,price});
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */