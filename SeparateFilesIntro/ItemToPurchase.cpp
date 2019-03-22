#include "ItemToPurchase.h"



   bool ItemToPurchase::operator>=(const ItemToPurchase& item){
      return item.GetPrice() >=  GetPrice();
   }
   
   int ItemToPurchase::operator+(const ItemToPurchase& item){
      return (item.GetPrice()*item.GetQuantity()) + (GetPrice()*GetQuantity());
   }

   ItemToPurchase::ItemToPurchase(){
      this->itemName = "none";
      this->itemPrice = 0;
      this->itemQuantity = 0;
   }
   
   ItemToPurchase::ItemToPurchase(string itemName, int itemPrice, int itemQuantity) : itemName(itemName), itemPrice(itemPrice), itemQuantity(itemQuantity) {
   }

   void ItemToPurchase::SetName(string itemName){
      this->itemName=itemName;
   }
   
   string ItemToPurchase::GetName() const{
      return itemName;
   }
   
   void ItemToPurchase::SetPrice(int itemPrice){
      this->itemPrice=itemPrice;
   }
   
   int ItemToPurchase::GetPrice() const{
      return itemPrice;
   }
   
   void ItemToPurchase::SetQuantity(int itemQuantity){
      this->itemQuantity=itemQuantity;
   }
   

   int ItemToPurchase::GetQuantity() const{
      return itemQuantity;
   }
   
   