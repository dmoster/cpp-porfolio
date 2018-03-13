#include <iostream>
#include <string>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0.0;
   itemQuantity = 0;

   return;
}


void ItemToPurchase::SetName(string name) {
   itemName = name;

   return;
}


string ItemToPurchase::GetName() {
   return itemName;
}


void ItemToPurchase::SetPrice(double price) {
   itemPrice = price;

   return;
}


double ItemToPurchase::GetPrice() {
   return itemPrice;
}


void ItemToPurchase::SetQuantity(int quantity) {
   itemQuantity = quantity;

   return;
}


int ItemToPurchase::GetQuantity() {
   return itemQuantity;
}