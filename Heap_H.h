#ifndef HEAP_H
#define HEAP_H

#include <malloc.h>
#include <stdio.h>

typedef int DType;

typedef struct tagHeap {
	DType* Nodes;
	int Capacity;
	int UsedSize;
} Heap;

// �� ����
Heap* Heap_Create(int InitialSize);

// ��� ����
int Heap_Insert(Heap* H, DType NewData);
// �θ� ��� ��ġ ��ȯ
int Heap_GetParent(int Index);
// ���� �ڽ� ��ġ ��ȯ
int Heap_GetLeftChild(int Index);
//��� ����
void Heap_SwapNodes(Heap* H, int a, int b);
// ���� �ּڰ� ����
void Heap_DeleteMin(Heap* H, DType* Root);
// �� ���
void Heap_PrintNodes(Heap* H);

#endif //HEAP_H