class MyStack {
    
    queue<int> q1;
    queue<int> q2;
     
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q1.empty()){
            while (q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            return temp;
        }
        else{
            while (q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            return temp;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()){
            return q2.back();
        }
        else{
            return q1.back();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */