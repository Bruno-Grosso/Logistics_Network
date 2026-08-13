#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "graph.h"
#include "hash_table.h"

// Reads file sequentially, using hash lookups to build the graph
void load_map(Graph* map, HashTable* hash, const char* filename){
  
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open the file '%s'.\n", filename);
    return;
  }

  char line[256];
  int reading_routes = 0;

  int current_id = 0;

  while (fgets(line, sizeof(line), file)){
    
    // Strip newline character
    line[strcspn(line, "\n")] = 0;

    if (strlen(line) == 0 || line[0] == '#'){
      continue;
    }

    if (strcmp(line, "---") == 0){
      reading_routes = 1;
      continue;
    }

    if (reading_routes == 0){
      map = create_vertex(map, current_id, 0, 0, line);
      hash = insert_hash(hash, line, current_id);

      current_id++;
    } else {
            
      char origin[100];
      char destination[100];
      int traffic;
      
      // Parses CSV-like format: Origin, Destination, Weight
      if (sscanf(line, "%[^,], %[^,], %d", origin, destination, &traffic) == 3){
        int o_id = search_hash(hash, origin);
        int d_id = search_hash(hash, destination);

        if (o_id != -1 && d_id != -1) {
          map = add_edge(map, traffic, o_id, d_id);
        } else {
          printf("Warning: Failed to connect %s and %s (City not found)\n", origin, destination);
        }
      } else {
        printf("Warning: Malformed route line ignored: %s\n", line);
      }
    }
  }

  fclose(file);
  printf("File uploaded successfully!\n");
}
