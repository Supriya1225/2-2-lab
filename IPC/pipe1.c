#include <stdio.h>
#include <unistd.h>
int main() {
int pipefds[2];
int returnvalue;
char writemsgs[2][20]={"Hi","Hello"};
char readmsg[20];
returnvalue = pipe(pipefds);
if (returnvalue == -1) {
printf("Unable to create pipe\n");
return 1;
}
printf("Writing-Msg1 is %s\n", writemsgs[0]);
write(pipefds[1], writemsgs[0], sizeof(writemsgs[0]));

read(pipefds[0], readmsg, sizeof(readmsg));
printf("Reading-Msg1 is %s\n", readmsg);
printf("Writing-Msg2 is %s\n", writemsgs[0]);
write(pipefds[1], writemsgs[1], sizeof(writemsgs[0]));
read(pipefds[0], readmsg, sizeof(readmsg));
printf("Reading-Msg2 is %s\n", readmsg);
return 0;
}
