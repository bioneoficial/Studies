//Questao 1
let sorteio = [Math.floor(Math.random() * 9999) + 1];
let milhar, dezena, centena, unidade;
sorteio[0] = sorteio[0].toString();
let teste = 0;
for (let i = 0; i < sorteio[0].length; i++) {
  if (sorteio[0].length === 4) {
    milhar = sorteio[0][0];
    centena = sorteio[0][1];
    dezena = sorteio[0][2];
    unidade = sorteio[0][3];
  } else if (sorteio[0].length === 3) {
    centena = sorteio[0][0];
    dezena = sorteio[0][1];
    unidade = sorteio[0][2];
  } else if (sorteio[0].length === 2) {
    dezena = sorteio[0][0];
    unidade = sorteio[0][1];
  } else {
    unidade = sorteio[0][0];
  }
}

sorteio >= 1000
  ? window.alert(
      `A unidade de Milhar é ${milhar}, a centena é ${centena}, a dezena é ${dezena}, a unidade é ${unidade}`
    )
  : sorteio >= 100
  ? window.alert(
      `A centena é ${centena}, a dezena é ${dezena}, a unidade é ${unidade}`
    )
  : sorteio >= 10
  ? window.alert(`A dezena é ${dezena}, a unidade é ${unidade}`)
  : window.alert(`Unidade é ${unidade}`);
// Questao 2
let numRandom = Math.round(Math.random() * 5);
console.log(numRandom);
window.alert('Adivinhe o numero entre 0 e 5');
let guess = Number(prompt('Qual seu chute, ma friend?'));
if (guess === numRandom) {
  window.alert('You win');
} else {
  window.alert('You Lose');
}
//Questao 3
let vel = Number(prompt('Escreva a velocidade do carro:'));
if (80 < vel) {
  let multa = 0;
  for (let i = vel; i > 80; i--) {
    multa += 7;
  }
  window.alert(
    'Prefeitura de Nit informa: TOMALHE MULTA no valor de ' + multa + ' $'
  );
}

//Questao 4
let distancia = Number(prompt('Qual a distancia em KM da viagem?'));
let passagem = Number;

if (distancia <= 200) {
  passagem = distancia * 0.5;
} else {
  passagem = distancia * 0.45;
}
window.alert(passagem + ' é o preço da passagem');
//Questao 5
let inputYear = Number(prompt('Insira um ano:'));
if ((inputYear % 4 === 0 && inputYear % 100 !== 0) || inputYear % 400 === 0) {
  window.alert(`O ano ${inputYear} é bissexto`);
} else {
  window.alert(`O ano ${inputYear} Ñ é bissexto`);
}
//questao 6 Faça um programa que leia 3 números e mostre qual é o maior e qual é o menor.
let num0 = Number(prompt('Insira um número:'));
let num1 = Number(prompt('Insira um segundo número:'));
let num2 = Number(prompt('Insira o último número:'));
num0 > num1 && num0 > num2
  ? num1 > num2
    ? window.alert(`${num0} > ${num1} > ${num2}`)
    : window.alert(`${num0} > ${num2} > ${num1}`)
  : num1 > num2 && num1 > num0
  ? num2 > num0
    ? window.alert(`${num1} > ${num2} > ${num0}`)
    : window.alert(`${num1} > ${num0} > ${num2}`)
  : num0 > num1
  ? window.alert(`${num2} > ${num0} > ${num1}`)
  : window.alert(`${num2} > ${num1} > ${num0}`);
//Q7
let salary = Number(prompt('Insira o salario:'));
if (salary > 1250) {
  window.alert(
    `O salario $${salary} recebeu um aumento de $${
      salary * 0.1
    }, totalizando $${salary * 1.1}`
  );
} else {
  window.alert(
    `O salario $${salary} recebeu um aumento de $${
      salary * 0.15
    }, totalizando $${salary * 1.15}`
  );
}
