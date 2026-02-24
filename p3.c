/*pipe() function creates a unidirectional pipe for IPC. On success it return two file descriptors pipefd[0] and pipefd[1]. pipefd[0] is the reading end of the pipe. So, the process which will receive the data should use this file descriptor. 
pipefd[1] is the writing end of the pipe. So, the process that wants to send the data should use this file descriptor.The program below creates a child process. The parent process will establish
 a pipe and will send the data to the child using writing end of the pipe and the child will receive that data and print on the screen using the reading end of the pipe.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd); //creates a unidirectional pipe with two end fd[0] and fd[1]
p=fork();
if(p>0) //parent
{
printf("Parent Passing value to child\n");
write(fd[1],"hello\n",6); //fd[1] is the write end of the pipe
wait(1);
}
else // child
{
printf("Child printing received value\n");
n=read(fd[0],buffer,100); //fd[0] is the read end of the pipe
write(1,buffer,n);
}
}

/*The parent process create a pipe using pipe(fd) call and then creates a child process using fork(). Then the parent sends the data by writing to the writing end of the pipe by using the fd[1]
 file descriptor. The child then reads this using the fd[0] file descriptor and stores it in buffer. Then the child prints the received data from the buffer onto the screen.*/