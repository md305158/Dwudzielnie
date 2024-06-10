#include "graph.h"
#include <queue>

Graph::Graph()
{
	this->mEdges = map<int, set<int>>();
	this->mColors = map<int, bool>();
}

Graph::~Graph()
{
	this->mEdges.clear();
	this->mColors.clear();
}

void Graph::AddEdge(int a, int b)
{
	this->mEdges[a].insert(b);
	this->mEdges[b].insert(a);
}

bool Graph::IsBigraph()
{
	//tworzymy kolejke do urzycia w algorytmie BFS
	queue<int> q;
	//czyscimy aktualne grupy wierzcholkow
	this->mColors.clear();
	//odwiedzamy wszystkie spojne skladowe
	for (const auto &[vertex, _] : this->mEdges)
	{
		//jezeli wierzcholek ma juz przypisana grupe to idz dalej
		//wierzcholek ten jest w spojnej skladowej ktora sprawdzilismy
		if (this->mColors.count(vertex) != 0)
			continue;
		
		//ustaw pierwszemu wierzcholkowi ze spojnej grupe na 1
		//i dodaj go do kolejki
		this->mColors[vertex] = true;
		q.push(vertex);
		//algorytm BSF
		while (!q.empty())
		{
			const int &p = q.front();
			for (const int &x : this->mEdges[p])
			{
				//jezeli sasiad aktualnie przegladanego sasiada ma juz grupe
				if (this->mColors.count(x) != 0)
				{
					//to sprawdz czy grupy sa rowne
					if (this->mColors[x] == this->mColors[p])
					{
						//jezeli tak to graf nie jest dwudzielny
						this->mColors.clear();
						return false;
					}
					continue;
				}
				//wpp ustaw grupe sasiada na przciwna grupe aktualnego wierzcholka
				this->mColors[x] = !this->mColors[p];
				q.push(x);
			}
			q.pop();
		}
	}
	return true;
}

void Graph::PrintGraph(ostream &outputStream)
{
	for (const auto &[vertex, edges] : this->mEdges)
	{
		outputStream << vertex << ":";
		for (const int &x : edges)
			outputStream << " " << x;
		outputStream << endl;
	}
}

void Graph::PrintSets(ostream &outputStream)
{
	outputStream << "Grupa 1:";
	for (const auto &[vertex, color] : this->mColors)
		if (color)
			outputStream << " " << vertex;
	outputStream << endl
				 << "Grupa 2:";
	for (const auto &[vertex, color] : this->mColors)
		if (!color)
			outputStream << " " << vertex;
	outputStream << endl;
}
