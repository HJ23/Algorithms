import math
import time
data1=[]
data2=[False,False]
number=input("number for limit>>>")
number=int(number)
start=time.time()
for yu in range(2,number+1):
    data2.append(True)
for y in range(2,int(math.sqrt(number))+1):
    m=0
    for z in range(2,y):
        if(y%z==0):
            m+=1
            break
    if(m==0):
        for yu in range(2,int(number/y)+1):

            data2[y*yu]=False
    else:
        data2[y]=False
n=0
for yu in range(0,len(data2)):
    if(data2[yu]):
        n+=1
print("total time:"+str(time.time()-start))
print(str(n))

































