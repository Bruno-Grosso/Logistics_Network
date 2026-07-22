#include<stdlib.h>
#include<string.h>
#include "hash_table.h"

HashTable* create_hash(int table_size){

  HashTable* hash = (HashTable*)malloc(sizeof(HashTable));

  hash->size = table_size;
  hash->array = (HashNode**)malloc(table_size*sizeof(HashNode*));

  for(int i=0; i<table_size; i++){
    hash->array[i] = NULL;
  }

  return hash;
}

static int hash_function(char* str, int table_size){
  
  unsigned long hash_code = 5381;
  int c;

  while((c = *str++)) {
    hash_code = ((hash_code << 5)+ hash_code) + c;
  }

  return hash_code%table_size;
}

HashNode* create_node(char* str, int vertex_id){

  HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));

  int len = strlen(str);
  new_node->name = (char*)malloc((len+1)*sizeof(char));
  strcpy(new_node->name, str);

  new_node->vertex_id = vertex_id;

  return new_node;
}

HashTable* insert_hash(HashTable* hash, char* str, int vertex_id){

  int hash_code = hash_function(str, hash->size);

  HashNode* new_node = create_node(str, vertex_id);

  new_node->next = hash->array[hash_code];
  hash->array[hash_code] = new_node;

  return hash;
}

int search_hash(HashTable* hash, char* str){

  int hash_code = hash_function(str, hash->size);

  HashNode* temp = hash->array[hash_code];

  while(temp != NULL){

    if(strcmp(temp->name, str) == 0){
      return temp->vertex_id;
    }

    temp = temp->next;
  }

  return -1;
}

void free_hash(HashTable* hash){

  for(int i = 0; i < hash->size; i++){

    HashNode* current = hash->array[i];

    while(current != NULL){

      HashNode* next_node = current->next;

      free(current->name);
      free(current);

      current = next_node;
    }
  }

  free(hash->array);
  free(hash);
}
