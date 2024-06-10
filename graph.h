#include <map>
#include <set>
#include <ostream>
#pragma once

using namespace std;

/// @brief Klasa przechowujaca graf
class Graph
{
private:
	map<int, set<int>> mEdges;
	map<int, bool> mColors;
public:
	Graph();
	~Graph();

	/**
	 * @brief Funkcja dodajaca krawedz pomiedzy dwoma wierzcholkami 
	 * 
	 * @param a pierwszy wierzcholek
	 * @param b drugi wierzcholek
	 */
	void AddEdge(int a, int b);

	/**
	 * @brief Funkcja sprawdzajaca dwudzielnosc grafu
	 * 
	 * @return true jezeli graf jest dwudzielny
	 * @return false jezeli graf nie jest dwudzielny
	 */
	bool IsBigraph();

	/**
	 * @brief Wypisz graf na strumien wyjsciowy
	 * 
	 * @param outputStream strumien wyjsciowy na ktory nalezy wypisac graf
	 */
	void PrintGraph(ostream& outputStream);

	/**
	 * @brief Wypisz 2 zbiory wierzcholkow na strumien wyjsciowy. Powinna byc uzywana tylko po sprawdzeniu dwudzielnosci funkcja @ref IsBigraph()
	 * 
	 * @param outputStream strumien wyjsciowy na ktory nalezy wypisac graf
	 */
	void PrintSets(ostream& outputStream);
};