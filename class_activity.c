#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("start pid: %d parent pid: %d\n", getpid(), getppid());
  int pid = fork();
  if (pid == 0) {
    printf("child : PID: %d, PARENT: %d\n", pid, getppid());
  } else if (pid > 0) {
    printf("parent: PID: %d, CHILD: %d", getpid(), pid);
  } else {
    printf("fork failed\n");
    return 1;
  }

  fprintf(stdout, "done");
  return 0;
}
