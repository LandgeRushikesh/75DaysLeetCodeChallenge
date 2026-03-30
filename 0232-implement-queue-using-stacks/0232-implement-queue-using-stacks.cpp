class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {//--->O(n)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {//---> O(1)
        int ele = s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {//---> O(1)
        return s1.top();
    }
    
    bool empty() {//---> O(1)
        return s1.empty();
    }

    // Space Complexity - O(n)---> elements stored in stacks
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */