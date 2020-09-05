import math
import numpy as np
import matplotlib.pyplot as plot


seed=[47,89,299,2003,20000]

#given values for lcg
m=244944
b=0
a_values=[1597,51749]

for i in range(2):
    print("Problem 2. Part",end=" ")
    print(i+1,"\n---->")
    
    # value of a
    a=a_values[i]
    
    for seeds in seed:
        print ("seed:",end=" ")
        print(seeds)
        #now for particular seed we have to count the frequency of the numbers
        # in range like [0.00,0.05], [0.05,0.10] and so on
        x=seeds
        #start u_i from i=0... where u_i=x_i/m
        u=x/m
    
        #iteration upto the period length, because after that the sequence would repeat itself and frequency would go INFINITY in some/all case
        #Therefore it reasonable to calculate frequencies for a period
    
        #we can perform a simple check if a sequence repeat by ?x==seeds and period length cannot be more than 'm'
    
        #there are 20 intervals in total [0.00-0.05],[0.05,0.10]...[0.95,1.00]
    
        frequency=[0]*20
        frequency_data=[]
        #frquency_data is for plotting histogram
        period_length=0
    
        for _ in range(m):
        
            period_length+=1
        
            increment=0.05
        
        
            for segment in range(20):
                l=segment*increment
                r=(segment+1)*increment
                l=float("{:.2f}".format(l))
                r=float("{:.2f}".format(r))
                if(u>=l and u<=r):
                    frequency[segment]+=1
                    frequency_data.append(l)
        
            #terminating the loop by checking repeating sequence
            x=(a*x+b)%m
            u=x/m
            if(x==seeds):
            
                break
    
        for _ in range(20):
            l=_*increment
            r=(_+1)*increment
            l=float("{:.2f}".format(l))
            r=float("{:.2f}".format(r))
            print("[",end=" ")
            print(l, end=",")
            print(r,end=" ")
            print("]",end=" :")
            print(frequency[_])
        plot.hist(frequency_data, bins=20, color='r', ec='b')
       
        plot.xlabel('intervals of size 0.05')
        plot.ylabel('frequency')
        plot.title(("seed", seeds)+(" ::  a", a))
        plot.show()
    
        print("-------------------------")
    
    print("-----------------------------------------x--------------------------------------\n")
    
    
    



