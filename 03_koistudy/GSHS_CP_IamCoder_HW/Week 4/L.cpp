#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

class board
{
 private:
    const int boardSize = 4;
    array<array<int, 4>, 4> boardArr;
    void move1()
    {
        for(int y = 0; y < 4; y++)
            for(int i = 0; i < 8; i++)
                for(int x = 1; x < 4; x++)
                    if(boardArr[x][y] != 0 && boardArr[x - 1][y] == 0)
                    {
                        boardArr[x - 1][y] = boardArr[x][y];
                        boardArr[x][y] = 0;
                    }
    }
    void move2()
    {
        for(int x = 0; x < 4; x++)
            for(int i = 0; i < 8; i++)
                for(int y = 1; y < 4; y++)
                    if(boardArr[x][y] != 0 && boardArr[x][y - 1] == 0)
                    {
                        boardArr[x][y - 1] = boardArr[x][y];
                        boardArr[x][y] = 0;
                    }
    }
    void move3()
    {
        for(int y = 0; y < 4; y++)
            for(int i = 0; i < 8; i++)
                for(int x = 2; x >= 0; x--)
                    if(boardArr[x][y] != 0 && boardArr[x + 1][y] == 0)
                    {
                        boardArr[x + 1][y] = boardArr[x][y];
                        boardArr[x][y] = 0;
                    }
    }
    void move4()
    {
        for(int x = 0; x < 4; x++)
            for(int i = 0; i < 8; i++)
                for(int y = 2; y >= 0; y--)
                    if(boardArr[x][y] != 0 && boardArr[x][y + 1] == 0)
                    {
                        boardArr[x][y + 1] = boardArr[x][y];
                        boardArr[x][y] = 0;
                    }
    }
 public:
    void reset(const int *p)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                boardArr[i][j] = *(p + 4 * i + j);
    }
    void set(const int x, const int y, const int c) {boardArr[x - 1][y - 1] = c;}
    void print(int * const p)
    {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                *(p + 4 * i + j) = boardArr[i][j];
    }
    
    void Move(int a)
    {
        if(a == 1)
        {
            move1();
            for(int y = 0; y < 4; y++)
                for(int i = 0; i < 8; i++)
                    for(int x = 1; x < 4; x++)
                        if(boardArr[x][y] == boardArr[x - 1][y] && boardArr[x][y])
                        {
                            boardArr[x - 1][y] *= 2;
                            boardArr[x][y] = 0;
                            move1();
                        }
        }
        else if(a == 2)
        {
            move2();
            for(int x = 0; x < 4; x++)
                for(int i = 0; i < 8; i++)
                    for(int y = 1; y < 4; y++)
                        if(boardArr[x][y] == boardArr[x][y - 1] && boardArr[x][y])
                        {
                            boardArr[x][y - 1] *= 2;
                            boardArr[x][y] = 0;
                            move2();
                        }
        }
        else if(a == 3)
        {
            move3();
            for(int y = 0; y < 4; y++)
                for(int i = 0; i < 8; i++)
                    for(int x = 2; x >= 0; x--)
                        if(boardArr[x][y] == boardArr[x + 1][y] && boardArr[x][y])
                        {
                            boardArr[x + 1][y] *= 2;
                            boardArr[x][y] = 0;
                            move3();
                        }
        }
        else if(a == 4)
        {
            move4();
            for(int x = 0; x < 4; x++)
                for(int i = 0; i < 8; i++)
                    for(int y = 2; y >= 0; y--)
                        if(boardArr[x][y] == boardArr[x][y + 1] && boardArr[x][y])
                        {
                            boardArr[x][y + 1] *= 2;
                            boardArr[x][y] = 0;
                            move4();
                        }
        }
        else
        {
            cerr << "WRONG" << endl;
            exit(0);
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    int A[16];
    for(int i = 0; i < 16; i++)
        scanf("%d", A + i);
    
    board a;
    a.reset(A);
    
    for(int i = 0; i < n; i++)
    {
        int prev[16];
        a.print(prev);
        
        int d, x, y, c;
        scanf("%d %d %d %d", &d, &x, &y, &c);
        a.Move(d);
        a.set(x, y, c);
        
        int now[16];
        a.print(now);
        
        bool k = true;
        for(int j = 0; j < 16; j++)
            if(prev[j] != now[j])
                k = false;
        if(k)
            a.reset(prev);
    }
    
    int t[16];
    a.print(t);
    
    for(int i = 0; i < 16; i++)
    {
        if(i % 4 == 0 && i > 0)
            printf("\n");
        printf("%d ", t[i]);
    }
    
    return 0;
}