// Generated by dia2code
#ifndef STATE__SHOP__H
#define STATE__SHOP__H

#include <string>
#include <map>

namespace state {
  class Inventory;
  class StaticElements;
}

#include "Inventory.h"
#include "StaticElements.h"

namespace state {

  /// class Shop - 
  class Shop : public state::StaticElements {
    // Associations
    // Attributes
  public:
    std::map<std::string,int> ShopItems;
    Inventory*  inventory;
    int money;
    // Operations
  public:
    void AddtoInventory (std::string item, Inventory* inventory);
    void RemovefromInventary (std::string item, Inventory* inventory);
    void MaxItemMoney (int money, std::string item);
    void IteminInventary (std::string item, Inventory inventory);
    void SelltoShop (std::string item, Inventory* inventory);
    Shop (Inventory* inventory, std::map<std::string,int> listItems, int money);
    ~Shop ();
    // Setters and Getters
  };

};

#endif
