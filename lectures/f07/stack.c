//#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stack_t *ioopm_stack_create(int maxsize)
{
  stack_t *result = malloc((2+maxsize)*sizeof(int));
  if (result)
    {
      *result = (stack_t) { .height = 0, .maxsize = maxsize };
    }
  return result;
}

void ioopm_stack_destroy(stack_t *s)
{
  free(s);
}

int ioopm_stack_top(stack_t *s)
{
  return s->values[s->height-1];
}

int ioopm_stack_size(stack_t *s)
{
  return s->height;
}

bool ioopm_stack_push(stack_t *s, int v)
{
  if (s->height < s->maxsize)
    {
      s->values[s->height++] = v;
      return true;
    }
  else
    {
      return false;
    }
}

bool ioopm_stack_pop(stack_t *s)
{
  if (s->height > 0)
    {
      s->height--;
      return true;
    }
  else
    {
      return false;
    }
}

  
