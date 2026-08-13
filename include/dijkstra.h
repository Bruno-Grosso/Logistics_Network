#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

// Calculates shortest path and exports payload to path_result.json
void shortest_path(Graph* map, int start_vertex, int end_vertex);

#endif
