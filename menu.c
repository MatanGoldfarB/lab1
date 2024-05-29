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

struct fun_desc{
    char *name;
    char (*fun)(char);
};

int main(int argc, char **argv){
    char carray[5] = "";
    struct fun_desc menu[] = {
        {"Get String", my_get},
        {"Print String (cprt)", cprt},
        {"Encrypt", encrypt},
        {"Decrypt", decrypt},
        {"Print Hex (xprt)", xoprt},
        {NULL, NULL}
    };
    
    int menu_size = sizeof(menu) / sizeof(menu[0]) - 1;

    while (1)
    {
        printf("Select operation from the following menu:\n");
        for (int i = 0; menu[i].name != NULL; i++){
            printf("%d) %s\n", i, menu[i].name);
        }
        char input[10];
        if (fgets(input, sizeof(input), stdin) == NULL) 
        {
            printf("Exiting\n");
            break; 
        }
        int choice = atoi(input);
        if (choice >= 0 && choice < menu_size) 
        {
            char *result = map(carray, sizeof(carray), menu[choice].fun);
            strncpy(carray, result, sizeof(carray));
            free(result);
        } 
        else {
            printf("Not within bounds\n");
            break;
        }
       
    }
}
