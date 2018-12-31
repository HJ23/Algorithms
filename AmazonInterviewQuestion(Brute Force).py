
###########  NOT EFFICIENT AND HARD WAY TO SOLVE MAX AREA OF HISTOGRAM PROBLEM
###########  TIME COMPLEXITY IS O(N^2) -->VERY BAD
import time
#find the max area in histogram
data=[1,2,3,4,5,1,2,1,2,5,4,5,5,2,2,3,1,2,4,5,3,2,5,3,5,7,4,2,4,6,3]
start=time.time()
area=[]
for x in range(0,len(data)):
    temp=[]
    for y in range(x,len(data)):
        temp.append(data[y])
        area.append(len(temp)*min(temp))

print("MAX area is:")
print(max(area))
print(time.time()-start)
