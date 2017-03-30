//Ramzi El-abdallah
//Assignment 5: Page Replacement
//CS433
//November 19, 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv){

  int size = strlen(argv[1]);
  int  page_array[40];
  int frame_array[4] = {-1,-1,-1,-1};
  int j = 0; //Holds number of Pages
  int faults = 0;
  int flag;
  int frame_track = 0;
  
  //Puts the page values into an array
  for (int i = 0; i < size; i++){
    if(isdigit(argv[1][i])){
      page_array[j] = argv[1][i];
      j++;
    }
  }
  
  //Prints the Page Reference
  printf("Page Reference: ");
  for (int i = 0; i<j; i++){
    printf("%c, ", page_array[i]);
  }
  printf("\n");
  
  //FIFO

  for(int i = 0; i < j; i++){
    flag = 0;
    for (int k=0; k<4; k++){
      if(page_array[i] == frame_array[k])
	flag = 1;
    }
    if(flag == 0){
      frame_array[frame_track] = page_array[i];
      frame_track = (frame_track + 1) % 4;
      faults++;
    }
    
  } 
  printf("FIFO Faults: %d\n", faults);

  //LRU
  faults = 0;
  frame_array = {-1,-1,-1,-1};
  //Optimal Page Replacement

  
  return 0;
}
