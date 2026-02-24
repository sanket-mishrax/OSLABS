#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
FILE *rd;
char buffer[50];
sprintf(buffer,"penguins in arctic");
rd=popen("wc -c","w"); // wc -c -> is the process which counts the number of characters passed. 2nd parameter is "w" which means pipe is opened in writing mode
fwrite(buffer,sizeof(char),strlen(buffer),rd); // to write the data into the pipe
pclose(rd);
}

/*There are two programs “ipc1.c” (which will send the data) and “wc” command(which will receive the data). As the data will be sent to another process, so the mode of opening the pipe is
 writing mode “w”. popen() establishes the pipe between ipc1.c and wc. fwrite() function writes data into this pipe. ipc1.c stores some data in the buffer, then it connects with “wc” using popen. 
 Finally, the fwrite() function writes data into the pipe. The data is received by “wc” which then counts the number of characters in the input and prints it*/