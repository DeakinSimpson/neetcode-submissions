class MinStack {
public:
    MinStack() 
        : stack_{}
        , minStack_{} 
    {  }

    // idea:
    // we have 2 stacks, one is the min stack and one is the normal stack,
    // at each step we check if the current value is less then the current min.top()
    // if it is then we push it to the normal stack as well as the min stack
    // if it is not we push the min.top() to the min stack again to represent that it is
    // still the min at that point
    
    void push(int val) {
      stack_.push(val);
      if (minStack_.empty() || val <= minStack_.top()) {
        minStack_.push(val);
      } else {
        minStack_.push(minStack_.top());
      }
    }
    
    void pop() {
        stack_.pop();
        minStack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return minStack_.top();
    }
private:
    std::stack<int> stack_;
    std::stack<int> minStack_;
};
