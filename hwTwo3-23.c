// Chapter 3 - #23 Stock Trading Program Bill
/* Last month Joe purchased some stock in Acme Software, Inc. Here are the details of
the purchase:
• The number of shares that Joe purchased was 1,000.
• When Joe purchased the stock, he paid $45.50 per share.
• Joe paid his stockbroker a commission that amounted to 2% of the amount he paid
for the stock.
Two weeks later Joe sold the stock. Here are the details of the sale:
• The number of shares that Joe sold was 1,000.
• He sold the stock for $56.90 per share.
• He paid his stockbroker another commission that amounted to 2% of the amount
he received for the stock.
Write a program that displays the following information:
• The amount of money Joe paid for the stock.
• The amount of commission Joe paid his broker when he bought the stock.
• The amount that Joe sold the stock for.
• The amount of commission Joe paid his broker when he sold the stock.
• Display the amount of profit that Joe made after selling his stock and paying the two
commissions to his broker. (If the amount of profit that your program displays is a
negative number, then Joe lost money on the transaction.) */

#include <stdio.h>

int main()
{
	const double COMMISSION = 0.02;
	const int STOCKS = 1000;

	double purchase = STOCKS * 45.50;
	double sale = STOCKS * 56.90;
	double pCommission = purchase * COMMISSION;
	double sCommission = sale * COMMISSION;
	double profit = sale - purchase - (pCommission + sCommission);

	printf("Amount paid for stocks: $%.2f\n", purchase);
	printf("Amount of commission paid to broker for purchase: $%.2f\n", pCommission);
	printf("Amount received for stocks: $%.2f\n", sale);
	printf("Amount of commission paid to broker for sale: $%.2f\n", sCommission);
	printf("Joe's profit: $%.2f\n", profit);

	return 0;
}
