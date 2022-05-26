#include <stdio.h>
#include <unistd.h>
int main() {
int pipefds[2];
int returnvalue;
int pid;
char writemsgs[2][20]={"Hi","Hello"};
char readmsg[20];
returnvalue = pipe(pipefds);
if (returnvalue == -1) {
printf("Unable to create pipe\n");
return 1;
}
pid = fork();
if (pid == 0) {
read(pipefds[0], readmsg, sizeof(readmsg));
printf("Reading – msg 1 is %s\n",readmsg);
read(pipefds[0], readmsg, sizeof(readmsg));
printf("Reading – msg 2 is %s\n",readmsg);
} 
else { 
printf("Writing - Msg 1 is %s\n",writemsgs[0]);
write(pipefds[1], writemsgs[0], sizeof(writemsgs[0]));
printf("Writing - Msg 2 is %s\n",writemsgs[1]);
write(pipefds[1], writemsgs[1], sizeof(writemsgs[1]));
}
return 0;
}
