#include <stdlib.h>
#include "priority_queue.h"

MinHeap* create_min_heap(int num_vertex){

  MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));

  heap->capacity = num_vertex;
  heap->size = 0;

  heap->array = (HeapNode*)malloc(num_vertex*sizeof(HeapNode));

  return heap;
}

void swap(HeapNode* a, HeapNode* b){
  HeapNode temp = *a;
  *a = *b;
  *b = temp;
}

void heapfy_up(MinHeap* heap, int current_index){
  
  if(current_index == 0){
    return;
  }

  int father_index = (current_index-1)/2;

  if(heap->array[current_index].cost < heap->array[father_index].cost) {
    swap(&heap->array[current_index], &heap->array[father_index]);
    heapfy_up(heap, father_index);

  }
}

void insert_min_heap(MinHeap* heap, int vertex_id, int cost){

  if(heap->size == heap->capacity){
    return;
  }

  heap->array[heap->size].vertex_id = vertex_id;
  heap->array[heap->size].cost = cost;

  int current_index = heap->size;

  heap->size++;

  heapfy_up(heap, current_index);

}

void heapfy_down(MinHeap* heap, int current_index){

  int left_child = (2 * current_index) + 1;
  int right_child = (2 * current_index) + 2;

  int smallest = current_index;

  if (left_child < heap->size && heap->array[left_child].cost < heap->array[smallest].cost) {
    smallest = left_child;
  }

    
  if (right_child < heap->size && heap->array[right_child].cost < heap->array[smallest].cost) {
    smallest = right_child;
  }

  if (smallest != current_index) {
    swap(&heap->array[current_index], &heap->array[smallest]);

    heapfy_down(heap, smallest);
  }
}

HeapNode extract_min(MinHeap* heap){

  if(heap->size == 0){
    HeapNode error_node;
    error_node.vertex_id = -1;
    error_node.cost = -1;
    return error_node;
  }

  HeapNode min_node = heap->array[0];
  heap->array[0] = heap->array[heap->size-1];

  heap->size--;

  if(heap->size > 1){
    heapfy_down(heap, 0);
  }
  
  return min_node;
}
