#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "priority_queue.h"

int main(){

  int num_vertex;
  
  printf("How many vertex you need? ");
  scanf("%d", &num_vertex);

  Graph* map = create_graph(num_vertex);

  int x, y;
  char name[50];

  
  for(int i=0; i<num_vertex; i++){

    printf("Put the name of the city here: ");
    scanf(" %[^\n]", name);

    printf("Which is the position of coordinate x? ");
    scanf("%d", &x);

    printf("Which is the position of coordinate y? ");
    scanf("%d", &y);
    
    map = create_vertex(map, i, x, y, name);

    printf("\n");
  }

  int continua = 0; 
  int origin, destination, weight;

  while (continua != 3) {
  
    printf("\n--- LOGISTICS NETWORK MENU ---\n");
    printf("1. Add Edge\n");
    printf("2. Print Graph\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &continua);

    switch (continua) {
        case 1:
            printf("Which is the origin vertex? ");
            scanf("%d", &origin);

            printf("Which is the destination vertex? ");
            scanf("%d", &destination);

            printf("Which is the weight for this edge? ");
            scanf("%d", &weight);
            
            map = add_edge(map, weight, origin, destination);
            break;

        case 2:
            print_graph(map);
            break;

        case 3:
            printf("Exiting engine...\n");
            break;
            
        default:
            printf("Invalid option! Try again.\n");
            break;
    }

  }

  /*MinHeap* heap = create_min_heap(10);

  insert_min_heap(heap, 3, 80);
  insert_min_heap(heap, 1, 10);
  insert_min_heap(heap, 2, 50);
  insert_min_heap(heap, 4, 5);
  insert_min_heap(heap, 5, 100);

  while(heap->size > 0){
    HeapNode closest = extract_min(heap);
    printf("Closest city -> ID: %d | Accumulate Cost: %d\n", closest.vertex_id, closest.cost);
  }

  free(heap->array);
  free(heap);*/
    
  return 0;
}
