#include "stack.h"
#include <CUnit/Basic.h>

void test_stack_creation()
{
  stack_t *s = ioopm_stack_create(10);

  CU_ASSERT_FALSE(s == NULL);
  CU_ASSERT_TRUE(ioopm_stack_size(s) == 0);

  ioopm_stack_destroy(s); 
}

void test_stack_size()
{
  stack_t *s = ioopm_stack_create(10);

  CU_ASSERT_TRUE(ioopm_stack_size(s) == 0);
  ioopm_stack_push(s, 0);
  CU_ASSERT_TRUE(ioopm_stack_size(s) == 1);
  ioopm_stack_push(s, 0);
  CU_ASSERT_TRUE(ioopm_stack_size(s) == 2);
  ioopm_stack_pop(s);
  CU_ASSERT_TRUE(ioopm_stack_size(s) == 1);
  ioopm_stack_pop(s);
  CU_ASSERT_TRUE(ioopm_stack_size(s) == 0);

  ioopm_stack_destroy(s); 
}

void test_stack_push_pop()
{
  stack_t *s = ioopm_stack_create(10);
  const int values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int i = sizeof(values) / sizeof(values[0]); i > 0; --i)
    {
      ioopm_stack_push(s, values[i - 1]);
    }

  for (int i = 0; i < sizeof(values) / sizeof(int); ++i)
    {
      CU_ASSERT_TRUE(ioopm_stack_top(s) == values[i]);
      ioopm_stack_pop(s);
    }
    
  ioopm_stack_destroy(s); 
}

void test_stack_top()
{
  stack_t *s = ioopm_stack_create(10);

  ioopm_stack_push(s, 1);
  CU_ASSERT_TRUE(ioopm_stack_top(s) == 1);
  ioopm_stack_push(s, 20);
  CU_ASSERT_TRUE(ioopm_stack_top(s) == 20);
  ioopm_stack_pop(s);
  CU_ASSERT_TRUE(ioopm_stack_top(s) == 1);

  ioopm_stack_destroy(s); 
}

int main(int argc, char *argv[])
{
  // Initialise
  CU_initialize_registry();

  // Set up suites and tests
  CU_pSuite creation = CU_add_suite("Test creation and height", NULL, NULL);
  CU_add_test(creation, "Creation", test_stack_creation);
  CU_add_test(creation, "Size", test_stack_size);
  
  CU_pSuite pushpoptop = CU_add_suite("Test push, pop and top", NULL, NULL);
  CU_add_test(pushpoptop, "Push and pop", test_stack_push_pop);
  CU_add_test(pushpoptop, "Top", test_stack_top);

  // Actually run tests
  CU_basic_run_tests();

  // Tear down
  CU_cleanup_registry();
  return 0;
}

