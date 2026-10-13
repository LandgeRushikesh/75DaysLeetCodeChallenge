class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();

        for(int i=0;i<tokens.length;i++){
            if(tokens[i].equals("+")){
                int op1 = stack.peekFirst();
                stack.pollFirst();
                int op2 = stack.peekFirst();
                stack.pollFirst();

                int ans = op2+op1;
                stack.offerFirst(ans);
            }
            else if(tokens[i].equals("-")){
                int op1 = stack.peekFirst();
                stack.pollFirst();
                int op2 = stack.peekFirst();
                stack.pollFirst();

                int ans = op2-op1;
                stack.offerFirst(ans);
            }
            else if(tokens[i].equals("*")){
                int op1 = stack.peekFirst();
                stack.pollFirst();
                int op2 = stack.peekFirst();
                stack.pollFirst();

                int ans = op2*op1;
                stack.offerFirst(ans);
            }
            else if(tokens[i].equals("/")){
                int op1 = stack.peekFirst();
                stack.pollFirst();
                int op2 = stack.peekFirst();
                stack.pollFirst();

                int ans = op2/op1;
                stack.offerFirst(ans);
            }
            else{
                stack.offerFirst(Integer.valueOf(tokens[i]));
            }
        }
        return stack.peekFirst();
    }
}