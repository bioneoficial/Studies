import json

# 2) Asks the user for a number and checks if it belongs to the Fibonacci sequence
number = int(input("Enter a number: "))
fibonacci = [0, 1]
while fibonacci[-1] < number:
    fibonacci.append(fibonacci[-1] + fibonacci[-2])
if fibonacci[-1] == number:
    print(f"The number {number} belongs to the Fibonacci sequence")
else:
    print(f"The number {number} does not belong to the Fibonacci sequence")

# 3) Loads the daily sales data from a JSON file and calculates some statistics
with open("sales.json") as f:
    data = json.load(f)
daily_sales = data["daily_sales"]
min_sales = min(daily_sales)
max_sales = max(daily_sales)
avg_sales = sum(daily_sales) / len(daily_sales)
days_above_avg = len([s for s in daily_sales if s > avg_sales])
print(f"Minimum sales value: $ {min_sales:.2f}")
print(f"Maximum sales value: $ {max_sales:.2f}")
print(f"Number of days with sales above average: {days_above_avg}")

# 4) Calculates the percentage of monthly sales for each state
monthly_sales = {
    "SP": 67836.43,
    "RJ": 36678.66,
    "MG": 29229.88,
    "ES": 27165.48,
    "Other": 19849.53
}
total_sales = sum(monthly_sales.values())
for state, sales in monthly_sales.items():
    percentage = sales / total_sales * 100
    print(f"{state}: {percentage:.2f}%")

# 5) Reverses the characters of a string
string = "joao"
reversed_string = ""
for i in range(len(string) - 1, -1, -1):
    reversed_string += string[i]
print(reversed_string)
