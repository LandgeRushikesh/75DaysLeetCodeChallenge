class Solution {
public:
    // We can write our own customized alphaNumeric checking function
    // bool isAplhaNumeric(char ch){
    //     if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch)<='z')){
    //         return true;
    //     }
    //     return false;  
    // }

    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }

            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++,j--;
        }

        return true;
    }
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};