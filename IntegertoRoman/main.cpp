#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int bit = 0;
        int count = 0;
        string result = "";
        while(num != 0){
            bit = num % 10;
            num = num / 10;
            switch(count)
            {
                case 0:{
                    if(bit == 4){
                        result = "IV" + result;
                    }else if(bit == 9){
                        result = "IX" + result;
                    }else{
                        for(int i = 0; i < bit % 5; i++){
                            result = "I" + result;
                        }
                        if(bit >= 5){
                            result = "V" + result;
                        }
                    }
                    break;
                }
                case 1:{
                     if(bit == 4){
                        result = "XL" + result;
                    }else if(bit == 9){
                        result = "XC" + result;
                    }else{
                        for(int i = 0; i < bit % 5; i++){
                            result = "X" + result;
                        }
                        if(bit >= 5){
                            result = "L" + result;
                        }
                    }
                    break;
                }
                case 2:{
                     if(bit == 4){
                        result = "CD" + result;
                    }else if(bit == 9){
                        result = "CM" + result;
                    }else{
                        for(int i = 0; i < bit % 5; i++){
                            result = "C" + result;
                        }
                        if(bit >= 5){
                            result = "D" + result;
                        }
                    }
                    break;
                }
                case 3:{
                    for(int i = 0; i < bit; i++){
                            result = "M" + result;
                    }
                    break;
                }
            }
            count++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.intToRoman(17)<<endl;
    return 0;
}
