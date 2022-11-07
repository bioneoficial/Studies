import random
Lista1 = []
Lista2= []
count = 0
while count<1000:
  temp = random.randint(1,10)
  if temp > 5:
    Lista1.append(temp)
  else:
    Lista2.append(temp)
    count = count + 1
print(Lista1)
print(Lista2)