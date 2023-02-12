
const long long INF = 10000000000;

struct Node
{
    long long dist;
    int point;
    
    bool operator < (const Node &a) const
    {
        return a.dist > dist;
    }
};

Node makeNode(long long a, int b)
{
    Node c;
    c.dist = a;
    c.point = b;
    return c;
}