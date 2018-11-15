import math
import time
limit=1000000
data1=[False,False]
data2=[]
data3=[]
for x in range(2,limit+1):
        data1.append(True)
m=0
def run(tr):
        global data1,data2,m
        for t in range(2,int(math.sqrt(limit))):
                if(data1[t]):
                        for y in range(2,t):
                                m=0
                                if(t%y==0):
                                        m+=1
                                        break
                        if(m==0):
                                for xx in range(2,int((limit)/t)+1):
                                        data1[xx*t]=False
                        
                        
                        
start=time.time()
run(1)
n=0
mmm=0
print(data1[2])
for y in range(2,len(data1)):
        if(data1[y]):
                mum=0
                kk=""
                if(len(str(y))==1 ):
                        continue
                for xc in range(0,len(str(y))):
                        kk=str(y)[len(str(y))-xc-1]+kk  #23
                        
                        if(data1[int(kk)]):
                                
                                        
                                mum+=1
                        else:
                                break
                       
                                
                if(mum==len(str(y))):
                        tut=0
                        kk=""
                        mum=0
                        for xc in range(0,len(str(y))):
                                kk=kk+str(y)[xc]  #1234  
                             
                                if(data1[int(kk)]):
                                        mum+=1
                                else:
                                        break
                        if(mum==len(str(y))):
                                mmm=mmm+y

print(mmm)

                
