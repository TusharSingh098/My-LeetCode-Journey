class MyQueue 
{
private:
    struct stack
    {
        int k{-1};
        int data[100];

        void pushS(int x) 
        {
            if (k != 99) data[++k] = x;        
        }

        int popS() 
        {
            if (k != -1) return data[k--];
            return -1;
        }

        int topS() 
        {
            if (k != -1) return data[k];
            return -1;
        }

        bool isEmpty() 
        {
            return k == -1;
        }
    } s1, s2;

public:
    MyQueue() {}
    
    void push(int x) 
    {
        if (s1.k == 99) return;

        while (!s1.isEmpty()) s2.pushS(s1.popS());

        s1.pushS(x);

        while (!s2.isEmpty()) s1.pushS(s2.popS());
    }
    
    int pop() 
    {
        return s1.popS();
    }
    
    int peek() 
    {
        return s1.topS();
    }
    
    bool empty() 
    {
        return s1.isEmpty();
    }
};