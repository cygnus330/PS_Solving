template<typename T, int s>
class Queue
{
 public:
    T A[s];
    int f = 0;
    int b = 0;
    
    T front()
    {
        return A[f];
    }
    bool empty()
    {
        return f == b;
    }
    bool full()
    {
        return ((b + 1) % s == f);
    }
    int size()
    {
        return f > b ? f-b : b-f;
    }
    void push(T e)
    {
        if(full())
            cerr << "FULL QUEUE : size " << s << endl;
        else
        {
            A[b++] = e;
            b %= s;
        }
    }
    void pop()
    {
        if(empty())
            cerr << "EMPTY QUEUE : size 0" << endl;
        else
        {
            f++;
            f %= s;
        }
    }
};