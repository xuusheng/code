#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 256

struct Tnode
{
     char v;
     struct Tnode *left, *right;
};


struct Tnode* newnode()
{
     struct  Tnode* u = (struct Tnode*) malloc(sizeof(struct Tnode));
     if (u)
	  u->left = u->right = NULL;
     return u;
}

void remove_tree(struct Tnode *tree)
{
     if(tree == NULL)
	  return;
     remove_tree(tree->left);
     remove_tree(tree->right);
     free(tree);
}

void build_tree(struct Tnode** u, char* x, char* y, int len)
{
     if(len == 0)
	  return;
     int len_l, len_r;
     *u = newnode();
     (*u)->v = x[0];
     len_l = strchr(y, x[0]) - y;
     len_r = len - len_l - 1;
     
     build_tree(&(*u)->left, x + 1, y, len_l);
     build_tree(&(*u)->right, x + len_l + 1, y + len_l + 1, len_r);
}

void post_order(struct Tnode* root)
{
     if(root == NULL)
	  return;
     post_order(root->left);
     post_order(root->right);
     printf("%c", root->v);
}

int main(int argc, char *argv[])
{
     struct Tnode* root;

     char x[MAXN], y[MAXN];
     FILE *fp;
     int len;
     fp = fopen("bt_order.in", "r");
     fscanf(fp, "%s%s", x, y);
     fclose(fp);

     len = strlen(x);
     
     build_tree(&root, x, y, len);
     post_order(root);
     printf("\n");

     remove_tree(root);
     
     return 0;
}
