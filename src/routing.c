#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "dijkstra.h"
#include "priority_queue.h"

#define INF 99999

void shortest_path(Graph* map, int start_vertex, int end_vertex){

  int num_vertex = map->num_vertex;
  MinHeap* heap = create_min_heap(num_vertex);

  int distance[num_vertex];
  int father[num_vertex];
  int visited[num_vertex];

  for(int i=0; i<num_vertex; i++){
    distance[i] = INF;
    father[i] = -1;
    visited[i] = 0;
  }

  distance[start_vertex] = 0;
  insert_min_heap(heap, start_vertex, 0);

  while(heap->size > 0){

    HeapNode closest = extract_min(heap);
    int current = closest.vertex_id;

    if(visited[current] == 1){
      continue;
    }

    visited[current] = 1;

    if(current == end_vertex){
      break;
    }

      Edge* temp = map->vertex[current]->edges; 
        
    while(temp != NULL){
      int neighboor = temp->next_vertex_id; 
      int weight = temp->weight; 

      if(visited[neighboor] == 0){
        int next_dist = distance[current] + weight;

        if(next_dist < distance[neighboor]){
          distance[neighboor] = next_dist; 
          father[neighboor] = current;     

                
          insert_min_heap(heap, neighboor, distance[neighboor]);
        }
      }
      temp = temp->next;
    }
  } 

  free(heap->array);
  free(heap);

  if(distance[end_vertex] == INF){
    printf("Erro: Nenhuma rota logistica possivel entre o Polo %d e o Polo %d.\n", start_vertex, end_vertex);
    return; 
  }
 
  int path[num_vertex];
  int step_count = 0;
  int curr = end_vertex;
  
  while(curr != -1){
    path[step_count] = curr;
    step_count++;
    curr = father[curr];
  }

  printf("\n--- RELATORIO DE ROTA ---\n");
  printf("Menor Caminho: ");
  for(int i = step_count - 1; i >= 0; i--){
    printf("%d", path[i]);
        
    if(i > 0){
      printf(" -> ");
    }
  }

  printf("\nCusto Total Acumulado: %d\n", distance[end_vertex]);
  printf("-------------------------\n");
}
