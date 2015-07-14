#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int length = calEveryAxisInterval(A,C,E,G);
        int wide = calEveryAxisInterval(B,D,F,H);
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        return area1 + area2 - length * wide;
    }

    int calEveryAxisInterval(int x1, int x2, int y1, int y2){
    	if(x1 > y1 || (x1 == y1 && x2 > y2)){
    		int tmp1 = x1;
    		x1 = y1;
    		y1 = tmp1;
    		int tmp2 = x2;
    		x2 = y2;
    		y2 = tmp2;
    	}

    	if(x2 < y1){
    		return 0;
    	}else{
    		if(x2 < y2){
    			return x2 - y1;
    		}else{
    			return y2 - y1;
    		}
    	}
    }
};

int main(){
	Solution s;
	cout<<s.computeArea(0,0,3,2,2,1,2,1)<<endl;
	return 0;
}