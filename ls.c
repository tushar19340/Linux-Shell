#include<stdio.h> 
#include<string.h>
#include<unistd.h> 
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{   
    // printf("\n");
    struct dirent *dir; 
     
    if((argc - 1) == 1){
        DIR *direc = opendir(".");
        while ((dir = readdir(direc)) != NULL) 
                printf("%s  ", dir->d_name);

        closedir(direc);
    }else if((argc - 1) == 3){
        DIR *direc = opendir(argv[1]);

        if(strcmp(argv[2], "-m") == 0){
            while ((dir = readdir(direc)) != NULL) 
                printf("%s, ", dir->d_name);

        }else if(strcmp(argv[2], "-1") == 0){
            while ((dir = readdir(direc)) != NULL) 
                printf("%s\n", dir->d_name);

        }else{
            while ((dir = readdir(direc)) != NULL) 
                    printf("%s  ", dir->d_name); 
        }
        closedir(direc);
    }else{
        
        if(strcmp(argv[1], "-m") == 0){
            DIR *direc = opendir(".");
            while ((dir = readdir(direc)) != NULL) {
                printf("%s, ", dir->d_name);
            }
            closedir(direc);

        }else if(strcmp(argv[1], "-1") == 0){
            DIR *direc = opendir(".");
            while ((dir = readdir(direc)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(direc);

        }else{
            DIR *direc = opendir(argv[1]);
            while ((dir = readdir(direc)) != NULL) {
                printf("%s  ", dir->d_name); 
            }
            closedir(direc);
        }
    }


    
    printf("\n");
  
     
    return 0;
}
