// 2) Asks the user for a number and checks if it belongs to the Fibonacci sequence
const number: number = parseInt(prompt("Enter a number: ") || "0");
let fibonacci: number[] = [0, 1];
while (fibonacci[fibonacci.length - 1] < number) {
fibonacci.push(
fibonacci[fibonacci.length - 1] + fibonacci[fibonacci.length - 2]
);
}
if (fibonacci[fibonacci.length - 1] === number) {
console.log(`The number ${number} belongs to the Fibonacci sequence`);
} else {
console.log(`The number ${number} does not belong to the Fibonacci sequence`);
}

// 3) Loads the daily sales data from a JSON file and calculates some statistics
fetch("sales.json")
.then((response) => response.json())
.then((data) => {
const dailySales: number[] = data.daily_sales;
const minSales: number = Math.min(...dailySales);
const maxSales: number = Math.max(...dailySales);
const avgSales: number =
dailySales.reduce((total, value) => total + value, 0) / dailySales.length;
const daysAboveAvg: number = dailySales.filter((sale) => sale > avgSales).length;
console.log(`Minimum sales value: $ ${minSales.toFixed(2)}`);
console.log(`Maximum sales value: $ ${maxSales.toFixed(2)}`);
console.log(`Number of days with sales above average: ${daysAboveAvg}`);
});

// 4) Calculates the percentage of monthly sales for each state
const monthlySales: Record<string, number> = {
SP: 67836.43,
RJ: 36678.66,
MG: 29229.88,
ES: 27165.48,
Other: 19849.53,
};
const totalSales: number = Object.values(monthlySales).reduce(
(total: number, value: number) => total + value,
0
);
for (const state in monthlySales) {
const sales: number = monthlySales[state];
const percentage: number = (sales / totalSales) * 100;
console.log(`${state}: ${percentage.toFixed(2)}%`);
}

// 5) Reverses the characters of a string
const string: string = "example";
let reversedString: string = "";
for (let i: number = string.length - 1; i >= 0; i--) {
reversedString += string[i];
}
console.log(reversedString);

// to run this on your HTML file, you need to add the following script tag:
// tsc 01.ts
// this will generate a 001.js file from this ts file
// remove the actual script tag from your HTML file and add the following:
// <script src="001.js"></script>
