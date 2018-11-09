




global px
global py
global prime
prime=3
primex=input("odd number >>>")
primex=int(primex)
px=int(int(primex)/2)
py=int(int(primex)/2)

t=1
def run(prime,t):
      global px
      global py
     
      data[px][py]=t
      t=t+1
      py=py+1
      data[px][py]=t
      for x in range(1,prime-1):
            t=t+1
            px=px+1
            data[px][py]=t
      for x in range(1,prime):
            t=t+1
            py=py-1
            data[px][py]=t
      for x in range(1,prime):
            t=t+1
            px=px-1
            data[px][py]=t
      for x in range(1,prime):
            t=t+1
            py=py+1
            data[px][py]=t
      if(prime!=primex):
            prime+=2
            run(prime,t)
      

data=[]
for x in range(0,primex):
      data.append([])
      for y in range(0,primex):
         data[x].append(0)

run(prime,t)

s=""
for x in range(0,primex):
      for y in range(0,primex):
         s=s+"   "+str(data[x][y])
      s=s+"\n"
print(s)












































