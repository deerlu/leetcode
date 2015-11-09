#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
    	vector< vector<string> > result;
    	unordered_map<string, vector<string> > m;

    	for(int i = 0; i < strs.size(); i++){
    		string tmp = strs[i];
    		sort(tmp.begin(), tmp.end());
    		m[tmp].push_back(strs[i]);
    	}

    	for(auto i = m.begin();i != m.end(); i++){
    		vector<string> tmp = i->second;
    		sort(tmp.begin(), tmp.end());
    		result.push_back(tmp);
    	}
        return result;
    }
};

int main(){
	Solution s;
	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tae");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	vector< vector<string> > result = s.groupAnagrams(strs);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}