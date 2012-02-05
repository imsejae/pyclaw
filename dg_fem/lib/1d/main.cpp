#include "tensors.h"

int main()
{
  dTensor1 dtest1(5);
  dTensor2 dtest2(5,5);
  dTensor3 dtest3(5,5,5);
  dTensor4 dtest4(5,5,5,5);

  iTensor1 itest1(5);
  iTensor2 itest2(5,5);
  iTensor3 itest3(5,5,5);

  int mbc = 2;

  dTensorBC1 dtestBC1(5,mbc);
  dTensorBC2 dtestBC2(5,5,mbc);
  dTensorBC3 dtestBC3(5,5,5,mbc);
  dTensorBC4 dtestBC4(5,5,5,5,mbc);

  return 1;
}
