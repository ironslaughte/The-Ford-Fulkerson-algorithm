#pragma once


struct Top {
	char node; 
	int weight = 0; // edge weight

	Top() {
		node = ' ';
		weight = 0;
	}

	Top(char Node, int Weight = 0) {
		node = Node;
		weight = Weight;
	}
};