#include <stdbool.h>

typedef struct stack stack_t;

struct stack
{
  int height;
  int maxsize;
  int values[0];
};


stack_t *ioopm_stack_create(int maxsize);

void ioopm_stack_destroy(stack_t *s);

int ioopm_stack_top(stack_t *s);

int ioopm_stack_size(stack_t *s);

bool ioopm_stack_push(stack_t *s, int v);

bool ioopm_stack_pop(stack_t *s);


  
