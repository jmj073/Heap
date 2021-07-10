#include "Heap_H.h"

// 힙 생성
Heap* Heap_Create(int InitialSize) {
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = InitialSize;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (DType*)malloc(sizeof(DType) * InitialSize);

	return NewHeap;
}

//노드 삽입
int Heap_Insert(Heap* H, DType NewData) {
	int CurrentPosition = H->UsedSize;
	int ParentPosition = Heap_GetParent(CurrentPosition);
	DType* Shield;

	if (H->UsedSize == H->Capacity) {
		H->Capacity *= 2;
		Shield = (DType*)realloc(H->Nodes, sizeof(DType) * H->Capacity);
		if (Shield == NULL)
			return -1;
		H->Nodes = Shield;
	}
	H->Nodes[CurrentPosition] = NewData;

	while (CurrentPosition > 0 && H->Nodes[CurrentPosition] < H->Nodes[ParentPosition]) {
		Heap_SwapNodes(H, CurrentPosition, ParentPosition);
		CurrentPosition = ParentPosition;
		ParentPosition = Heap_GetParent(CurrentPosition);
	}
	H->UsedSize++;
	return 1;
}

// 부모 노드 위치 반환
int Heap_GetParent(int Index) {
	return (Index - 1) / 2;
}

// 왼쪽 자식 위치 반환
int Heap_GetLeftChild(int Index) {
	return Index * 2 + 1;
}

//노드 스왑
void Heap_SwapNodes(Heap* H, int a, int b) {
	int Temp = H->Nodes[a];
	H->Nodes[a] = H->Nodes[b];
	H->Nodes[b] = Temp;
}

// 힙의 최솟값 삭제
void Heap_DeleteMin(Heap* H, DType* Root) {
	int ParentPosition = 0, LeftPosition = 0, RightPosition = 0;

	*Root = H->Nodes[0];
	H->Nodes[0] = 0;

	Heap_SwapNodes(H, 0, --(H->UsedSize));

	LeftPosition = Heap_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1) {
		int SelectedChild = 0;

		if (LeftPosition >= H->UsedSize)
			break;

		if (RightPosition >= H->UsedSize)
			SelectedChild = LeftPosition;
		else if (H->Nodes[LeftPosition] > H->Nodes[RightPosition])
			SelectedChild = RightPosition;
		else
			SelectedChild = LeftPosition;

		if (H->Nodes[SelectedChild] < H->Nodes[ParentPosition]) {
			Heap_SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}
		else
			break;

		LeftPosition = Heap_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2)) {
		H->Capacity /= 2;
		H->Nodes = (DType*)realloc(H->Nodes, sizeof(DType) * H->Capacity);
	}
}

// 힙 출력
void Heap_PrintNodes(Heap* H) {
	int i;
	for (i = 0; i < H->UsedSize; i++)
		printf("%d ", H->Nodes[i]);
	printf("\n");
}