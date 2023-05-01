class Solution {
public:
    double average(vector<int>& salary) {
        
        int n = salary.size();
        
        double mini = *min_element(salary.begin(),salary.end());
        double maxi = *max_element(salary.begin(),salary.end());
        
        double sum=0;
        
        for(int i=0;i<salary.size();i++){
            sum += salary[i];
        }
        
        return (sum-mini-maxi)/(n-2);
    }
};