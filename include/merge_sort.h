#ifndef MERGE_SORT_H 
#define MERGE_SORT_H

typedef struct TrafficNode{
  int vertex_id;
  char* name;
  int incoming_routes;
}TrafficNode;

void merge_sort(TrafficNode* ranking, int left, int right);

#endif 
