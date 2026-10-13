class Solution {
    public List<String> buildArray(int[] target, int n) {
        Deque<Integer> stack = new ArrayDeque<>();
        List<String> ans = new ArrayList<>();
        int j=0;
        for(int i=1;i<=n;i++){
            stack.offerFirst(i);
            ans.add("Push");
            if(stack.peekFirst()==target[j]){
                j++;
            }
            else{
                stack.pollFirst();
                ans.add("Pop");
            }

            if(j==target.length){
                break;
            }
        }

        return ans;
    }
}