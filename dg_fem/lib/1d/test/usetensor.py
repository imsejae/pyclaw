
from tensors import dTensor1

tens=dTensor1(5)

tens.set(1,-5.0)
tens.set(2,-11.0)
tens.set(3,-4.0)
tens.set(4,-3.0)
tens.set(5,-2.0)

for i in range(1,6):
 print tens.get(i)
