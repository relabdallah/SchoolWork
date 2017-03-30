#include<iostream>
#include<stdlib.h>
#define PAGE_SIZE 4096
using namespace std;

int main(int argc, char **argv){
if(argc<2){
cout<<"Enter the address: ";
return -1;
}
unsigned int address = atoi(argv[1]);
unsigned int page_number = address / PAGE_SIZE;
unsigned int offset = address%PAGE_SIZE;
cout<<"the address "<<address<<"contains: Page number = "<<page_number<<"And off set = "<<offset<<endl;
system("pause");
}
