#include <stdio.h>
#include <unistd.h>
int main()
{
int pipefds1[2],pipefds2[2];
int returnvalue1,returnvalue2;
int pid;
char pipe1writemsg[20]="Hi";
char pipe2writemsg[20]="Hello";
char readmsg[20];
returnvalue1=pipe(pipefds1);
if(returnvalue1==-1)
{
printf("Unable to create pipe1\n");
return 1;
}
returnvalue2=pipe(pipefds2);
if(returnvalue2==-1)
{
printf("Unable to create pipe2\n");
return 1;
}
pid=fork();
if(pid!=0)
{
close(pipefds1[0]);
close(pipefds2[1]);
printf("In Parent:Writing pipe1-Msg is %s\n",pipe1writemsg);
write(pipefds1[1],pipe1writemsg,sizeof(pipe1writemsg));
read(pipefds2[0],readmsg,sizeof(readmsg));
printf("In Parent:Reading pipe2-Msg is %s\n",readmsg);
}
else{
close(pipefds1[1]);
close(pipefds2[0]);
read(pipefds1[0],readmsg,sizeof(readmsg));
printf("In Child:Reading pipe1-Msg is %s\n",readmsg);
printf("In Child:Writing pipe2-Msg is %s\n",pipe2writemsg);
write(pipefds2[1],pipe2writemsg,sizeof(pipe2writemsg));
}
return 0;
}
