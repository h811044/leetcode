// 225. Implement Stack using Queues

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
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
