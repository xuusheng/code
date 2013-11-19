#include <stdio.h>
#include <unistd.h>

int main(void)
{
  printf("%s\n", ttyname(0));
  printf("%s\n", ttyname(1));
  printf("%s\n", ttyname(2));

  //Bug: 此程序认为eshell是一个伪终端，在eshell下执行此程序，将打印出第
  //一个尚未分配的伪终端文件名，实际上此文件名所指的文件并不存在。
}

