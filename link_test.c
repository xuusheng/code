#include <stdio.h>
#include "link.h"

void print_item(link p)
{
  printf("%c\t", p->item);
}

int main(void)
{
  link p = make_node('X');
  insert(p);
  p = make_node('C');
  insert(p);
  insert (make_node('!'));
  insert (make_node('\n'));
  insert (make_node('b'));
  insert (make_node('a'));
  traverse(print_item);
  p = search ('a');
  delete(p);
  free_node(p);
  traverse(print_item);
  destroy();

  push(make_node('\n'));
  p = make_node('e');
  push(p);
  p = make_node('v');
  push(p);
  p = make_node('o');
  push(p);
  push(make_node('l'));
  while (p = pop()) {
    print_item(p);
    free_node(p);
  }

  return 0;

}
