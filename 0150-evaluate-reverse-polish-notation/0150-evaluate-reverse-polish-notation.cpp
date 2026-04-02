#include<cctype>
#include<stack>
#include <string>
class Solution {
public:
    // Brute Force Approach
    // bool isInteger(string num){
    //     int n = num.length();
    //     if(n==1 && isdigit(num[0])){
    //         return true;
    //     }
    //     else if(n==1 && !isdigit(num[0])){
    //         return false;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(!isdigit(num[i]) && (i==0 && num[0]=='-')){
    //             continue;
    //         }
    //         else if(!isdigit(num[i])){
    //             return false;
    //         }
    //     }

    //     return true;
    // }
    // int evalRPN(vector<string>& tokens) {
    //     stack<int> val;
    //     int n = tokens.size();

    //     for(int i=0;i<n;i++){
    //         if(isInteger(tokens[i])){
    //             val.push(stoi(tokens[i]));
    //         }
    //         else if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/"){
    //             int num2 = val.top();
    //             val.pop();
    //             int num1 = val.top();
    //             val.pop();

    //             string op = tokens[i];
    //             int res;
    //             if(op== "+"){
    //                 res = num1+num2;
    //             }
    //             else if(op== "-"){
    //                 res = num1-num2;
    //             }
    //             else if(op== "*"){
    //                 res = num1*num2;
    //             }
    //             else if(op== "/"){
    //                 res = num1/num2;
    //             }

    //             val.push(res);
    //         }
    //     }
    //     return val.top();
    // }

    // Optimal Approach - An input only have valid integer and an operator so we don't need isInteger() function we can simply check for an operator if not then input is valid integer.
    int evalRPN(vector<string>& tokens) {
        stack<int> val;
        int n = tokens.size();

        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" ||tokens[i]=="/"){
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
            else{
                val.push(stoi(tokens[i]));
            }
        }
        return val.top();
    }
    /*
    Time Complexity → O(n)
    Space Complexity → O(n) (stack)
    */
};