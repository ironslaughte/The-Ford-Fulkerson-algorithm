#include "Set.h"
#include <fstream>
#include "List.h"
#include <string>


size_t uniqNodes(std::fstream& stream) {
	stream.open("input.txt", std::ios::in);
	if (!stream.good()) {
		throw std::invalid_argument("File do not exist\n");
	}
	stream >> std::noskipws;
	Set set_nodes;
	
	while (!stream.eof()) {
		char s = ' ';
		stream >> s;
		if (s != '\n' && !stream.eof()) {
			if (s >= 'A') {
				set_nodes.Insert(s);
			}
		}
	}
	stream.close();
	if (!set_nodes.Find('S')) throw std::logic_error("the input file is set incorrectly\n");
	if (!set_nodes.Find('T')) throw std::logic_error("the input file is set incorrectly\n");
	return set_nodes.GetSize();
}


int findInGraph(List* list, char node) {
	size_t len = _msize(list) / sizeof(List);
	for (size_t i = 0; i < len; i++) {
		if (list[i][0].node == node) return i;
	}
	return -1;
}

void ReadFile(std::fstream& stream, List* graph) {
	stream.open("input.txt", std::ios::in);
	if (!stream.good()) {
		throw std::invalid_argument("File do not exist\n");
	}
	stream >> std::noskipws;
	size_t i = 0;
	while (!stream.eof()) {
		char s = ' ';
		std::string str = "";
		while (s != '\n' && !stream.eof()) {
			stream >> s;
			if (s != '\n' && !stream.eof() && s!= ' ') str += s;
		}

		char node1 = str[0];
		char node2 = str[1];
		int weight = 0;
		for (size_t i = 2, rate = 1; i < str.length(); i++, rate += 10) {
			weight *= rate;
			weight += (str[i] - '0');
		}

		int idx = findInGraph(graph, node1);
		if (idx == -1) {
			graph[i].Push_back(Top(node1));
			graph[i++].Push_back(Top(node2, weight));
		}
		else {
			graph[idx].Push_back(Top(node2, weight));
		}

		idx = findInGraph(graph, node2);
		if (idx == -1) {
			graph[i].Push_back(Top(node2));
			graph[i++].Push_back(Top(node1, weight));
		}
		else {
			graph[idx].Push_back(Top(node1, weight));
		}
	}
	if (_msize(graph) / sizeof(List) == 0) {
		throw std::runtime_error("File is empty");
	}
}
