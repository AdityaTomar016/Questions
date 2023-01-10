class info{
    public: 
    
    string name;
    int time;
    int amount;
    string city;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
    
        vector<string>ans;
        
        info obj;
        vector<info> v;
        
        string str="";
        
         for(auto s: transactions){
             
             int num=0;
             for(int i=0;i<s.size();i++){
                 
                 if(s[i] == ','){
                     
                     if(num == 0){
                         obj.name = str;
                     }
                     else if(num == 1){
                         obj.time = stoi(str);
                     }
                     else if(num == 2){
                         obj.amount = stoi(str);
                     }
                     
                     num++;
                     str = "";
                     continue;
                 }
                 
                 str += s[i];
             }
             
             obj.city = str;
             v.push_back(obj);
             str = "";
         }
        
        bool found=false;
        
        for(int i=0;i<v.size();i++){
            
            if(v[i].amount >= 1000){
                ans.push_back(transactions[i]);
                continue;
            }
            
            for(int j=0;j<v.size();j++){
                
                if(i == j){
                    continue;
                }
                
                if(v[i].name == v[j].name && v[i].city != v[j].city){
                    if(abs(v[i].time - v[j].time) <= 60){
                        
                        found = true;
                        break;
                    }
                }
            }
            
            if(found){
                ans.push_back(transactions[i]);
                found = false;
            }
        }
        
        return ans;
    }
};