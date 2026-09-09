class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int newn = 0;
        int x_copy = x;
        while(x_copy>0){
            int digit = x_copy%10;
            newn = newn*10 + digit;
            x_copy = x_copy/10;
        }

        return x == newn;
    }
}