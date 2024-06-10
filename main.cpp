/** @file */

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "graph.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream inputFile;
	ofstream outputFile;

	// jezeli nie udalo sie sparsowac argumentow to zakoncz programa
	if (!parseArgs(argc, argv, inputFile, outputFile))
		return 1;
	Graph graph = Graph();
	processFile(inputFile, graph);
	graph.PrintGraph(outputFile);
	outputFile << endl;
	if (graph.IsBigraph())
		graph.PrintSets(outputFile);
	else
		outputFile << "Graf nie jest dwudzielny" << endl;
	return 0;
}