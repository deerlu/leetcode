#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector< bitset<26> > vecWords;
        bitset<26> word;
        bitset<26> zero;
        zero.reset();
        int result = 0;
        for(vector<string>::iterator i = words.begin(); i != words.end(); i++){
        	word.reset();
        	for(int j = 0; j < (*i).length(); j++){
        		word[(*i)[j] - 'a'] = true;
        	}
        	vecWords.push_back(word);
        }
        for(int i = 0; i != vecWords.size(); i++){
        	for(int j = i + 1; j != vecWords.size(); j++){
        		if((vecWords[i] & vecWords[j]) == zero){
        			int length = words[i].size() * words[j].size();
        			if(length > result){
        				result = length;
        			}
        		}
        	}
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<string> words;
	words.push_back("eae");
	words.push_back("ea");
	words.push_back("aaf");
	words.push_back("bda");
	words.push_back("fcf");
	words.push_back("dc");
	words.push_back("ac");
	words.push_back("ce");
	words.push_back("cefde");
	words.push_back("dabae");
	cout<<s.maxProduct(words)<<endl;
	return 0;
}