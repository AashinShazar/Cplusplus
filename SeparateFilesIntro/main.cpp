#include <iostream>
#include<sstream>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase item1;
ItemToPurchase item2;
string itemName;
int itemPrice;
int itemQuantity;
int totalCost;


std::ostream & operator<<( std::ostream & strm, const ItemToPurchase & item)
{
   return strm << "Name: " << item.GetName() << endl << "Unit price: $" << item.GetPrice() << endl << "Quantity bought: " << item.GetQuantity() << endl;
}

int main()
{
   cout << "Item 1:" << endl;
   cout << "Enter the item name : " << endl;
   getline(cin,itemName);
   cout << "Enter the item price : " << endl;
   cin >> itemPrice;
   cout << "Enter the item quantity : " << endl;
   cin >> itemQuantity;
   
   item1.SetName(itemName);
   item1.SetPrice(itemPrice);
   item1.SetQuantity(itemQuantity);
   
   cout << endl;
   cin.ignore();
   
   cout << "Item 2:" << endl;
   cout << "Enter the item name : " << endl;
   getline(cin,itemName);
   cout << "Enter the item price : " << endl;
   cin >> itemPrice;
   cout << "Enter the item quantity : " << endl;
   cin >> itemQuantity;
   
   item2.SetName(itemName);
   item2.SetPrice(itemPrice);
   item2.SetQuantity(itemQuantity);
   
   cout << endl;
   
   cout << "TOTAL COST" << endl;
   cout<<item1.GetName()<<" "<<item1.GetQuantity()<<" @ $"<<item1.GetPrice()<<" = "<<(item1.GetQuantity()*item1.GetPrice())<<endl;
   cout<<item2.GetName()<<" "<<item2.GetQuantity()<<" @ $"<<item2.GetPrice()<<" = "<<(item2.GetQuantity()*item2.GetPrice())<<endl;
   totalCost = (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice());
   cout << "Total: $" << totalCost<<endl;

  cout << (item1 >= item2) << endl;
  cout << (item1.operator>=(item2)) << endl;
  cout << (item1) << endl;


   
}