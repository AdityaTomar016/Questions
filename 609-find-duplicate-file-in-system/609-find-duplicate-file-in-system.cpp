class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
	unordered_map<string, vector<string>> Files;
	vector<vector<string> > ans;
        
	for(auto path : paths) {
        
		int i = 0, j;
        
		while(path[i] != ' ') i++;   
		string dir = path.substr(0, i), file, content;
        
		while(i++ < size(path)) {
			
			j = i;
			while(path[i] != '(') i++;  
			file = path.substr(j, i - j);
			
			j = i;
			while(path[i++] != ')');    
			content = path.substr(j, i - j);
			
			Files[content].emplace_back(dir + '/' + file);
		}
	}
	for(auto content : Files) 
		if(size(content.second) > 1)
			ans.push_back(move(content.second));
	return ans;
}
};