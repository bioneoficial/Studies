//Q1
let yearSmoke = Number(prompt("Q1-Quantos anos fuma?"));
yearSmoke *= 365;
let cigarN = Number(prompt("Q1-Qnts cigars per day?"));
let cigarPrice = Number(prompt("Q1- Qual é o preço de uma carteira de cigarretes ?"));
let resCigar = document.write("R$ " + yearSmoke * ( cigarN * (cigarPrice
  / 20)) + ' É o valor gasto por ano. <br>');

  //Q2

  let sides = prompt("Q2-Insira os 3 lados em valor numérico separados por espaço").split(" ");
  let sidesValue =  sides.map((el) => Number(el));
  if(sides.length === 3){
  let cont = 0;
  for(let i =1; i<3;i++){
    if(sidesValue[0] === sidesValue[i]|| sidesValue[i] === sidesValue[i+1]){
      cont++;
    };
  };
if(cont === 0){
  document.write("Triangulo escaleno<br>");
}else{
  cont === 1 ? document.write("Triangulo isosceles<br>"):document.write("Triangulo Equilatero<br>");
}
}else{
  window.alert("ATENÇÃO NAS INSTRUÇÕES DOS LADOS DO TRIANGUILO, SOLDADO!");
}

//Q3

let q3 = prompt("Q3-Digite 4 valores números separados por espaço:").split(" ");

if(q3.length === 4){
  
  sumq3 = +q3[0] + +q3[1];
  mulq3 = +q3[2] * +q3[3];
  if(sumq3 > mulq3){
    document.write("Soma maior que multiplicação <br>");
  }else{
    sumq3 === mulq3 ? document.write("Multiplicação igual soma"): document.write("Multiplicação maior que soma");
    
  }
}else{
  window.alert("ATENÇÃO NAS INSTRUÇÕES DO ENUNCIADO Q3, SOLDADO!");
}

//Q4
let gasosa = parseFloat(prompt("Qual preço da gasosa my friend? Ex: 5.00, 5.21, 5.10! :"));
let alcohol = parseFloat(prompt("Qual preço do alcool my friend? Ex: 5.00, 5.21, 5.10! :"));
alcohol <= (gasosa * 0.70) ?  document.write("Vantagem no alcohol"):document.write("Vantagem na gasosa");
