cost_price = float(input("Enter the cost price of the product :"))
sell_price = float(input("Enter the sell price of the product :"))
profit = sell_price - cost_price
NewSellingPrice = 1.05 * profit + cost_price
print("The profit from this sell is " ,profit)
print("To increase the profit by 5% the selling price should be ",NewSellingPrice)
