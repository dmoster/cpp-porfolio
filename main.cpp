/*
Daniel Moster, Section 5, d.moster@me.com
Description: 


Test Cases

Case 1
Input: 
Expected Output: 
Result: 

Case 2
Input: 
Expected Output: 
Result: 

Case 3
Input: 
Expected Output: 
Result: 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"

using namespace std;


int main() {
   const int PRECISION_MONEY = 2;
   string name = "";
   double price = 0.0;
   int quantity = 0;
   double costAtQty = 0.0;
   double totalCost = 0.0;
   ItemToPurchase item1;
   ItemToPurchase item2;
   

   cout << "Item 1" << endl;
   cout << "Enter the item name: ";
   getline(cin, name);
   item1.SetName(name);
   cout << endl;
   cout << "Enter the item price: ";
   cin >> price;
   item1.SetPrice(price);
   cout << endl;
   cout << "Enter the item quantity: ";
   cin >> quantity;
   item1.SetQuantity(quantity);
   cout << endl << endl;
   cin.ignore();

   cout << "Item 2" << endl;
   cout << "Enter the item name: ";
   getline(cin, name);
   item2.SetName(name);
   cout << endl;
   cout << "Enter the item price: ";
   cin >> price;
   item2.SetPrice(price);
   cout << endl;
   cout << "Enter the item quantity: ";
   cin >> quantity;
   item2.SetQuantity(quantity);
   cout << endl << endl;


   cout << "TOTAL COST" << endl;
   costAtQty = item1.GetQuantity() * item1.GetPrice();
   cout << item1.GetName() << " " << item1.GetQuantity() << " @ " << fixed << setprecision(PRECISION_MONEY) << "$" <<
      item1.GetPrice() << " = $" << costAtQty << endl;
   totalCost = costAtQty;
   costAtQty = item2.GetQuantity() * item2.GetPrice();
   cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << costAtQty << endl 
      << endl;
   totalCost += costAtQty;
   cout << "Total: $" << totalCost;


//   system("pause");
   return 0;
}