#include "Heap_H.h"

void main(void) {
	Heap* H = Heap_Create(3);
	DType MinNode;

	Heap_Insert(H, 12);
	Heap_Insert(H, 87);
	Heap_Insert(H, 111);
	Heap_Insert(H, 34);
	Heap_Insert(H, 16);
	Heap_Insert(H, 75);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	Heap_DeleteMin(H, &MinNode);
	Heap_PrintNodes(H);

	free(H->Nodes);
	free(H);

}