#include<stdio.h>
#include<stdlib.h>

#include "graph.h"
#include "priority_queue.h"
#include "dijkstra.h"
#include "hash_table.h"

int main(){

  int num_vertex;
  
  printf("How many vertex you need? ");
  scanf("%d", &num_vertex);

  Graph* map = create_graph(num_vertex);

  int table_size = 4099;
  HashTable* hash = create_hash(table_size);

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
    hash = insert_hash(hash, name, i);

    printf("\n");
  }

  int continua = 0;
  int origin_id, destination_id, weight;
  char origin[50], destination[50];

  while (continua != 4) {
  
    printf("\n--- LOGISTICS NETWORK MENU ---\n");
    printf("1. Add Edge\n");
    printf("2. Print Graph\n");
    printf("3. Calculate Route\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &continua);

    switch (continua) {
        case 1:
            printf("Which is the origin city? ");
            scanf(" %[^\n]", origin);

            printf("Which is the destination city? ");
            scanf(" %[^\n]", destination);

            origin_id = search_hash(hash, origin);
            destination_id = search_hash(hash, destination);

            if(origin_id == -1 || destination_id == -1){
              printf("Operation failed: One of the cities is not registered.\n");
            } else{

              printf("Which is the weight for this edge? ");
              scanf("%d", &weight);

              map = add_edge(map, weight, origin_id, destination_id);
            }
            
            break;

        case 2:
            print_graph(map);
            break;

        case 3:
            printf("Wich is the start city? ");
            scanf(" %[^\n]", origin);

            printf("Wich is the final city? ");
            scanf(" %[^\n]", destination);

            origin_id = search_hash(hash, origin);
            destination_id = search_hash(hash, destination);

            if(origin_id == -1 || destination_id == -1){
              printf("Operation failed: One of the cities is not registered.\n");
            } else{
              shortest_path(map, origin_id, destination_id);
            }

            break;
          
        case 4:
            printf("Exiting engine...\n");
            break;
            
        default:
            printf("Invalid option! Try again.\n");
            break;
    }

  }
  
  free_graph(map);
  free_hash(hash);
  return 0;
}
