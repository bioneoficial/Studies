/* Desenvolver um programa para calcular a conta de água. O custo da água varia dependendo se o consumidor é residencial,
 comercial ou industrial. A regra para calcular a conta é:

– Residencial: R$5,00 de taxa mais R$0,05 por m³ gastos;
– Comercial: R$500,00 para os primeiros 80 m³ gastos mais R$0,25 por m³ gastos;
– Industrial: R$800,00 para os primeiros 100 m³ gastos mais R$0,04 por m³ gastos;

O programa deverá ler a conta do cliente, consumo de água por metros cúbicos e o tipo de consumidor 
( residencial, comercial e industrial ). Como resultado, imprima a conta do cliente e o valor real a 
ser pago pelo mesmo e guarde em uma lista.
*/

let clienteM = Number(prompt('insira quantos metros foram gastos:'));
//let clienteM = 10;
//let clienteType = '3';
let clienteType = prompt("insira Número '1' para cliente residencial, '2' para comercial, '3' para industrial:");
let taxa = {
  Residencial: 5 + clienteM * 0.05,
  Comercial: 500 + clienteM * 0.25,
  Industrial: 800 + clienteM * 0.04,
};
let lista = [];
if( clienteType === '1'){
  lista.push(`Cliente Residencial conta $${taxa.Residencial}`);
  console.log(lista[0])
}else if(clienteType === '2'){
  lista.push(`Cliente comercial conta $${taxa.Comercial}`);
  console.log(lista[0])
}else if(clienteType === '3'){
  lista.push(`Cliente industrial conta $${taxa.Industrial}`);
  console.log(lista[0])
}else{
  console.log('Tipo Invalido');
}

//Fazer um programa que dado um número, calcular e escrever se este é positivo ou negativo, e múltiplo ou não de 3, ao mesmo tempo.
/*
let num = Number(prompt('insira um valo numerico:'));

if (num >= 0) {
  num % 3 === 0
    ? console.log('positivo e  multiplo de 3')
    : console.log('positivo e não multiplo de 3');
} else {
  num % 3 !== 0
    ? console.log('negativo e  nao multiplo de 3')
    : console.log('negativo e  multiplo de 3');
}
*/
