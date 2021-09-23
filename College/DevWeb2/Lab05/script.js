// Criar um array com 20 elementos inteiros. Imprimir o maior e o menor valor , sem ordenar, o percentual de números pares e a média dos elementos do vetor.
let arr1 = [];
for (let i = 0; i < 20; i++) {
  arr1.push(Math.floor(Math.random() * 20) + 1);
}
//arr1.sort((a,b) => a - b);
let maior = 0;
let flagPar = 0;
for (let el of arr1) {
  if (el % 2 === 0) flagPar++;
  if (el > maior) maior = el;
}
let mediaPar = (flagPar*100)/20;
let menor = maior;
for (let el of arr1) {
  if (el < menor) menor = el;
}
window.alert(`Maior = ${maior},Menor = ${menor}, ${mediaPar}% N Pares.`);
//Escreva um programa que receba do usuário 3 notas para dado aluno, armazenando-as em um array; em seguida, o programa deve imprimir na tela tais notas. 
let arr2 = [];
for(let i = 0; i < 3;i++){
  arr2.push(prompt(`Insira a ${i+1} nota:`));
}
window.alert(`${arr2} são as 3 notas inseridas.`);
// Para um jogo, precisamos saber se um personagem morreu ou não depois de sofrer um ataque. Faça uma função que receba 2 parâmetros, DANO e SAÚDE. A função deve retornar verdadeiro se o dano for matar o personagem (ou seja, deixar sua saúde menor ou igual a zero) e falso caso contrário.
function n3(dano,saude){
  console.log(dano)
  console.log(saude)
  return dano >= saude ? true:false;
}
window.alert(n3(Number(prompt("Dano causado?")),Number(prompt("Saude do personagem:"))))
