f0 = 0 
f1 = 1 
f2 = 0 
n = int(input("insira n: "))
if(n <= 0):
    print("ta troll")
elif(n == 1):
    print(f0)
else:
    print(f0)
    print(f1)
for x in range(n-2):
    f2 = f1 + f0
    f0 = f1
    f1 = f2
    print(f2)


n = int(input("insira n: "))
f = n
for x in range(n-1):
    f *= (x+1)
print(f)


calc = 0 
for x in range(10):
    calc += x
print(calc)


the_list = []
for x in range(20):
    print(x+1)
    the_list.append(x+1)
print(the_list)



nota = int(input("nota de 0 a 10: "))
while(nota < 0 or nota > 10):
   nota = int(input("Invalido. Nota de 0 a 10: "))


for x in range(50):
    if(x % 2 == 1):
        print(x)


n = int(input("Insira N: "))
the_list = []
soma = 0
for x in range(n):
    temp = int(input("Insira um valor numerico: "))
    soma += temp
    the_list.append(temp)
the_list.sort()
for x in the_list:
    if(x == the_list[0]):
        print("menor valor = " + str(x))
    elif(x == the_list[len(the_list) - 1]):
        print("Maior valor = " + str(x))
print("Soma dos valores = " + str(soma))


n = int(input("Insira N entre 0 e 100: "))
while(n < 0 or n > 100):
    n = int(input("Insira N entre 0 e 100: "))
the_list = []
soma = 0
for x in range(n):
    temp = int(input("Insira um valor numerico: "))
    soma += temp
    the_list.append(temp)
the_list.sort()
for x in the_list:
    if(x == the_list[0]):
        print("menor valor = " + str(x))
    elif(x == the_list[len(the_list) - 1]):
        print("Maior valor = " + str(x))
print("Soma dos valores = " + str(soma))



cont = 0 
while (cont == 0):
    cont += 1
    letra_a = 0
    letra_b = 0
    a = int (input ("Insira valor A: "))
    b = int (input ("Insira valor B: ")) 
    letra_c = 0 
    letra_d = 0
    n = input(str("Insira um valor N: "))
    for x in n:
        if(int(x) % 2 != 0):
            letra_d += int(x)
    for y in range(101):
        letra_b += (y * y)
        if (a > b):
            if (y % 2 != 0 and y >= b and y <= a):
                letra_c += y
        else:
            if (y % 2 != 0 and y >= a and y <= b):
                letra_c += y
        if (y % 2 == 0):
            letra_a += y
print ("Soma de todos pares entre e inclusive 2 e 100 = "+str(letra_a))
print ("Soma todos quadrados entre e inclusive 1 e 100 = " + str(letra_b))
print ("Soma dos impares entre e inclusive " + str(a) + " e " + str(b) +" = " + str(letra_c))
print("A soma dos impares do digito N = " + str(letra_d))





