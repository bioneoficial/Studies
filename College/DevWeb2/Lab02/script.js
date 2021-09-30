var num1 = Number(prompt('digite 1 numero'));
var num2 = Number(prompt('digite 1 numero'));
window.alert('Operações  imprimidos no console');
console.log(`${num1} + ${num2} = ${num1 + num2}`);
console.log(`${num1} - ${num2} = ${num1 - num2}`);
console.log(`${num1} * ${num2} = ${num1 * num2}`);
console.log(`${num1} / ${num2} = ${num1 / num2}`);
console.log(`${num1} % ${num2} = ${num1 % num2}`);
//Q1 /\
var notas = [];
var pesos = [];
for (let i = 0; i < 7; i++) {
  notas.push(Number(prompt('Digite a nota ' + (i + 1))));
  pesos.push(Number(prompt('Digite peso da nota ' + (i + 1))));
  notas[i] *= pesos[i];
}
var notaTotal = 0;
var pesoTotal = 0;
for (nota of notas) {
  notaTotal += nota;
}
for (peso of pesos) {
  pesoTotal += peso;
}
document.write(`A média ponderada é ${notaTotal / pesoTotal}`);
// q2 /\

var num0 = Number(prompt('digite 1 numero'));
window.alert(num0 * 2);
// Q3 /\
var jantar = Number(prompt('digite o valor do jantar'));
var taxa = jantar * 0.1;
window.alert(
  `${taxa} é os 10% do garçom e o total a pagar vai é ${jantar + taxa} reais`
);
// Q4 /\
