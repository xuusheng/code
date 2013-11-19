/* 双向链表改造 */

/* LinkedList 单向链表 */
#include <stdio.h>	    
#include <stdlib.h>
typedef struct node *link;
struct node
{
     unsigned char item;
     link pre, next;
};

static link head = NULL;
static link head2 = NULL;
static link tail = NULL;
link make_node(unsigned char item)
{
     link p = malloc(sizeof *p);
     p->item = item;
     p->pre = NULL;
     p->next = NULL;
     return p;
}

void free_node(link p)
{
     free(p);
}

link search(unsigned char key)
{
     link p;
     for (p = head; p; p = p->next)
	  if (p->item == key)
	       return p;
     return NULL;
}

/* 在链表的前面增加元素 */
void insert (link p)
{
     if (head)
	  head->pre = p;
     else
	  tail = p;
     p->next = head;
     head = p;
}

void delete(link p)
{
     link *pnext;
     for (pnext=&head; *pnext; pnext=&(*pnext)->next)
	  if (*pnext==p)
	  {
	       *pnext=p->next;
	       return;
	  }
}

void delete2(link p)
{
     
}

/* 这个函数了不得，居然把函数当作参数 */
void traverse (void (*visit)(link))
{
     link p;
     for (p = head; p; p = p->next)
	  visit(p);
}

void destroy(void)
{
     link q, p = head;
     head = NULL;
     while (p)
     {
	  q = p;
	  p = p->next;
	  free_node(q);
     }
}


/* 也是在头部增加 */
void push(link p)
{
     p->next = head;
     head = p;
}

link pop(void)
{
     if (head == NULL)
	  return NULL;
     else
     {
	  link p = head;
	  head = head->next;
	  return p;
     }
}

/* 修改insert函数，实现插入排序的功能 */
/* 排序单链表的折半查找 */

/* 此函数之难在于把一个节点插入到另一个结点之前 */
void insert2 (link p)
{
     if ((head == NULL) || (p->item <= head->item))
     {
	  insert(p);
	  return;
     }
     link q;

     for (q = head; q->next; q = q->next)
     {
	  if (p->item <= (q->next)->item)
	  {
	       p->next=q->next;
	       q->next=p;
	       return;
	  }
     }
     q->next=p;
     p->next=NULL;
}

/* 这段代码写得漂亮，Linus不吾欺也 */
void insert3 (link p)
{
     link *pp;
     for (pp = &head; *pp; pp = &(*pp)->next)
	  if (p->item <= (*pp)->item)
	       break;
     p->next = *pp;
     *pp = p;
}

/* 与insert3相比，多维护一个tail指针 */
void insert4 (link p)
{
     link *pp;
     for (pp = &head; *pp; pp = &(*pp)->next)
	  if (p->item <= (*pp)->item)
	       break;
     p->next = *pp;
     tail = *pp ? tail : p;
     *pp = p;
}

void print_node (link p)
{
     printf("%d ", p->item);
}

/* 反转链表 */
void reverse(void)
{
     link p;
     link t;
     for (p = head; p;)
     {
	  t = p;
	  p = p->next;
	  t->next = head2;
	  head2 = t;
     }
     head = head2;
}

void enqueue(link p)
{
     if (tail == NULL)
     {
	  tail = p;
	  head = p;
     }
     else
     {
	  tail->next = p;
	  tail = p;
     }
}

link dequeue(void)
{
     return pop();
}

void enqueue2(link p)
{
     p->next = head;
     head = p;
}
//从尾部dequeue也是可以的，只不过，需要遍历链表，比较麻烦
link dequeue2(void)
{
     link p;
     link t;
     if ((head == NULL) || (head->next == NULL))
	  return head;
     
     for (p = head; p; p = p->next)
	  if (p->next == tail)
	  {
	       t = tail;
	       tail = p;
	       p->next = NULL;
	       return t;
	  }
}

int main(void)
{
     unsigned char item[10]={1,4,2,8,5,7,3,6,0,9};
     int i;
     for (i = 0; i < 10; i++)
	  insert4(make_node(item[i]));
     traverse(print_node);
     puts("\n");

     dequeue2();
     traverse(print_node);
     puts("\n");

     dequeue2();
     traverse(print_node);
     puts("\n");
     return 0;
}

/* 反转链表，折半查找链表 */

