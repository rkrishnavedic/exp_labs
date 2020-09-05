print("Problem 1. Part 1.");
print("a=6 , b=0, m=11 ");
print ("---------------");

for seed in range(11): #range(11) means 0<=seed and seed<11
    print("Seed value:", end=" ");
    print (seed);
    print ("Sequence :", end=" ");
    a=6; b=0; m=11;
    x=seed;
    trace_sequence=[-1]*13;
    
    period_length=0;
    for _ in range(13):
        if trace_sequence[x]!=-1:
            break;
        else:
            trace_sequence[x]=_;
            period_length+=1;
            x=(a*x+b)%m;
            print(x, end=" ");
            
    print("\nPeriod-Length :",end=" ");
    print(period_length);
    print("--------------------")
    
print("-----------------------------x------------------------------------------");
    
print("Problem 1. Part 2." );
print("a=3 , b=0, m=11 ");
print ("---------------");

for seed in range(11): #range(11) means 0<=seed and seed<11
    print("Seed value:", end=" ");
    print (seed);
    print ("Sequence :", end=" ");
    a=3; b=0; m=11;
    x=seed;
    trace_sequence=[-1]*13;
    
    period_length=0;
    for _ in range(13):
        if trace_sequence[x]!=-1:
            break;
        else:
            trace_sequence[x]=_;
            period_length+=1;
            x=(a*x+b)%m;
            print(x, end=" ");
            
    print("\nPeriod-Length :",end=" ");
    print(period_length);
    print("-----------------");
    
print("-----------------------------x------------------------------------------");
    
