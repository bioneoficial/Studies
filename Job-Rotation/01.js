// 2) Asks the user for a number and checks if it belongs to the Fibonacci sequence
const number = parseInt(prompt("Enter a number: "));
let fibonacci = [0, 1];
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
    const dailySales = data.daily_sales;
    const minSales = Math.min(...dailySales);
    const maxSales = Math.max(...dailySales);
    const avgSales =
      dailySales.reduce((total, value) => total + value, 0) / dailySales.length;
    const daysAboveAvg = dailySales.filter((sale) => sale > avgSales).length;
    console.log(`Minimum sales value: $ ${minSales.toFixed(2)}`);
    console.log(`Maximum sales value: $ ${maxSales.toFixed(2)}`);
    console.log(`Number of days with sales above average: ${daysAboveAvg}`);
  });

// 4) Calculates the percentage of monthly sales for each state
const monthlySales = {
  SP: 67836.43,
  RJ: 36678.66,
  MG: 29229.88,
  ES: 27165.48,
  Other: 19849.53,
};
const totalSales = Object.values(monthlySales).reduce(
  (total, value) => total + value,
  0
);
for (const state in monthlySales) {
  const sales = monthlySales[state];
  const percentage = (sales / totalSales) * 100;
  console.log(`${state}: ${percentage.toFixed(2)}%`);
}

// 5) Reverses the characters of a string
const string = "joao";
let reversedString = "";
for (let i = string.length - 1; i >= 0; i--) {
  reversedString += string[i];
}
console.log(reversedString);
