#include<cctype>
#include<stack>
#include <string>
class Solution {
public:
    bool isInteger(string num){
        int n = num.length();
        if(n==1 && isdigit(num[0])){
            return true;
        }
        else if(n==1 && !isdigit(num[0])){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!isdigit(num[i]) && (i==0 && num[0]=='-')){
                continue;
            }
            else if(!isdigit(num[i])){
                return false;
            }
        }

        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> val;
        int n = tokens.size();

        for(int i=0;i<n;i++){
            if(isInteger(tokens[i])){
                val.push(stoi(tokens[i]));
            }
            else if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/"){
                int num2 = val.top();
                val.pop();
                int num1 = val.top();
                val.pop();

                string op = tokens[i];
                int res;
                if(op== "+"){
                    res = num1+num2;
                }
                else if(op== "-"){
                    res = num1-num2;
                }
                else if(op== "*"){
                    res = num1*num2;
                }
                else if(op== "/"){
                    res = num1/num2;
                }

                val.push(res);
            }
        }
        return val.top();
    }
};