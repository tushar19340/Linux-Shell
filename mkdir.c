#include <sys/stat.h> 
#include <sys/types.h>
#include<stdio.h> 
#include<string.h> 

int main(int argc, char const *argv[])
{   
    int check;
    // check = mkdir(argv[1],0777);
    // printf("%d", argc);
    if((argc - 1) == 3){

        if(strcmp(argv[1], "-p") == 0){
            check = mkdir(argv[1],0777);   
        }else if(strcmp(argv[2], "-v") == 0){
            check = mkdir(argv[1],0777); 
            if(!check ){
                printf("mkdir: created directory ' %s'", argv[1]);
                printf("\n");
            }else{
                printf("mkdir: cannot create directory '%s' : File exists", argv[1]);
                printf("\n");
            }
        }

    }else{
        check = mkdir(argv[1],0777); 
        if(!check ){

        }else{
            printf("mkdir: cannot create directory '%s' : File exists", argv[1]);
            printf("\n");
        }

    }

    
    return 0;
}
