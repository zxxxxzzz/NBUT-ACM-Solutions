按行按列缩点（中间没有墙隔开的点）
然后对于每一个’.’,从它所在的行点的向列点建图，求最大匹配

/*************************************************************************
    > File Name: hdu1045.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年02月16日 星期一 12时21分20秒
 ************************************************************************/

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

const int N = 20;
int edge[N][N];
int match[N];
bool used[N];
int un, vn;
int row[10][10];
int col[10][10];
char mat[10][10];

bool dfs (int u)
{
    for (int i = 0; i < vn; ++i)
    {
        if (!used[i] && edge[u][i])
        {
            used[i] = 1;
            if (match[i] == -1 || dfs (match[i]))
            {
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungry ()
{
    int ans = 0;
    memset (match, -1, sizeof(match));
    for (int i = 0; i < un; ++i)
    {
        memset (used, 0, sizeof(used));
        if (dfs (i))
        {
            ++ans;
        }
    }
    return ans;
}

int main ()
{
    int n;
    while (~scanf("%d", &n), n)
    {
        memset (edge, 0, sizeof(edge));
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", mat[i]);
        }
        un = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = 0;
            bool flag = false;
            while (j < n)
            {
                if (mat[i][j] == '.')
                {
                    flag = true;
                    row[i][j] = un;
                    ++j;
                    if (j == n)
                    {
                        ++un;
                    }
                }
                else
                {
                    ++j;
                    if (flag)
                    {
                        ++un;
                    }
                }
            }
        }
        vn = 0;
        for (int j = 0; j < n; ++j)
        {
            int i = 0;
            bool flag = false;
            while (i < n)
            {
                if (mat[i][j] == '.')
                {
                    flag = true;
                    col[i][j] = vn;
                    ++i;
                    if (i == n)
                    {
                        ++vn;
                    }
                }
                else
                {
                    ++i;
                    if (flag)
                    {
                        ++vn;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == '.')
                {
                    edge[row[i][j]][col[i][j]] = 1;
                }
            }
        }
        int res = hungry();
        printf("%d\n", res);
    }
    return 0;
}
