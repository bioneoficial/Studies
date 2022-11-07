let min, max, guess, tries = 0;
while(isNaN(min) || isNaN(max)){
    min = Number(prompt("Insira o intervalo minimo de N"));
    max = Number(prompt("Insira o intervalo maximo de N"));
}
const numRandom = min > max ?  ~~((Math.random() * min) + max) : ~~((Math.random() * max) + min);
console.log(numRandom);
while(guess !== numRandom){
    guess = Number(prompt("Chute o N gerado:"));
    if(guess === numRandom){
        break;
    }
    tries++;
    guess > numRandom ? console.log("chutou alto") : console.log("Chutou baixo")
}
console.log(`parabains!!, acertou o ${numRandom} em ${tries} tentativa(s)`);