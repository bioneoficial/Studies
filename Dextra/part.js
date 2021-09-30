// javascript
let arr0 = [22, 5, 18, 7, 1, 10, 2, 7, 3, 6, 4, 20];
let arr1 = [15, 5, 7, 8, 10, 2, 9, 1, 4, 4, 2, 7, 13, 2, 3];
let msg = 'Achou n mano';
function particao(arr) {
  for (let i = 0; i < arr.length; i++) {
    let sum0 = 0,
      sum1 = 0;
    for (let j = 0; j < i; j++) {
      sum0 += arr[j];
    }
    for (let k = arr.length - 1; k > i; k--) {
      sum1 += arr[k];
    }
    if (sum0 === sum1) {
      return i; // retorna o indice desejado
    }
  }
  return msg;
}
console.log(particao(arr0));
console.log(particao(arr1));

/* Dado um vetor de inteiros, faça um algorítmo que retorne a primeira posição do 
vetor na qual a soma de todos os elementos a sua esquerda seja igual a soma de todos os elementos a sua direita. */
