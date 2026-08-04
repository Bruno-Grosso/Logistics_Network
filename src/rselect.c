#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "rselect.h"

static void swap(TrafficNode* a, TrafficNode* b){
  TrafficNode temp = *a;
  *a = *b;
  *b = temp;
}

static int partition(TrafficNode arr[], int low, int high){

  int random_index = low + rand() % (high - low + 1);

  swap(&arr[low], &arr[random_index]);

  int pivot = arr[low].incoming_routes;
  int i = low+1;

  for(int l=low+1; l<=high; l++){

    if(arr[l].incoming_routes <= pivot){
      swap(&arr[i], &arr[l]);
      i++;
    }

  }

  swap(&arr[i-1], &arr[low]);
  return i-1;
}

TrafficNode rselect(TrafficNode arr[], int low, int high, int k){

  if(low == high){
    return arr[low];
  }

  int pivot_index = partition(arr, low, high);

  if(pivot_index == k){
    return arr[pivot_index];
  }

  if(pivot_index > k){
    return rselect(arr, low, pivot_index-1, k);
  }else{
    return rselect(arr, pivot_index+1, high, k);
  }
}

void run_logistics_audit(TrafficNode arr[], int num_vertex) {
  if (num_vertex == 0) return;

  int k = num_vertex / 2;

  TrafficNode median = rselect(arr, 0, num_vertex - 1, k);

  printf("\n--- LOGISTICS AUDIT (Underperforming Zones) ---\n");
  printf("Global Traffic Median: %d routes (Reference City: %s)\n\n", 
    median.incoming_routes, median.name);

  printf("Cities operating BELOW or AT the median traffic:\n");
  for (int i = 0; i < k; i++) {
    printf("- [%d] %s -> %d incoming routes\n", 
      arr[i].vertex_id, 
      arr[i].name, 
      arr[i].incoming_routes);
  }
  printf("-----------------------------------------------\n");
}
