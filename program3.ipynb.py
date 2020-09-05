import math
import numpy as np
import matplotlib.pyplot as plot


seed=[47,89,299,2003,20000]

#given values for lcg
m=2048
b=1
a=1229
seed=0

x=seed

u_prev=[]
u_next=[]

for _ in range(m):
    u=x/m
    
    x=(a*x+b)%m
    
    if(x==seed):
        break
    
    u=float("{:.2f}".format(u))
    u_prev.append(u)
    u=x/m;
    u=float("{:.2f}".format(u))
    u_next.append(u)
    

plot.figure(figsize=(15,15))
plot.scatter(u_prev,u_next,color='g', ec='b')
plot.show()
    


