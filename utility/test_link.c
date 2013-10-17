#include <stdio.h>
#include <stdlib.h>

struct list
{
  struct list *next;
  int i;
};
typedef struct list list_t;

int
main ()
{
  list_t *p = NULL, **pp;

  pp = &p;
  while (*pp)
    pp = (list_t **) * pp;

  *pp = malloc (sizeof (list_t));
  (*pp)->i = 2;
  (*pp)->next = NULL;

  return 0;
}
