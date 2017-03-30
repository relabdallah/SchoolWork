#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  //FIFO
  int frame[3] = {-1,-1,-1};
  int cnt=0,i,j,flag;
  int hitcnt=0;
  printf("FIFO: \n");
  for(i=1;i<argc;i++)
    {
      flag=0;
      for(j=0;j<3;j++){
        if(frame[j]==atoi(argv[i]))
          {
            flag=1;
          }
      }

      if(flag==0)
        {
          hitcnt++;
          printf("\tBefore :");
          for(j=0;j<3;j++)
	    printf(" %d",frame[j]);
          printf("\t");
          frame[cnt]=atoi(argv[i]);
          cnt++;
          if(cnt>=3)
            cnt=0;
          printf("\tAfter :\t");
          for(j=0;j<3;j++)
	    printf("%d",frame[j]);
          printf("\n");
        }
    }
  printf("Faults = %d \n",hitcnt-3);
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
	    printf(" %d ",frame2[j]);
	  //selection of victim for replacement
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
	  //printf("\tVictim is %d ",index);
	  frame2[index]=atoi(argv[i]);
	  used[index]=cnt;
	  printf("\tAfter :\t");
	  for(j=0;j<3;j++)
	    printf(" %d ",frame2[j]);
	  printf("\n");
	}
      cnt++;
    }
  printf("Faults = %d \n ",hitcnt-3);
  return 0;
}

