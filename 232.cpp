// 232. Implement Queue using Stacks

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int s1Bot;

public:
    MyQueue() {
    }

    void push(int x) {
        if (s1.empty()) {
            s1Bot = x;
        }
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }

    int peek() {
        int top = s2.empty() ? s1Bot : s2.top();
        return top;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
