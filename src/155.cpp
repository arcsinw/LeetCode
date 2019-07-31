class MinStack {
public:
    MinStack() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        min_val = INT_MAX;
    }

    void push(int x) {
        if (x <= min_val){
            data.push(min_val);
            min_val = x;
        }
        data.push(x);
    }

    void pop() {
        int t = data.top();
        data.pop();
        if (t == min_val){
            min_val = data.top();
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min_val;
    }
private:
    int min_val;
    stack<int> data;
};
