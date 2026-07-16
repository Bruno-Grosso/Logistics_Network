#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct HeapNode{
  int vertex_id;
  int cost;
}HeapNode;

typedef struct MinHeap{
  int capacity;
  int size;
  HeapNode* array;
}MinHeap;

MinHeap* create_min_heap(int num_vertex);
void insert_min_heap(MinHeap* heap, int vertex_id, int cost);
HeapNode extract_min(MinHeap* heap);

#endif 
