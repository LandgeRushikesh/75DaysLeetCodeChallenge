class Solution {
    public String removeDuplicates(String s) {
        char arr[] = new char[s.length()];
        int j = -1;
        for(int i=0;i<s.length();i++){
            if(j==-1){
                arr[j+1] = s.charAt(i);
                j++;
            }
            else if(j!=-1 && arr[j]==s.charAt(i)){
                j--;
            }
            else{
                arr[j+1] = s.charAt(i);
                j++;
            }
        }
        String ans = "";
        for(int i=0;i<=j;i++){
            ans += arr[i];
        }

        return ans;
    }
}