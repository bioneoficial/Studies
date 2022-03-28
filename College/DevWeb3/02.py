# Online Python - IDE, Editor, Compiler, Interpreter

nomeC =input("Insira o nome completo")
print(nomeC.upper())
print(nomeC.lower())
nomeC = nomeC.strip().split()
tamT = 0
tam1 = 0
cont = 0
for el in nomeC:
    if(cont ==0):
        tam1 = len(el)
        cont += 1
    tamT += len(el)
print("Letras totais: " + str(tamT))
print("Letras Prim nome: " + str(tam1))

pTotal = 0
p15 = []
capEl = 50
for i in range(5):
    temp =  int(input("Insira o peso da pessoa " + str(i + 1)))
    pTotal += temp
    p15.append(temp)
print("Liberado pra subir") if capEl >= pTotal else print("Excedeu Carga")

 capEl = int(input("Cap Elevador:"))

meuNome = "Joao Bione"
newName = input("Insira nome comparativo")
print("Nome correto") if meuNome == newName else print("Nome Incorreto")

anoI = int(input("Informe Ano: "))
if(anoI % 400 == 0 or (anoI % 4 == 0 and anoI % 100 != 0)):
    print("Ano Bissexto")
else:
    print("Ano Nao Bissexto")

