let arr = [];
const randomInt = max => ~~((Math.random() * max) + 1);
const max = 60;
for(let i = 0; i < 6; i++) arr.push(~~(Math.random() * 60) + 1);
for(let i = 0; i < 6; i++) arr.push(randomInt(60) + 1);
for(let i = 0; i < 6; i++) arr.push(randomInt(max) + 1);
console.log(arr);
const p4 = (param) => {
    const nota5 = 5, nota20 = 20,nota50 = 50;
    let cont5 = cont20 = cont50 = 0, resp = param;
while(resp !== 0){
    if(resp - nota50 >= 0){
        resp -= nota50;
        cont50++;
    }else if(resp - nota20 >= 0){
        resp -= nota20;
        cont20++;
    }else if(resp - nota5 >= 0){
        resp -= nota5;
        cont5++;
    }else{
        return 'Tratar erro';
    }
}
let msg =`Para um saque de R$${param}, teremos um total de`;
// monto msg nos ternarios, primeiro qtd de notas, segundo notas de 50, terceiro de 20, ultimo de 5.
msg = (cont5+cont20+cont50 > 1) ? msg.concat(' ', `${cont5+cont20+cont50} notas,`) : msg.concat(' ',`${cont5+cont20+cont50} nota,`);
msg = cont50 > 1 ? msg.concat(' ',`${cont50} notas de ${nota50}`) : cont50 === 1 ? msg.concat(' ',`${cont50} nota de ${nota50}`) : msg;
msg = cont20 > 1 ? msg.concat(' ',`${cont20} notas de ${nota20}`) : cont20 === 1 ? msg.concat(' ',`${cont20} nota de ${nota20}`) : msg;
msg = cont5 > 1 ? msg.concat(' ',`${cont5} notas de ${nota5}`) : cont5 === 1 ? msg.concat(' ',`${cont5} nota de ${nota5}`) : msg;
    return msg;
}
console.log(p4(25));
console.log(p4(175));
console.log(p4(5));
console.log(p4(50));
console.log(p4(20));