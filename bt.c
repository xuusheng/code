#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 256

char s[MAXN + 10];
int ans[MAXN];

struct Tnode
{
     int have_value;
     int v;
     struct Tnode *left, *right;
};

struct Tnode *root;

struct Tnode* newnode()
{
     struct  Tnode* u = (struct Tnode*) malloc(sizeof(struct Tnode));
     if (u)
     {
	  u->have_value = 0;
	  u->left = u->right = NULL;
     }
     return u;
}

void remove_tree(struct Tnode *tree)
{
     remove_tree(tree->left);
     remove_tree(tree->right);
     free(tree);
}

void addnode(int v, char* s, int *failed)
{
     int leng = strlen(s);
     struct Tnode* u = root;
     for (int i = 0; i < leng; ++i)
	  if (s[i] == 'L')
	  {
	       if (u->left == NULL)
	       {
		    u->left = newnode();
	       }
	       u = u->left;
	  }
	  else if (s[i] == 'R')
	  {
	       if (u->right == NULL)
	       {
		    u->right = newnode();
	       }
	       u = u->right;
	  }
     if (u->have_value)
     {
	  *failed = 1;
     }
     u->v = v;
     u->have_value = 1;
}

void read_input(int *failed)
{
     root = newnode();
     FILE *fp;
     fp = fopen("bt.in", "r");
     
     for(;;)
     {
	  if(fscanf(fp, "%s", s) != 1)
	       return;
	  if(!strcmp(s, "()"))
	       return;
	  int v;
	  sscanf(&s[1], "%d", &v);
	  addnode(v, strchr(s, ',') + 1, failed);
     }
}

int bfs(int *n)
{
     int front = 0, rear =1;

     struct Tnode* q[MAXN];
     q[0] = root;
     while (front < rear)
     {
	  struct Tnode* u = q[front++];
	  if(!u->have_value)
	       return 1;
	  ans[(*n)++] = u->v;
     
	  if(u->left)
	       q[rear++] = u->left;
	  if(u->right)
	       q[rear++] = u->right;
     }
     return 0;
}


int main(int argc, char *argv[])
{
     int failed = 0;
     int n = 0;

     read_input(&failed);

     if(!failed && !bfs(&n))
     {
	  for (int i = 0; i < n; ++i)
	       printf("%d ", ans[i]);
	  printf("\n");
     }
     else
	  printf("-1\n");
     remove_tree(root);

     return 0;
}
