/* 
 * File:   grsh.c
 * Author: Alex
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * 
 */

int cd(char **tokens);
int builtin_exit(char **tokens);
char error_message[30] = "An error has occurred\n";
char prompt[30] = "grsh> ";
int pathEmpty=0;
char multiPath[512][512];
int numberMultiPath=0;
int pathChanged=0;
char *path;
int parallel;

char *builtin_str[] = {
    "cd",
    "exit",
    "path"
};

void printPrompt(){
    printf("grsh> ");
}


char *read_line(void)
{
  size_t bufsize = 1024;
  int characters;
  char *buffer = malloc(sizeof(char) * bufsize);
  

  if (!buffer) {
    write(STDERR_FILENO, error_message, strlen(error_message)); 
    exit(-1);
  }

  while (1) {
    
    characters = getline(&buffer, &bufsize, stdin);
    char *temp_buffer = malloc(sizeof(char)* bufsize);
    strcpy(temp_buffer, buffer);
    if(temp_buffer[0] != 0 && temp_buffer[0] != '\n'){
        char *command[sizeof(temp_buffer)];
        command[0] = strtok(temp_buffer, " \t\r\n\f\v");
        int p=0;
        while(command[p]!=NULL){
            p++;
            command[p]=strtok(NULL, " \t\r\n\f\v");

        }
        command[p+1]=NULL;
        if(strcmp(command[0], "path") == 0){
            pathChanged = 1;
            if(p==2){
                pathEmpty = 0;
                path = strdup(command[1]);
                if(path[strlen(path)-1]!= '/'){
                    strcat(path, "/");
                }
            }
            else if(p ==1){
                pathEmpty = 1;
            }
            else{
                pathEmpty = 0;
                for(int i =1; i<p; i++){
                    char *temp=strdup(command[i]);
                    if(temp[strlen(temp)-1]!='/')
                        strcat(temp,"/");
                        strcpy(multiPath[i-1],temp);
                        numberMultiPath++;
                }
            }
        }
        else if (strcmp(command[0], "exit") == 0){
            exit(0);
        }
        else if(strcmp(command[0],"cd") == 0){
            if(p==2){
                if(chdir(command[1])!=0){
                    write(STDERR_FILENO, error_message, strlen(error_message));

                }
            }
            else{ //0 Arguments or more than 2 arguments?
                write(STDERR_FILENO, error_message, strlen(error_message));

            }
        } 
        else{
            return buffer;
        }
    }
    
    return buffer;

    
  }
}

char **split_line(char *line){
    int bufsize = 64, position = 0;
    char *token, **token_temp;
    char **tokens = malloc(bufsize * sizeof(char*));
    
    if(!tokens){
        write(STDERR_FILENO, error_message, strlen(error_message)); 
        exit(-1);
    }
    
    token = strtok(line, " \t\r\n\f\v");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            token_temp = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        if (!tokens) {
            free(token_temp);
            write(STDERR_FILENO, error_message, strlen(error_message)); 
            exit(-1);
      }
    }
    token = strtok(NULL, " \t\r\n\f\v");
  }
  tokens[position] = NULL;
  return tokens;
    
}

int launch(char **tokens)
{
    int pid;
    int status;
    if(strcmp(tokens[0],"path") == 0){
        return 1;
    }

    pid = fork();
    if(pid < 0) {
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
    else if (pid == 0 && pathEmpty !=1) {
        if(pathChanged==0){
            path=strdup("/bin/");
            path=strcat(path,tokens[0]);
            if(access(path,X_OK)!=0 && pathChanged==0){
                path=strdup("/usr/bin/");
                path=strcat(path,tokens[0]);
                if(access(path,X_OK)!=0){
                    write(STDERR_FILENO, error_message, strlen(error_message));
                    exit(-1);
                }
            }             
        }
        else if(pathChanged==1 && numberMultiPath == 0){
            path = strcat(path, tokens[0]);
            if (access(path,X_OK)!=0){
                write(STDERR_FILENO, error_message, strlen(error_message));
                exit(-1);
            }
        }
        else{
            for(int i = 0; i<numberMultiPath; i++){
                strcat(multiPath[i], tokens[0]);
                if(access(multiPath[i],X_OK) == 0){
                    strcpy(path,multiPath[i]);
                    break;
                }
            }
        }
        if(execv(path,tokens)== -1){
            write(STDERR_FILENO, error_message, strlen(error_message));
            exit(-1);
        }  
    }
    else if (pid == 0 && pathEmpty ==1) {
        write(STDERR_FILENO, error_message, strlen(error_message));
        exit(-1);
    }
    else if (pid > 0 && parallel == 1){
        return pid;
    }
    else{
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
   
  return pid;
}

int execute(char **tokens)
{
    int i;
    if (tokens[0] == NULL){
        return 1;
    }
    
    for(i = 0; i < 2; i++ ){
        if(strcmp(tokens[0],builtin_str[i]) == 0){
            return 1;
        }
    }
    
    return launch(tokens);
}



int main(int argc, char** argv) {
   if(argc == 1){
    char *line;
    char **tokens;
    int status;
    status = 1;
    parallel = 0;
    do{
        if(parallel == 0){
            printPrompt();
        }
        line = read_line();
        if(strstr(line, "&")!= NULL){
            int j=0;
            parallel = 1;
            char *mytokens[sizeof(line)];
            mytokens[0] = strtok(line, "\n\t&");
            while(mytokens[j] != NULL){
                j++;
                mytokens[j] = strtok(NULL, "\n\t&");
            }
            mytokens[j+1] = NULL;
            int pid[j];
            for(int i = 0;i< j; i++){
                tokens = split_line(mytokens[i]);
                pid[i] = execute(tokens);
                for(int x = 0; x<j; x++){
                    int returnStatus = 0;
                    waitpid(pid[x], &returnStatus, 0);
                    if(returnStatus == 1)
                    {
                        write(STDERR_FILENO, error_message, strlen(error_message));
                    }
                }
            }
        parallel = 0;  
        }
        else{
            tokens = split_line(line);
            execute(tokens); 
        }
        
        free(line);
        free(tokens);
    }
    while(status); 
   }
   else if(argc == 2){
	FILE *fp;
	char line[1024];
	char **tokens;
        int status;
        char *file= strdup(argv[1]);
	fp = fopen(file, "r");
	if(fp == NULL){
            return 1;
	}
        else{
            while(fgets(line, sizeof(line), fp) != NULL){
		tokens = split_line(line);
		status = execute(tokens);
	    }
	}
	free(tokens);
	fclose(fp);

	}else{
            write(STDERR_FILENO, error_message, strlen(error_message));
	}
    
    
    return (EXIT_SUCCESS);
}