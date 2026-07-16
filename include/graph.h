#ifndef GRAPH_H
#define GRAPH_H

typedef struct Edge{
  int next_vertex_id;
  int weight;
  struct Edge* next;
}Edge;

typedef struct Vertex{
  int vertex_id;
  int x_position;
  int y_position;
  char* name;
  Edge* edges;
}Vertex;

typedef struct Graph{
  int num_vertex;
  Vertex** vertex;
}Graph;

Graph* create_graph(int num_vertex);
Graph* create_vertex(Graph* map, int id, int x_position, int y_position, char name[]);
Graph* add_edge(Graph* map, int weight, int origin, int destination);
void print_graph(Graph* map);

#endif 
