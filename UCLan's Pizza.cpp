// Name : Aparna Pant
// G-Number : 21197081

#include <iostream>
using namespace std;

//Oliver Kerr (2023) 'Week 4 - More Loops & User Input Validation' CO1409 : Programming. Available at : https://portal.uclan.ac.uk/ultra/courses/_156937_1/outline/file/_6552922_1 
//Return a string to upper case character
string ToUpper(string myString)
{
	string upperString;
	for (auto c : myString) upperString += toupper(c);
	return upperString;
}
//Return string to lowercase characters
string ToLower(string myString)
{
	string lowerString;
	for (auto c : myString) lowerString += tolower(c);
	return lowerString;
}

//Function to add credit to the user's account
double userCredits(double credits)
{
	cout << "Do you wish to add credit to your account? (y/n) ";
	string ynCredit;
	cin >> ynCredit;

	ynCredit = ToLower(ynCredit);
	double creditAmount = 0;

	if (ynCredit == "y")
	{
		cout << "Enter the amount you want to add in your credit " << endl;
		cin >> creditAmount;
		credits = credits + creditAmount;
		return credits;
	}
	else if (ynCredit == "n")
	{
		cout << "We will take you back to the menue " << endl;
		return credits;
	}
	else
	{
		cout << " Enter valid input " << endl;
		return credits;
	}
}

// Function to let the user choose the size of the Pizza
double choosePizzaSize(double& credits)
{
	int orderNo;
	double totalSizePrice = 0.0;
	const int numPizzaSize = 3;
	const double sizePricesList[numPizzaSize] = { 5.0 , 8.50 , 10.25 };
	do {
		string pizzaSizeList[numPizzaSize] = { " Small", "Medium" , "Large" };
		cout << "Please select the size of the Pizza. There are three size of Pizza available " << endl;
		cout << "0. Return to Main Menu" << endl;

		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << pizzaSizeList[i] << " = " << sizePricesList[i] << " $" << endl;
		}

		cout << " " << endl;
		cout << " Please select a number : ";
		cin >> orderNo;

		if (orderNo >= 1 && orderNo <= 3)
		{
			cout << " You have selected " << pizzaSizeList[orderNo - 1] << " which is " << sizePricesList[orderNo - 1] << " $." << endl;
			credits = credits - sizePricesList[orderNo - 1];
			totalSizePrice = totalSizePrice + sizePricesList[orderNo - 1];
		}

		else if (orderNo == 0)
		{
			cout << "We will take you back to the menu." << endl;
			return 0;
		}

		else {
			cout << "Enter valid data. Taking back you to the menu." << endl;
			return 0;
		}
	} while (orderNo == 0);

	return totalSizePrice;
}

//Funtion to let the user choose pizza toppings
double choosePizzaTopping(double& credits)
{
	double totalToppingPrice = 0.0;
	int toppingNo = 0;
	string moreTopping;
	do {
		const int numToppingPrice = 6;
		const double toppingsPriceList[numToppingPrice] = { 0.80,0.50,1.00,0.80,0.40, 1.50 };
		string toppingsList[numToppingPrice] = { " Ham " , " Mushroom", "Pepperoni ", "Peppers", "Onions", "Extra Cheese " };

		cout << " " << endl;
		cout << "\n Now let's choose Toppings.There are multiple toppings option available. Please choose the toppings." << endl;
		cout << "0. Return to Main Menu" << endl;

		for (int i = 0; i < 6; i++) {
			cout << i + 1 << ". " << toppingsList[i] << " = " << toppingsPriceList[i] << " $" << endl;
		}

		cout << " " << endl;
		cout << " Please select a number : ";
		cin >> toppingNo;

		if (toppingNo >= 1 && toppingNo <= 6)
		{
			cout << " You have selected " << toppingsList[toppingNo - 1] << " which is " << toppingsPriceList[toppingNo - 1] << " $." << endl;
			cout << " " << endl;
			credits = credits - toppingsPriceList[toppingNo - 1];
			totalToppingPrice = totalToppingPrice + toppingsPriceList[toppingNo - 1];
		}

		else if (toppingNo == 0)
		{
			cout << "We will take you back to the menu." << endl;
			return 0;
		}
		else {
			cout << "Enter valid data. Taking back you to the menu." << endl;
			return 0;
		}

		cout << "Do you want to add more toppings? (y/n) " << endl;
		cin >> moreTopping;
		cout << " " << endl;
		moreTopping = ToLower(moreTopping);

	} while (moreTopping == "y");

	return totalToppingPrice;
}

//Function to display user's Order Details
void displayUserOrder(double totalPrice, double& credits, int initialCredits)
{
	if (initialCredits > totalPrice)
	{
		cout << "Your total will be " << totalPrice << " $" << endl;
		cout << " Thank you for purchase:) " << endl;
		cout << " Your remaining credits is " << credits << " $" << endl;
		cout << " " << endl;
	}

	else
	{
		cout << "Your total is " << totalPrice << " $" << endl;
		cout << "You have " << initialCredits << " $" << " which is not enough!!" << endl;
		cout << " " << endl;
	}
}

//Function to manage the ordering process of pizza
void pizzaOrder(double credits, int initialCredits)
{
	double totalPrice;
	string ynOrder;

	cout << "Do you wish to order a pizza? (y/n) ";
	cin >> ynOrder;

	ynOrder = ToLower(ynOrder);

	if (ynOrder == "y")
	{
		double sizePrice; double toppingPrice;
		sizePrice = choosePizzaSize(credits); // function call

		toppingPrice = choosePizzaTopping(credits); // function call
		totalPrice = sizePrice + toppingPrice;

		// Calling function to display the order summary of user
		displayUserOrder(totalPrice, credits, initialCredits);
	}
	else {
		cout << "Returning to the menu." << endl;
	}
	cout << " " << endl;
}

int main()
{
	double credits = 0.0, taskNo = 0;
	int initialCredits;
	double totalPrice;

	do {

		cout << "Hello, Welcome to UClan's Pizza paradise.";
		cout << " Kindly select the desired number to begin the task. " << endl;
		cout << "1) Add Credits ( Your Current Credits = " << credits << " $ ) " << endl;
		cout << "2) Place a Pizza Order " << endl;
		cout << "3) Exit " << endl;

		initialCredits = credits;

		cout << " " << endl;
		cout << "Enter number here : ";
		cin >> taskNo;

		//Input validation
		while (cin.fail() || taskNo < 1 || taskNo > 3)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Enter valid input!!" << endl;
			system("pause");
			cout << " " << endl;
			cout << "Enter valid number here : ";
			cin >> taskNo;
		}

		if (taskNo == 1)
		{
			credits = userCredits(credits); //Stores the input of the user credit and displays it

		}
		else if (taskNo == 2)
		{
			pizzaOrder(credits, initialCredits);
		}
	} while (taskNo != 3);
}


