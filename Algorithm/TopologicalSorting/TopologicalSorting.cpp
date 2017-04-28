#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MAX_VERTEX_NUM 20
typedef struct ArcNode 
{
	int adjvex;				//
	struct ArcNode *nextarc;	//
	//string info;			//
}ArcNode;

typedef struct VNode 
{
	int data;				//
	ArcNode *firstarc;		//
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct 
{
	AdjList vertices;		//
	int venum, arcnum;		//
	int kind;				//
}ALGraph;

int InDegree[MAX_VERTEX_NUM] = {0};		//

int CreateDG(ALGraph& G)
{
	cout << "Please input the vertices and edges of the graph:";
	cin >> G.venum >> G.arcnum;
	int i;
	for (i = 0; i < G.venum; i++)
	{
		G.vertices[i].data = i + 1;		//
		G.vertices[i].firstarc = NULL;
	}

	for (i = 0; i < G.arcnum; i++)
	{
		cout << "Please input the info of the edges that you would add:";
		int v1, v2;
		cin >> v1 >> v2;
		ArcNode* current = G.vertices[v1 - 1].firstarc;
		ArcNode* p = G.vertices[v1 - 1].firstarc;
		InDegree[v2 - 1]++;		//

		if (current == NULL)
		{
			G.vertices[v1 - 1].firstarc = new ArcNode;
			G.vertices[v1 - 1].firstarc->adjvex = v2 - 1;
			G.vertices[v1 - 1].firstarc->nextarc = NULL;
		}
		else
		{
			while (current != NULL)
			{
				p = current;
				current = current->nextarc;
			}
			current = new ArcNode;
			current->adjvex = v2 - 1;
			current->nextarc = NULL;
			p->nextarc = current;
		}
	}
	return 1;
}

void TopologicalSort(ALGraph &G)
{
	stack<int> S;
	int i;
	for (i = 0; i < G.venum; i++)
	{
		if (InDegree[i] == 0)
		{
			S.push(i);		//
		}
	}
	
	int count = 0;
	while (!S.empty())
	{
		i = S.top();
		S.pop();
		cout << G.vertices[i].data << " ";
		++count;
		ArcNode *p = NULL;
		for (p = G.vertices[i].firstarc; p != NULL; p = p->nextarc)
		{
			int w = p->adjvex;
			InDegree[w]--;
			if (InDegree[w] == 0)
			{
				S.push(w);
			}
		}
	}

	if (count < G.venum)
	{
		cout << "The existence of a ring in a directed graph" << endl;
	}
}

int main() 
{
	ALGraph G;
	CreateDG(G);
	ArcNode* current1;
	ArcNode* p;
	for (int k = 0; k < G.venum; k++)
	{
		cout << G.vertices[k].data << "->";
		ArcNode* current1 = G.vertices[k].firstarc;
		while (current1 != NULL)
		{
			cout << current1->adjvex << "->";
			current1 = current1->nextarc;
		}
		cout << endl;
	}

	TopologicalSort(G);

	for (int i = 0; i < G.venum; i++)
	{
		current1 = p = G.vertices[i].firstarc;
		if (current1 == NULL)
			continue;
		else 
		{
			while (p != NULL)
			{
				p = current1->nextarc;
				delete current1;
				current1 = p;
			}
		}
	}
}
