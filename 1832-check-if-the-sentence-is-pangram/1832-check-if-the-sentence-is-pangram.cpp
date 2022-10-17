class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        set<char>st;
        
        for(auto i: sentence){
            st.insert(i);
        }
        
        for(char ch='a';ch<='z';ch++){
            if(st.find(ch)==st.end()){
                return false;
            }
        }
        return true;
    }
};