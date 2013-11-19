#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void sig_alrm(int signo)
{
}

unsigned int mysleep(unsigned int nsecs)
{
  struct sigaction newact, oldact;
  unsigned int unslept;

  newact.sa_handler = sig_alrm;
  sigemptyset(&newact.sa_mask);
  newact.sa_flags = 0;
  sigaction(SIGALRM, &newact, &oldact);

  alarm(nsecs);
  pause();

  unslept = alarm(0);
  sigaction(SIGALRM, &oldact, NULL);

  return unslept;
}

void loop_string(int index, char *new_string,
		 const char *old_string)
{
  int i;
  for (i = 0; i < 24; ++i)
    new_string[i] = old_string[(i+index) % 24];
  new_string[24] = 0;
}
  

int main(void)
{
  int i = 30;
  char new_string[24+1];
  memset(new_string, 0, sizeof(new_string));

  while (i) {
    int unslept = mysleep(2);
    printf("%d\n", unslept);
    
    loop_string(30-i, new_string, "两秒逝矣君學進否");
    printf("%s\n", new_string);
    i-=3;
  }
      
  return 0;
}
