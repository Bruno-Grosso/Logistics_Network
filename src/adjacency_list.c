#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

Graph* create_graph(int num_vertex){
  
  Graph* map = (Graph*)malloc(sizeof(Graph));
  
  map->num_vertex = num_vertex;
  map->vertex = (Vertex**)malloc(num_vertex*sizeof(Vertex*));

  for(int i=0; i<num_vertex; i++){
    map->vertex[i] = NULL;
  }

  return map;
}

Graph* create_vertex(Graph* map, int id, int x_position, int y_position, char name[]){

  Vertex* new_vertex = (Vertex*)malloc(sizeof(Vertex));

  new_vertex->vertex_id = id;
  new_vertex->x_position = x_position;
  new_vertex->y_position = y_position;
  new_vertex->name = (char*)malloc(strlen(name) + 1);
  strcpy(new_vertex->name, name);
  new_vertex->edges = NULL;

  map->vertex[id] = new_vertex;

  return map;
}

Edge* create_edge(int destination, int weight){

  Edge* new_edge = (Edge*)malloc(sizeof(Edge));

  new_edge->next_vertex_id = destination;
  new_edge->weight = weight;
  new_edge->next = NULL;

  return new_edge;
}

Graph* add_edge(Graph* map, int weight, int origin, int destination){
  
  Edge* new_edge = create_edge(destination, weight);
  
  Vertex* current_vertex = map->vertex[origin];

  new_edge->next = current_vertex->edges;
  current_vertex->edges = new_edge;

  return map;
}

void print_graph(Graph* map){
  if (map == NULL) return;

    printf("\n--- LOGISTICS NETWORK MAP ---\n");
    for (int i = 0; i < map->num_vertex; i++) {
        Vertex* v = map->vertex[i];
        
        if (v != NULL) {
            printf("[%d] %s (x: %d, y: %d) -> Connections:\n", v->vertex_id, v->name, v->x_position, v->y_position);
            
            Edge* current_edge = v->edges;
            if (current_edge == NULL) {
                printf("    (No outgoing routes)\n");
            }
            
            // Percorre a lista encadeada de arestas
            while (current_edge != NULL) {
                printf("    -> To Hub [%d] (Weight: %d)\n", current_edge->next_vertex_id, current_edge->weight);
                current_edge = current_edge->next;
            }
        }
    }
    printf("-----------------------------\n");
}
