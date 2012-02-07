
from tensors import dTensor1,iTensor1,dTensorBC1,dTensor2,iTensor2,dTensorBC2,dTensor3,iTensor3,dTensorBC3,dTensor4,dTensorBC4
from tensors import SumOperator

tens=dTensor1(5)

tens.set(1,-5.0)
tens.set(2,-11.0)
tens.set(3,-4.0)
tens.set(4,-3.0)
tens.set(5,-2.0)

for i in range(1,6):
 print tens.get(i)
b=SumOperator(tens)
print "Sum=?",b

tens=iTensor1(5)

tens.set(1,5)
tens.set(2,11)
tens.set(3,4)
tens.set(4,3)
tens.set(5,2)

tens=dTensorBC1(4,1)

tens.set(0,5.0)
tens.set(1,4.0)
tens.set(2,3.0)
tens.set(3,2.0)
tens.set(4,1.0)
tens.set(5,0.0)


for i in range(1,7):
 print "BC1=",tens.get(i-1)

print "end 1d test"
tens=dTensor2(2,2)

tens.set(1,1,-5.0)
tens.set(1,2,-4.0)
tens.set(2,1,-3.0)
tens.set(2,2,-2.0)

for i in range(1,3):
 for j in range(1,3):
   print tens.get(i,j)

tens=iTensor2(2,2)

tens.set(1,1,-5.0)
tens.set(1,2,-4.0)
tens.set(2,1,-3.0)
tens.set(2,2,-2.0)

for i in range(1,3):
 for j in range(1,3):
   print tens.get(i,j)

tens=dTensorBC2(2,2,1)
tens.set(0,1,-4.0)
tens.set(1,0,-4.0)
tens.set(1,1,-5.0)
tens.set(1,2,-4.0)
tens.set(2,1,-3.0)
tens.set(2,2,-2.0)
tens.set(3,2,-1.0)

for i in range(1,4):
 for j in range(1,4):
   print "BC2=",tens.get(i-1,j-1)

print "end 2d test"
tens=dTensor3(2,2,2)

tens.set(1,1,1,-5.0)
tens.set(1,2,1,-4.0)
tens.set(2,1,1,-3.0)
tens.set(2,2,1,-2.0)
tens.set(1,1,2,-5.0)
tens.set(1,2,2,-4.0)
tens.set(2,1,2,-3.0)
tens.set(2,2,2,-2.0)

for i in range(1,3):
 for j in range(1,3):
  for k in range(1,3):
   print tens.get(i,j,k)

tens=iTensor3(2,2,2)

tens.set(1,1,1,-5.0)
tens.set(1,2,1,-4.0)
tens.set(2,1,1,-3.0)
tens.set(2,2,1,-2.0)
tens.set(1,1,2,-5.0)
tens.set(1,2,2,-4.0)
tens.set(2,1,2,-3.0)
tens.set(2,2,2,-2.0)

for i in range(1,3):
 for j in range(1,3):
  for k in range(1,3):
   print tens.get(i,j,k)

tens=dTensorBC3(2,2,2,1)
tens.set(0,1,1,-6.0)
tens.set(0,1,2,-6.0)
tens.set(0,2,1,-6.0)
tens.set(0,2,2,-6.0)
tens.set(1,1,1,-5.0)
tens.set(1,2,1,-4.0)
tens.set(2,1,1,-3.0)
tens.set(2,2,1,-2.0)
tens.set(1,1,2,-5.0)
tens.set(1,2,2,-4.0)
tens.set(2,1,2,-3.0)
tens.set(2,2,2,-2.0)
tens.set(3,2,2,-1.0)
tens.set(3,1,2,-1.0)
tens.set(3,2,1,-1.0)
tens.set(3,1,1,-1.0)

for i in range(0,4):
 for j in range(1,3):
  for k in range(1,3):
   print "BC3=",tens.get(i,j,k)

print "end 3d test"
tens=dTensor4(2,2,2,2)

tens.set(1,1,1,1,-5.0)
tens.set(1,2,1,1,-4.0)
tens.set(2,1,1,1,-3.0)
tens.set(2,2,1,1,-2.0)
tens.set(1,1,2,1,-5.0)
tens.set(1,2,2,1,-4.0)
tens.set(2,1,2,1,-3.0)
tens.set(2,2,2,1,-2.0)
tens.set(1,1,1,1,-5.0)
tens.set(1,2,1,1,-4.0)
tens.set(2,1,1,1,-3.0)
tens.set(2,2,1,1,-2.0)
tens.set(1,1,2,1,-5.0)
tens.set(1,2,2,1,-4.0)
tens.set(2,1,2,1,-3.0)
tens.set(2,2,2,1,-2.0)

for i in range(1,3):
 for j in range(1,3):
  for k in range(1,3):
   for kj in range(1,2):
    print tens.get(i,j,k,kj)

tens=dTensorBC4(2,2,2,2,1)
tens.set(0,1,1,1,-5.0)
tens.set(0,2,1,1,-4.0)
tens.set(3,1,1,1,-3.0)
tens.set(3,2,1,1,-2.0)
tens.set(0,1,2,1,-5.0)
tens.set(0,2,2,1,-4.0)
tens.set(3,1,2,1,-3.0)
tens.set(3,2,2,1,-2.0)
tens.set(0,1,1,1,-5.0)
tens.set(0,2,1,1,-4.0)
tens.set(3,1,1,1,-3.0)
tens.set(3,2,1,1,-2.0)
tens.set(0,1,2,1,-5.0)
tens.set(0,2,2,1,-4.0)
tens.set(3,1,2,1,-3.0)
tens.set(3,2,2,1,-2.0)

tens.set(1,1,1,1,-5.0)
tens.set(1,2,1,1,-4.0)
tens.set(2,1,1,1,-3.0)
tens.set(2,2,1,1,-2.0)
tens.set(1,1,2,1,-5.0)
tens.set(1,2,2,1,-4.0)
tens.set(2,1,2,1,-3.0)
tens.set(2,2,2,1,-2.0)
tens.set(1,1,1,1,-5.0)
tens.set(1,2,1,1,-4.0)
tens.set(2,1,1,1,-3.0)
tens.set(2,2,1,1,-2.0)
tens.set(1,1,2,1,-5.0)
tens.set(1,2,2,1,-4.0)
tens.set(2,1,2,1,-3.0)
tens.set(2,2,2,1,-2.0)

for i in range(0,4):
 for j in range(1,3):
  for k in range(1,3):
   for kj in range(1,2):
    print "BC4=",tens.get(i,j,k,kj)



print "end 4d"
