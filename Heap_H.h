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

// 힙 생성
Heap* Heap_Create(int InitialSize);

// 노드 삽입
int Heap_Insert(Heap* H, DType NewData);
// 부모 노드 위치 반환
int Heap_GetParent(int Index);
// 왼쪽 자식 위치 반환
int Heap_GetLeftChild(int Index);
//노드 스왑
void Heap_SwapNodes(Heap* H, int a, int b);
// 힙의 최솟값 삭제
void Heap_DeleteMin(Heap* H, DType* Root);
// 힙 출력
void Heap_PrintNodes(Heap* H);

#endif //HEAP_H