#include<stdio.h>
#include<string.h> 

int main(int argc, char const *argv[])
{   
    if((argc - 1) == 3){
        if(strcmp(argv[2], "-f")){
            if(remove(argv[1]) != 0){}

        }
    }else{
            remove(argv[1]);
        }
    return 0;
}
