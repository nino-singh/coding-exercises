#include "list_tests.h"
#include "queue_tests.h"
#include "stack_tests.h"
#include "bst_tests.h"
#include "bt_tests.h"

int main(int argc, char *argv[])
{
  //run_list_tests();
  //run_queue_tests();
  //run_stack_tests();
  //run_bt_tests();
  run_bst_tests();

  typedef union ctrlreg{

    //4 byte (word) bitfield
    struct {
      uint32_t nPRIV:1; //specify length of first regiion  of bitfield - 1bit
      uint32_t SPSEL:1; //Next region is 1 bit
      uint32_t FPCA: 1; //next region is 1 bit
      uin32_t reserved:29; //last region is 29 bits
    } b;

    uint32_t w; //Set a value equal to entire word

  } CtrlReg_t;

  CtrlReg_t controlReg;

  controlReg.w = 0x0000000000;
  controlReg.b.nPRIV = 0;

  return 0;
}
