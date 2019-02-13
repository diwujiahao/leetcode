class MinStack {
    
    stack<int> data;
    stack<int> min_data;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (min_data.empty() || x < min_data.top()){
            min_data.push(x);
        }
        else{
            min_data.push(min_data.top());
        }
    }
    
    void pop() {
        data.pop();
        min_data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_data.top();
    }
};