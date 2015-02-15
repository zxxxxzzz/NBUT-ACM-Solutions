
解法：trie + dfs

/*************************************************************************
    > File Name: cf291-c.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年02月15日 星期日 12时16分59秒
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
const int N = 7 * 100010;
char str[N];
int has_len[N];
int len;

struct TRIE
{
    TRIE *next[3];
    int cnt;
    TRIE ()
    {
        cnt = 0;
        next[0] = next[1] = next[2] = NULL;
    }
}*root;

void insert (char str[])
{
    int len = strlen (str);
    TRIE *p = root;
    for (int i = 0; i < len; ++i)
    {
        if (p -> next[str[i] - 'a'] == NULL)
        {
            p -> next[str[i] - 'a'] = new TRIE ();
        }
        p = p -> next[str[i] - 'a'];
    }
    p -> cnt = 1;
}

bool find (TRIE *p, int cur, bool has)
{
    if (cur == len)
    {
        return has && p -> cnt;
    }
    bool flag = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (p -> next[i] != NULL)
        {
            if (i == str[cur] - 'a')
            {
                flag |= find (p -> next[i], cur + 1, has);
            }
            else
            {
                if (has)
                {
                    continue;
                }
                flag |= find (p -> next[i], cur + 1, 1);
            }
        }
    }
    return flag;
}

void DELETE (TRIE *p)
{
    for (int i = 0; i < 3; ++i)
    {
        if (p -> next[i] != NULL)
        {
            DELETE (p -> next[i]);
        }
    }
    delete p;
}

int main ()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        memset (has_len, 0, sizeof(has_len));
        root = new TRIE();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            len = strlen (str);
            has_len[len] = 1;
            insert (str);
        }
        while (m--)
        {
            scanf("%s", str);
            len = strlen (str);
            if (!has_len[len])
            {
                printf("NO\n");
                continue;
            }
            if (find (root, 0, 0))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        DELETE(root);
    }
    return 0;
}
