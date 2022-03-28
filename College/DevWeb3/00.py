01.py
from random import random, randrange

ex01 = randrange(0,9999)
if(ex01 > 0):
    itera = ex01
    cont01 = 0
    string01 = ["Unidade ","Dezena ","Centena ", "Milhar "]
    while itera > 0:
        itera = itera % 10;
        print(string01[cont01] + str(itera))
        ex01 = int(ex01 / 10)
        cont01 += 1
        itera = ex01
else:
    print("Unidade " + str(ex01))

ex02 = int(input("Insira 1 numero Inteiro: "))
ex02_1 = int(input("Insira outro numero Inteiro: "))
ex02_3 = float(input("Insira 1 numero real: "))
print("Calculo 1 " + str((ex02 * 2) * (ex02_1 / 2)) + "\t Calculo 2 " +str(ex02 * 3 + ex02_3) + "\n Calculo 3 "+ str(ex02_3 ** 3))

ex03 = input("Insira um numero: ")
print("O numero digitado foi "+ str(ex03))

ex04 = int(input('Insira qtd metros: '))
print("Centimetros: " + str(ex04 * 100))

ex05 = int(input("Insira Temp em Fahrenheit "))
C = 5 * ((ex05-32) / 9)
print("Temos em Graus Celsius a temperatura de " + str(C))