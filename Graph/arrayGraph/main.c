#include "graph.h"

int main(int argc, char* argv[])
{
	int nodeCount = 6;
	DirectLinkedGraph* pG2 = createDirectLinkedGraph(nodeCount);
	if (pG2 != NULL) {
		addEdgeDLG(pG2, 0, 1);
		addEdgeDLG(pG2, 1, 2);
		addEdgeDLG(pG2, 2, 0);
		addEdgeDLG(pG2, 2, 3);
		addEdgeDLG(pG2, 3, 2);
		addEdgeDLG(pG2, 3, 4);
		addEdgeDLG(pG2, 4, 5);
		addEdgeDLG(pG2, 5, 3);
		printf("G2 : 방향그래프\n");
		displayGraphDLG(pG2);
		deleteGraphDLG(pG2);
	}
	return 0;
}
