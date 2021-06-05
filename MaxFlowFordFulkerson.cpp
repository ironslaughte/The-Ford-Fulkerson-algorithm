#include <iostream>
#include "Read_file.cpp"
#include "adjacencyMatrix.cpp"
#include "MaxFlow.cpp"
int main()
{
    std::fstream stream;
    size_t cap = uniqNodes(stream);
    List* graph = new List[cap];
    ReadFile(stream, graph);
    int** adjacencyMatrix = buildAdjacencyMatrix(graph);
    size_t len = _msize(graph) / sizeof(List);

    std::cout << maxFlow(adjacencyMatrix, 0, 2);

    delete[] graph;
    for (size_t i = 0; i < len; i++) {
        delete[] adjacencyMatrix[i];
    }
    return 0;
}


