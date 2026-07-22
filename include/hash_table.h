#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct HashNode{
  char* name;
  int vertex_id;
  struct HashNode* next;
}HashNode;

typedef struct HashTable{
  int size;
  HashNode** array;
}HashTable;

HashTable* create_hash(int table_size);
HashTable* insert_hash(HashTable* hash, char* str, int vertex_id);
int search_hash(HashTable* hash, char* str);
void free_hash(HashTable* hash);

#endif 
