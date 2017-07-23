/**
 * Solution use two stack(one stack when use pair)
 * time : O(1)
 * space : O(n)
 */
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, min_s;
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if(min_s.empty() || x < min_s.top())
            min_s.push(x);
        else
            min_s.push(min_s.top());
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};
