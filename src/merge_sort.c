#include<stdlib.h>
#include<stdio.h>

#include "merge_sort.h"

void merge(TrafficNode traffic_array[], int left, int mid, int right){
  int left_size = mid-left+1;
  int right_size = right-mid;
  
  TrafficNode* L_array = (TrafficNode*)malloc(left_size*sizeof(TrafficNode));
  TrafficNode* R_array = (TrafficNode*)malloc(right_size*sizeof(TrafficNode));

  for(int i=0; i<left_size; i++){
    L_array[i] = traffic_array[left+i];
  }

  for(int i=0; i<right_size; i++){
    R_array[i] = traffic_array[mid+1+i];
  }

  int h = 0;
  int j = 0;
  int k = left;

  while(h < left_size && j < right_size){
    
    if((L_array[h].incoming_routes) >= (R_array[j].incoming_routes)){
      traffic_array[k] = L_array[h];
      h++;
    } else{
      traffic_array[k] = R_array[j];
      j++;
    }

    k++;
  }

  while(h < left_size){
    traffic_array[k] = L_array[h];
    h++;
    k++;
  }

  while(j < right_size){
    traffic_array[k] = R_array[j];
    j++;
    k++;
  }

  free(L_array);
  free(R_array);

}

void merge_sort(TrafficNode traffic_array[], int left, int right){

  if(left<right){
    int mid = left + (right-left) / 2;
    
    merge_sort(traffic_array, left, mid);
    merge_sort(traffic_array, mid+1, right);

    merge(traffic_array, left, mid, right);
  }

}


