#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
FILE *rd;
char buffer[50];
rd=popen("ls","r"); //pipe opened in reading mode
fread(buffer, 1, 40, rd); //will read only 50 characters
printf("%s\n", buffer);
pclose(rd);
}

/*In this case, we establish the pipe between “ipc2.c” and “ls”. Since, the data will be read, hence, the pipe is opened in reading mode “r”. ls sends the data through the pipe. 
This data will be read by ipc2.c. So, this time our program is the one receiving the data.ls will send the list of files in current working directory. ipc2.c will read that, save it 
in buffer and then finally print it. */