#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include "burger.h"
#include "shoppingCart.h"
#include "side.h"
#include "drink.h"
#include "extras.h"
#include <map>
#include <QQmlPropertyMap>
class ItemManager
{
public:
    static ItemManager* GetSingleton();

    void InitBurgers(const QString& path);
    void ListBurgers(){}
    QVector<QString> getBurgerList();

    void InitSides(const QString& path);
    QVector<QString> getSidesList();

    void InitDrinks(const QString& path);
    QVector<QString> getDrinkList();

    void InitExtras(const QString& path);
    QVector<QString> getExtraList();

    QString getBurger(const QString& burgerName){return burgerName;}

    Burger* getBurgerItem(const QString& burgerName){return m_burgerList[burgerName];}
    FoodItem* getItem(const QString& itemName){return m_allItemList[itemName];}
    Extra* getExtra(const QString& extraName){return m_extraList[extraName];}

    ShoppingCart* getCart(){return m_cart;}
    void addToCart(FoodItem* item){m_cart->addToCart(item);}

    QVector<QString> getBImages();
    QVector<QString> getSImages();
    QVector<QString> getDImages();

    ~ItemManager();
private:
    ItemManager(ShoppingCart* cart): m_cart(cart) {}
    static ItemManager* m_itemManager;
    static std::map<QString, Burger*> m_burgerList;
    static std::map<QString, Sides*> m_sidesList;
    static std::map<QString, Drink*> m_drinkList;
    static std::map<QString, Extra*> m_extraList;

    static std::map<QString, FoodItem*> m_allItemList;

    ShoppingCart* m_cart;
};

#endif // ITEMMANAGER_H
