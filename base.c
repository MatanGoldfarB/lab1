#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  if(mapped_array == NULL){
    return NULL;
  }
  for(int i=0; i<array_length; i++){
    mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

char my_get(char c){
  char ch = fgetc(stdin);
  return ch;
}

char cprt(char c){
  if(c>=0x20 && c<=0x7E){
    printf("%c\n", c);
  }
  else{
    printf(".\n");
  }
  return c;
}

char encrypt(char c){
  if(c>=0x20 && c<=0x4E){
    return c+0x20;
  }
  return c;
}

char decrypt(char c){
  if(c>=0x40 && c<=0x7E){
    return c-0x20;
  }
  return c;
}

char xoprt(char c){
  printf("%02X ", c);
  printf("%03o\n", c);
  return c;
}
 
int main(int argc, char **argv){
  /* TODO: Test your code */
}

