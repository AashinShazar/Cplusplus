#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include<iostream>
using namespace std;



class ItemToPurchase
{
   public:
      ItemToPurchase();
      ItemToPurchase(string itemName, int itemPrice, int intQuantity);
      
      bool operator>=(const ItemToPurchase& item);
      int operator+(const ItemToPurchase& item);
      
      void SetName(string itemName);
      string GetName() const;
      
      void SetPrice(int itemPrice);
      int GetPrice() const;
      
      void SetQuantity(int itemQuantity);
      int GetQuantity() const;
      
   private:
      string itemName;
      int itemPrice;
      int itemQuantity;
      
   
      
};


#endif // ITEMTOPURCHASE_H