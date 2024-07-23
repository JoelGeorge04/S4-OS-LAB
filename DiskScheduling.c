#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int temp;
void sort(int *requests, int number_of_request) {
  for (int i=0;i<number_of_request-1;i++) {
    for (int j=0;j<number_of_request-1;j++) {
      if (requests[j] > requests[j+1]) {
        temp = requests[j];
        requests[j] =requests[j+1];
        requests[j+1] =temp;
      }
    }
  }
}

void fcfs(int *requests, int number_of_request) {
  int i, total_head_movement = 0;
  printf("Sequence : %d ", requests[0]);
  for (i=0;i<number_of_request;i++) {
    printf("%d ",requests[i+1]);
    total_head_movement+=abs(requests[i+1]-requests[i]);
  }
  printf("\nTotal head movement = %d \n", total_head_movement);
}

void scan(int *copy_of_array, int number_of_request, int initial_position) {
  int choice, total_head_movement = 0, loc, i, traverse_index, disk_start, disk_end, inc,requests[MAX], traversed[MAX];
  for (i=0;i<number_of_request+1;i++)
    requests[i]=copy_of_array[i];
  printf("Choose 1: Left or 2: Right :");
  scanf("%d", &choice);
  printf("Enter the Start and End of disk :");
  scanf("%d%d", &disk_start, &disk_end);
  requests[++number_of_request] = disk_start, requests[++number_of_request] = disk_end;
  sort(requests,++number_of_request);
  for (i=0;i<number_of_request && requests[i]!=initial_position;i++);
  loc =i;
  inc =(choice == 1) ? (-1) : 1;
  for (i=loc,traverse_index =0;traverse_index<number_of_request-1;) {
    traversed[traverse_index++]= requests[i];
    i += inc;
    if ((i<0||i>number_of_request-1) && traverse_index<number_of_request-1)
      inc *= (-1), i = loc+inc;
  }
  printf("Sequence : %d ", traversed[0]);
  for (i=0;i<traverse_index-1;i++) {
    printf("%d ", traversed[i + 1]);
    total_head_movement+=abs(traversed[i+1]-traversed[i]);
  }
  printf("\nTotal head movement = %d \n", total_head_movement);
}

void cscan(int copy_of_array[], int number_of_request, int initial_position) {
  int choice, total_head_movement = 0, loc, i, traverse_index, disk_start, disk_end, inc,requests[MAX], traversed[MAX];
  for (i=0;i<number_of_request+1;i++)
    requests[i]=copy_of_array[i];
  printf("Choose 1: Left or 2: Right :");
  scanf("%d", &choice);
  printf("Enter the Start and End of disk :");
  scanf("%d%d", &disk_start, &disk_end);
  requests[++number_of_request] = disk_start, requests[++number_of_request] = disk_end;
  sort(requests, ++number_of_request);
  for (i =0;i< number_of_request && requests[i] != initial_position; i++);
  loc = i;
  inc = (choice == 1) ? (-1) : 1;
  for (i = loc, traverse_index = 0; traverse_index < number_of_request;) {
    traversed[traverse_index++] = requests[i];
    i += inc;
    if ((i<0||i>number_of_request-1) &&traverse_index < number_of_request-1)
      i =(i < 0) ? (number_of_request - 1) : 0;
  }
  printf("Sequence : %d ", traversed[0]);
  for (i=0;i<traverse_index-1;i++) {
    printf("%d ", traversed[i+1]);
    total_head_movement += abs(traversed[i+1]-traversed[i]);
  }
  printf("\nTotal head movement = %d \n", total_head_movement);
}

int main() {
  int i, number_of_request, requests[MAX], choice, initial_position;
  printf("Enter the number of requests :");
  scanf("%d", &number_of_request);
  printf("Enter the Requests :");
  for (i=1;i<number_of_request+1;i++)
    scanf("%d", &requests[i]);
  printf("Enter the initial position :");
  scanf("%d", &initial_position);
  requests[0] = initial_position;
  do {
    printf("Enter 1:FCFS 2:SCAN 3:CSCAN 4:Exit :\n");
    scanf("%d", &choice
    );
    switch (choice) {
      case 1:
        fcfs(requests, number_of_request);
        break;
      case 2:
        scan(requests, number_of_request, initial_position);
        break;
      case 3:
        cscan(requests, number_of_request, initial_position);
      case 4:
        break;
      default:
        printf("Invalid input\n");
    }
  } while (choice
   != 4);
  return 0;
}