#include <bits/stdc++.h>
using namespace std;

// Just a Normal Loser Useless One //

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
const ll MOD = 1e9 + 7;

#define all(x) (x).begin(), (x).end()
#define pb push_back

#define int ll


struct SparseTable
{
	int n,K;
	vector<int>lg;
	vector<vector<int>>st;
	SparseTable(const vector<int>&a)
	{
		n = a.size();
		lg.resize(n+1);
		for(int i = 2;i <= n;i++)
		{
			lg[i] = lg[i/2]+1;
		}

		K = lg[n]+1;
		st.assign(K,vector<int>(n));
		st[0] = a;

		for(int k = 1;k < K;k++)
		{
			for(int i = 0;i+(1<<k) <=n;i++)
			{
				st[k][i] = min(
					st[k-1][i],
					st[k-1][i+(1<<(k-1))]);
			}
		}
	}

	int query(int l,int r)
	{
		int k = lg[r-l+1];
		return min(
			st[k][l],
			st[r][r-(1<<k)+1]);
	}
};


void solve()
{
    
}

signed main()
{

    fast_io;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}