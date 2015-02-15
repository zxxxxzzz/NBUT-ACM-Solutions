解法：水题，二分答案，然后枚举起点查询区间最大值，用RMQ即可

/*************************************************************************
    > File Name: cf-291-d.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年02月15日 星期日 14时09分50秒
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

const int N = 100010;
int dp[6][N][20];
int arr[N][6];
int ans[6];
int ret[6];
int LOG[N];

void initRMQ (int n, int m)
{
    for (int k = 1; k <= m; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            dp[k][i][0] = arr[i][k];
        }
        for (int j = 1; j <= LOG[n]; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            {
                dp[k][i][j] = max (dp[k][i][j - 1], dp[k][i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

int ST (int t, int l, int r)
{
    int k = LOG[r - l + 1];
    return max (dp[t][l][k], dp[t][r - (1 << k) + 1][k]);
}

int main ()
{
    int n, m;
    LL k;
    LOG[0] = -1;
    for (int i = 1; i <= N; ++i)
    {
        LOG[i] = ((i & ( i - 1)) == 0) ? LOG[i - 1] + 1 : LOG[i - 1];
    }
    while (~scanf("%d%d%lld", &n, &m, &k))
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        initRMQ(n, m);
        int l = 1, r = n;
        int mid;
        memset (ans, 0, sizeof(ans));
        memset (ret, 0, sizeof(ret));
        while (l <= r)
        {
            bool flag = false;
            mid = (l + r) >> 1;
            for (int i = 1; i <= n - mid + 1; ++i)
            {
                LL sum = 0;
                for (int j = 1; j <= m; ++j)
                {
                    int tmp = ST (j, i, i + mid - 1);
                    sum += tmp;
                    ret[j] = tmp;
                }
                if (sum > k)
                {
                    memset (ret, 0, sizeof(ret));
                    continue;
                }
                flag = true;
                break;
            }
            if (flag)
            {
                for (int i = 1; i <= m; ++i)
                {
                    ans[i] = ret[i];
                }
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d", ans[1]);
        for (int i = 2; i <= m; ++i)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
