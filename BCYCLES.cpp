/*
https://www.codechef.com/problems/BCYCLES
Problem Code: BCYCLES
*/
#include<bits/stdc++.h>
#define MAX 100005
#define MAX1 300005
using namespace std; 
vector<int> cycs[MAX]; 
int ans[3][MAX],res[MAX],seq[MAX];
int Fst[MAX],to[MAX1],pre[MAX1],vot,num; 
bool vis[MAX]; 
void add_new_edge(int u, int v)
{
	to[vot] = v; 
	pre[vot] = Fst[u]; 
	Fst[u] = vot++; 
}
bool dfs_traversal(int u)
{
	vis[u] = true; 
	for (int i = Fst[u]; ~i; i = pre[i])
	{
		if (res[to[i]] == -1 || (!vis[res[to[i]]] && dfs_traversal(res[to[i]])))
		{
			res[u] = to[i]; 
			res[to[i]] = u; 
			return true; 
		}
	}
	return false; 
}
void hungary()
{
	memset(res, -1, num << 2); 
	for (int i = 0; i < num; i++)
	{
		if (res[i] == -1)
		{
			memset(vis, false, num); 
			dfs_traversal(i); 
		}
	}
}
int main()
{
	int tc; 
	cin>>tc; 
	while (tc--)
	{
		cin>>num;
		memset(Fst, -1, num << 2); 
		vot = 0; 
		for (int i = 0; i < 3 * num / 2; i++)
		{
			int u, v; 
			cin>>u>>v;
			add_new_edge(--u, --v);
			add_new_edge(v, u); 
		}
		hungary(); 
		memcpy(ans[0], res, num << 2); 
		memset(vis, false, num); 
		for (int i = 0; i < num; i++)
		{
			if (vis[i])
				continue; 
			int fa = -1, u = i, cnt = 0; 
			while (!vis[u])
			{
				seq[cnt++] = u; 
				vis[u] = true; 
				for (int j = Fst[u]; ~j; j = pre[j])
				{
					if (to[j] == fa || to[j] == res[u])
						continue; 
					fa = u; 
					u = to[j]; 
					break; 
				}
			}
			for (int j = 0; j < cnt; j++)
			{
				ans[(j & 1) + 1][seq[j]] = seq[(j + 1) % cnt]; 
				ans[(j & 1) + 1][seq[(j + 1) % cnt]] = seq[j]; 
			}
		}
		int cyc_cnt = 0; 
		for (int i = 0; i < 3; i++)
		{
			memset(Fst, -1, num << 2); 
			vot = 0; 
			for (int j = 0; j < 3; j++)
			{
				if (i == j)
					continue; 
				for (int x = 0; x < num; x++)
					add_new_edge(x, ans[j][x]); 
			}
			memset(vis, false, num); 
			for (int j = 0; j < num; j++)
			{
				if (vis[j])
					continue; 
				int fa = to[Fst[j]], u = j; 
				vector<int> cyc; 
				while (!vis[u])
				{
					cyc.push_back(u); 
					vis[u] = true; 
					int v = to[Fst[u]] ^ to[pre[Fst[u]]] ^ fa;
					fa = u;
					u = v; 
				}
				cycs[cyc_cnt++] = cyc; 
			}
		}
		cout<<cyc_cnt<<endl;
		for (int i = 0; i < cyc_cnt; i++)
		{
			cout<<(int)cycs[i].size()<<" ";
			for (int j = 0; j < cycs[i].size(); j++)
				printf("%d%c", cycs[i][j] + 1, " \n"[j + 1 == cycs[i].size()]);
		}
	}
	return 0; 
}
