const readline = require('readline');

class Funcionarios {
    constructor(nome, salBruto, inss, irrf, salLiq) {
        this.nome = nome;
        this.salBruto = salBruto;
        this.inss = inss;
        this.irrf = irrf;
        this.salLiq = salLiq;
    }

    calcSal(salBruto) {
        let desInss = Number, actualSalLiq = Number;
        this.inss = desInss;
        this.salLiq = actualSalLiq;
        return true;
    }
}

let listaFunc = [];
const scan = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

scan.question("testando", answer =>   {
    console.log(answer);
}
//scan.close();