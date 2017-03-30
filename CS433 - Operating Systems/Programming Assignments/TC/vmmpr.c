//*******************************************************************************
//Ramzi El-abdallah
//Assignment 5 - Page Replacement Algorithms
//December 10, 2016
//CS433 - Operating Systems
//Description: Enter in page numbers on command line following the execution file and
//             program will sort through and display before and after for First in
//             first out, Last Recently used and Optimal page replacement.
//*******************************************************************************

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if(argc>40){
    printf("Reference string needs to be below 40");
    return 1;
  }
  
  //FIFO
  int frame[3] = {-1,-1,-1}; 
  int cnt=0,i,j,flag;
  int hitcnt=0; //fault counter
  printf("FIFO: \n");
  for(i=1;i<argc;i++)
    {
      flag=0;
      //Search function to see if value is in array
      for(j=0;j<3;j++){
        if(frame[j]==atoi(argv[i]))
          {
            flag=1;
          }
      }
      //If value is not in array, this adds the new value
      if(flag==0)
        {
          hitcnt++; //counts fault
          printf("\tBefore :\t"); //displays what is in array before adding new value
          for(j=0;j<3;j++)
	    printf(" %d",frame[j]);
          printf("\t");
          frame[cnt]=atoi(argv[i]); //adds new value to array
          cnt++; //increment array pointer
          if(cnt>=3) //ristricts array pointer to 0-2
            cnt=0;
          printf("\tAfter :\t"); //displays what is in array after adding new value
          for(j=0;j<3;j++)
	    printf(" %d",frame[j]);
          printf("\n");
        }
    }
  printf("Faults = %d \n\n",hitcnt-3); //display number of faults
  
  //LRU
  int frame2[3]={-1,-1,-1};
  int used[3]={-1,-1,-1};
  cnt=0; 
  i=0;
  j=0;
  flag = 0;
  int index,value;
  hitcnt=0;
  printf("LRU: \n");
  for(i=1;i<argc;i++)
    {
      flag=0;
      for(j=0;j<3;j++)
	if(frame2[j]==atoi(argv[i]))
	  {
	    flag=1;
	    used[j]=cnt;
	    break;
	  }
      if(flag==0)
	{
	  hitcnt++;
	  printf("\tBefore :\t");
	  for(j=0;j<3;j++)
	    printf(" %d",frame2[j]);
	  //Replacement
	  index=0;
	  value=used[0];
	  if(cnt!=0) {
	    for(j=0;j<3;j++)
	      if(value>used[j]&&value!=used[j])
		{
		  index=j;
		  value=used[j];
		}
	  }
	  frame2[index]=atoi(argv[i]);
	  used[index]=cnt;
	  printf("\tAfter :\t");
	  for(j=0;j<3;j++)
	    printf(" %d",frame2[j]);
	  printf("\n");
	}
      cnt++;
    }
  printf("Faults = %d \n\n",hitcnt-3);
  
  //Optimal
  int z = 0;
  while(z <3){
    frame[z]=-1;
    used[z]=-1;
    z++;
  }
  cnt=0;
  i=0;
  j=0;
  flag=0;
  int val1,val2,val3;
  index = 0;
  hitcnt=0;
  printf("Optimal \n");
  for(i=1;i<argc;i++)
    {
      flag=0;
      for(j=0;j<3;j++)
	if(frame[j]==atoi(argv[i]))
	  {
	    flag=1;
	    break;
	  }
      if(flag==0)
	{
	  hitcnt++;
	  if(cnt<3)
	    {
	      frame[cnt]=atoi(argv[i]);
	      cnt++;
	    }
	  else
	    {
	      printf("\tBefore :\t");
	      for(j=0;j<3;j++)
		printf(" %d",frame[j]);
	      //selection
	      val1=frame[0];
	      flag=0;
	      for(j=i;j<argc;j++)
		if(atoi(argv[j])==val1)
		  {
		    val1=j;
		    flag=1;
		    break;
		  }
	      if(flag==0)
		val1=argc;
	      val2=frame[1];
	      flag=0;
	      for(j=i;j<argc;j++)
		if(atoi(argv[j])==val2)
		  {
		    val2=j;
		    flag=1;
		    break;
		  }
	      if(flag==0)
		val2=argc;
	      val3=frame[2];
	      flag=0;
	      for(j=i;j<argc;j++)
		if(atoi(argv[j])==val3)
		  {
		    val3=j;
		    flag=1;
		    break;
		  }
	      if(flag==0)
		val3=argc;
	      if(val1<val2)
		if(val3<val2)
		  index=1;
		else
		  index=2;
	      else
		if(val3<val1)
		  index=0;
		else
		  index=2;
	      
	      frame[index]=atoi(argv[i]);
	      printf("\tAfter :\t");
	      for(j=0;j<3;j++)
		printf(" %d",frame[j]);
	      printf("\n");
	    }
	}
    }
  printf("Faults = %d \n\n",hitcnt-3);
  return 0;
}


