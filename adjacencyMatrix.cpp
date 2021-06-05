#include "List.h"

size_t find_top_idx_in_graph(List* graph, size_t idx_start, size_t idx) {
	size_t len = _msize(graph) / sizeof(List);
	for (size_t i = 0; i < len; i++) {
		if (graph[idx_start][idx].node == graph[i][0].node) return i;
	}
}


int** buildAdjacencyMatrix(List* graph) {
	size_t size = _msize(graph) / sizeof(List);
	int** adjacencyMatrix = new int* [size]; // матрица смежности
	for (size_t i = 0; i < size; i++) {
		adjacencyMatrix[i] = new int[size];
	}

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			adjacencyMatrix[i][j] = 0;
		}
	}

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < graph[i].GetSize(); j++) {
			size_t idx = find_top_idx_in_graph(graph, i, j);
			adjacencyMatrix[i][idx] = graph[i][j].weight;
		}
	}

	return adjacencyMatrix;
}