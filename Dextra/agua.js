/*  Dado um vetor de números inteiros não negativos representando tijolos maciços empilhados onde a largura de cada tijolo é 1.
 Escreva um algoritmo que calcule quanto de água ficaria armazenado entre os tijolos após uma chuva intensa.
Assuma que:
O vetor nunca estará vazio
Os valores do vetor sempre serão de 0 até 5, ou seja, 0, 1, 2, 3, 4 ou 5*/
let arr = [2, 1, 0, 3, 1, 2, 2, 3, 2]; //7
let arr2 = [0, 1, 2, 3, 4, 2, 4, 3, 2]; //2
function agua(arr) {
  let t1 = Number;
  let max = Math.max(...arr);
  let flag = 0;
  let flag1 = 0;
  let maxCount = 0;
  arr.forEach(element => {
    if (element === Math.max(...arr)) maxCount++;
  });
  for (let i = 0; i < arr.length; i++) {
    t1 = arr[i]; //
    if (t1 === max) {
      flag1++;
    }
    if (flag1 === maxCount) {
      break;
    }
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < t1) {
        flag += t1 - arr[j];
      }
      if (arr[j] >= t1) {
        i = j - 1;
        break;
      }
    }
  }
  return flag;
}
console.log(agua(arr));
console.log(agua(arr2));
