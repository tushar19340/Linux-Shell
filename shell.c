#include<stdio.h> 
#include<string.h>
#include<unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{   
    char path[100];
	getcwd(path, 100);

    char history[100][100];
    int commandNo = 0;

    char cwd[100];

    while(1){

        printf("%s ", getcwd(cwd, 100));
        char command[100];
		char commands[100][100];

		scanf("%[^\n]%*c", command);

        strcpy(history[commandNo], command);
        commandNo++;

        int count = 0;
        
		char* token;
		token = strtok(command, " ");

		while(token != NULL){
			strcpy(commands[count], token);
			// printf("token\n");
			// printf("%d\n", count);
			token = strtok(NULL," ");
			count++;
		}
        if(strcmp(commands[0], "cd") == 0){
            
			if(count > 2){
				printf("Invalid no. of arguments");
			}else if(count = 2){
				if(strcmp(commands[1], "~") == 0){
					// p l
					chdir(getenv("HOME"));
					// printf("%s ", getcwd(cwd, 100));
				}else if(strcmp(commands[1], "--help") == 0){
                    printf("cd: used to change the current directory.");
                }else{
					getcwd(cwd, 100);
					chdir(commands[1]);
					// printf("%s ", getcwd(cwd, 100));
				}
			}
		}else if(strcmp(commands[0], "echo") == 0){
			// printf("%d", count);
			if(count == 1){

			}else if(count >= 2){
				if(strcmp(commands[1], "-E") == 0){
					for(int i = 2; i < count; i++){
						printf("%s ", commands[i]);
					}printf("\n");
				}else if(strcmp(commands[1], "-n") == 0){
					for(int i = 2; i < count; i++){
						printf("%s ", commands[i]);
					}
				}else{
                    for(int i = 1; i < count; i++){
						printf("%s ", commands[i]);
					}printf("\n");
                }
			}

		}else if(strcmp(commands[0], "pwd") == 0){
            if(count == 2){
                if(strcmp(commands[1], "--help") == 0){
                    printf("pwd: Used to print current directory.");
                }else if(strcmp(commands[1], "-P") == 0){
                    printf("%s ", getcwd(cwd, 100));
                    printf("\n");
                }else
                {
                    printf("Invalid flag");
                }
            }else{
                printf("%s ", getcwd(cwd, 100));
                printf("\n");
            }

        }else if(strcmp(commands[0], "history") == 0){
            
            if(count >= 2){
                if(strcmp(commands[1], "-c") == 0){
                    commandNo = 0;
                }else if(strcmp(commands[1], "-a") == 0){

                }else{
                    printf("Invalid command.");
                }
            }else{
                for(int i = 0; i < commandNo; i++){
                    printf("%s\n", history[i]);
                }
            }

        }else if(strcmp(commands[0], "exit") == 0){
            exit(1);
        }else if(strcmp(commands[0], "ls") == 0){
            // printf("hello\n");
            pid_t pid;
            pid = fork();

            if(pid == 0){
                char* arguments[count];

            for(int i = 0; i < count; i++){
                arguments[i] = commands[i];
            }
            arguments[count + 1] = NULL;

            execvp(strcat(path,"/ls"), arguments);
            }else if(pid > 0){
                waitpid(pid, NULL, 0);
            }else if(pid < 0){
                printf("Failed to create child process");
            }
        }else if(strcmp(commands[0], "mkdir") == 0){
                pid_t pid;
                pid = fork();
                if(count == 1){
                    printf("mkdir: missing operand\n");
                    printf("Try 'mkdir --help' for more information.\n");
                }else{
                    if(pid == 0){
                        char* arguments[count];

                        for(int i = 0; i < count; i++){
                            arguments[i] = commands[i];
                        }
                        arguments[count + 1] = NULL;
                        execvp(strcat(path,"/mkdir"), arguments);
                    }else if(pid > 0){
                        waitpid(pid, NULL, 0);
                    }else if(pid < 0){
                        printf("Failed to create child process");
                    }

                }
                
        }else if(strcmp(commands[0], "rm") == 0){
            pid_t pid;
            pid = fork();

            if(pid == 0){
                char* arguments[count];

            for(int i = 0; i < count; i++){
                arguments[i] = commands[i];
            }
            arguments[count + 1] = NULL;

            execvp(strcat(path,"/rm"), arguments);
            }else if(pid > 0){
                waitpid(pid, NULL, 0);
            }else if(pid < 0){
                printf("Failed to create child process");
            }
            
        }else{
            printf("Invalid command!!\n");
        }
    }
    return 0;
}
