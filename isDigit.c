#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int isDigito(char* str){
  int count = 0;
  while(str[count]!='\0'){
    if(str[count]>='0' && str[count]<='9'){
      count++;
    }else{
      return false;
    }
  }
  return true;
}
