#include "list_tests.h"
#include "queue_tests.h"
#include "stack_tests.h"

int main(int argc, char *argv[])
{
  run_list_tests();
  run_queue_tests();
  run_stack_tests();

  return 0;
}
