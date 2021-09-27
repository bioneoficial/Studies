//Q1 Leia 20 valores reais e calcule seu somatório utilizando a instrução while 
let arrQ1 = [], flagQ1 = 0, arrReduce = (prev,current) =>  prev+current;
while(flagQ1 < 2){
    flagQ1++;
    arrQ1.push(Number(prompt(`Q1)Insira o ${flagQ1} valor numerico real:`)));
    if(flagQ1 === 2)
       arrQ1 = arrQ1.reduce(arrReduce);    
}
document.write(`<p> Q1) a Soma dos elementos resulta em ${arrQ1}</p>`); 
//Q2 Escreva um programa utilizando o comando switch que leia dois valores do usuário e a 
//operação que ele deseja realizar(soma, subtração, divisão ou multiplicação), execute a operação desejada e imprima na tela
let numQ2 = [];
numQ2[0] = Number(prompt("Q2)Insira um valor numerico:"));
numQ2[1] = Number(prompt("Q2)Insira outro valor numerico:"));
let opQ2 =  prompt("Q2)Insira símbolo '+' pra soma, '-' pra subtração, '/' pra divisão, '*' pra multiplicação :");
switch (opQ2) {
    case '+':
        numQ2[3] = numQ2[0] + numQ2[1];
        break;
    case '-':
        numQ2[3] = numQ2[0] - numQ2[1];
        break;
    case '*':
        numQ2[3] = numQ2[0] * numQ2[1];
        break;
    case '/':
        numQ2[3] = numQ2[0] / numQ2[1];
        break;

    default:
        window.alert("Q2)Inseriu valores invalidos para a Q2, tente novamente!");
        break;
}
document.write(`<p> Q2) O resultado da operação é ${numQ2[3]}</p>`); 
//Q3 Criar uma função que junte dois arrays (os valores serão recebidos de forma externa) e retorno o resultado como um novo array.
let arr1Q3 = [], arr2Q3 = [],q3=0;
function q3Function(arr1Q3,arr2Q3){
    let posQ3 = []; // vou criar esse array pra retornar, mas preferia retornar direto.
    posQ3.push(...arr1Q3, ...arr2Q3);
    return  posQ3;
}
while(q3 < 2){
    q3++;
    arr1Q3.push(Number(prompt(`Q3)Insira o ${q3} valor do primeiro array:`)));
    arr2Q3.push(Number(prompt(`Q3)Insira o ${q3} valor do segundo array:`)));

}
document.write(`<p>Q3) O resultado da junção dos arrays ${arr1Q3} e ${arr2Q3} em um novo array é ${q3Function(arr1Q3,arr2Q3)}</p>`);

//Q4 Criar uma função que receba como parâmetro um array de números e retorne um array  contendo somente números positivos.
let arrQ4 = [],q4 = 0; 
function q4Funtion(p1){
    let posQ4 = [];
for(const el of p1){
if (el > 0)
    posQ4.push(el);

}
return posQ4;
}
while(q4<4){
    q4++;
    arrQ4.push(Number(prompt(`Q4)insira o ${q4} valor numero do array:`)));
}
document.write(`<p>Q4) os valores positivos do array ${arrQ4} retornados em um novo array somente com 
 os numeros positivos feito em uma função resultou em ${q4Funtion(arrQ4)}</p>`)
