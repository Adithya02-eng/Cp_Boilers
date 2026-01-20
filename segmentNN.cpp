#include "bits/stdc++.h"
using namespace std;

class SegmentTree
{
	int n;
	vector<int>a;
	vector<int>lazy;
public:

	SegmentTree(int n,vector<int>&arr)
	{
		this->n= n;
		a = vector<int>(4*n +1);
		lazy = vector<int>(4*n +1);
		for(int i = 0;i < n;i++)
		{
			Update(0,n-1,i,i,arr[i]);
		}
	}

	int Update(int l,int r,int ql,int qr,int x,int i=1)
	{
		if(ql > r||qr < l)
		{
			return a[i];
		}

		if(lazy[i] != 0)
		{
			if(l != r)
			{
				lazy[2*i] += lazy[i];
				lazy[2*i +1] += lazy[i];
			}
			a[i] += (r-l+1)*lazy[i];
			lazy[i] = 0;
		}

		if(l >= ql && r <= qr)
		{
			if(l != r)
			{
				lazy[2*i] += x;
				lazy[2*i +1] += x;
			}
			return (a[i] += (r-l+1)*x); 
		}
		int mid = (l+r)/2;
		return a[i] = Update(l,mid,ql,qr,x,2*i) + Update(mid+1,r,ql,qr,x,2*i +1);
	}

	int query(int l,int r,int ql,int qr,int i=1)
	{
		if(ql > r||qr < l)
		{
			return 0;
		}

		if(lazy[i] != 0)
		{
			if(l != r)
			{
				lazy[2*i] += lazy[i];
				lazy[2*i +1] += lazy[i];
			}
			a[i] += (r-l+1)*lazy[i];
			lazy[i] = 0;
		}
		if(l >= ql && r <= qr)
		{

			return a[i];
		}
		int mid = (l+r)/2;
		return query(l,mid,ql,qr,2*i) + query(mid+1,r,ql,qr,2*i +1);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
    	int n;
    	cin>>n;
    	vector<int>a(n);
    	for(int i = 0;i < n;i++)
    	{
    		cin>>a[i];
    	}
    	SegmentTree sT(n,a);
    	cout<<sT.query(0,n-1,1,3);
    }

    return 0;
}