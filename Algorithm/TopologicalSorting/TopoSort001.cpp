/*
 *
 */

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <memory.h>

using namespace std;
#define MAX 9999

stack<int>mystack;
int indegree[MAX];

struct node
{
	int adjvex;
	node* next;
}adj[MAX];

int Create(node adj[], int n, int m)//
{
	int i;
	node *p;
	for (i = 1; i <= n; i++)
	{
		adj[i].adjvex = i;
		adj[i].next = NULL;
	}

	for (i = 1; i <= m; i++)
	{
		cout << "Please input the NO." << i << "edge:";
		int u, v;
		cin >> u >> v;
		p = new node;
		p->adjvex = v;
		p->next = adj[u].next;
		adj[u].next = p;
	}
	return 1;
}

void print(int n)
{
	int i;
	node *p;
	for (i = 1; i <= n; i++)
	{
		p = &adj[i];
		while (p != NULL)
		{
			cout << p->adjvex << ' ';
			p = p->next;
		}
		cout << endl;
	}
}

void topsort(node adj[], int n)
{
	int i;
	node *p;
	memset(indegree,0,sizeof(indegree));
	for (i = 1; i < n; i++)
	{
		p = adj[i].next;
		while (p != NULL)
		{
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			mystack.push(i);
	}
	int count = 0;
	while (mystack.size() != 0)
	{
		i = mystack.top();
		mystack.pop();
		cout << i << ' ';
		count++;
		for (p = adj[i].next; p != NULL; p = p->next)
		{
			int k = p->adjvex;
			indegree[k]--;
			if (indegree[k] == 0)
				mystack.push(k);
		}
	}
	cout << endl;
	if (count < n)cout << "LOOP" << endl;
}

int main()
{
	int n;
	int m;
	cout << "Please input vertices and edges:";
	cin >> n >> m;
	Create(adj, n, m);
	cout << "input the adjacency list:" << endl;
	print(n);
	cout << "toposort result is:" << endl;
	topsort(adj,n);
	system("pause");
	return 0;

}
