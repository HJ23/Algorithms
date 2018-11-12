import time
import math
number=input("upper limit>>>")
number=int(number)
def retme(tr):
    data=[]
    for x in range(2,tr):
        m=0
        for y in range(2,x):
            if(x%y==0):
                m+=1
                break
        if(m==1):
            continue
        else:
            data.append(x)
    return data

df=retme(int(math.sqrt(number)))
mm=max(df)
print(df)
start=time.time()
aka=0             
for y in range(2,number):
    m=0
    for t in range(0,len(df)):
        if(y==df[t]):
            break
        else:
            if(y%df[t]==0):
                m+=1
                break
    if(m==0):
        
        aka+=1
        
print("total>>>"+str(aka))
print(time.time()-start)
