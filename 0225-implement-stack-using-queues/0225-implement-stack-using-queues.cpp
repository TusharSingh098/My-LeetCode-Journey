class MyStack {
private:
    struct queue
    {
        int start{-1}, end{-1}, size{0};
        int data[100];

        void pushQ(int x) 
        {
            if (size == 100) return;
            if (size == 0) start = end = 0;
            else end = (end + 1) % 100;
            data[end] = x;
            (size)++;
        }

        int popQ() 
        {
            if (size == 0) return -1;
            int temp{data[start]};
            if (size == 1) start = end = -1;
            else start = (start + 1) % 100;
            (size)--;
            return temp;
        }

        int peek() { return size ? data[start] : -1; }
    } q1, q2;

public:
    MyStack() {}
    
    void push(int x) 
    {
        if (q1.size == 100) return;

        q2.pushQ(x);

        while (q1.size) q2.pushQ(q1.popQ());

        swap(q1, q2);
    }
    
    int pop() 
    {
        return q1.popQ();
    }
    
    int top() 
    {
        return q1.peek();
    }
    
    bool empty() 
    {
        return q1.size == 0;
    }
};