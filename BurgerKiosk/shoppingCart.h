#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <QDebug>
#include <QObject>
#include "burger.h"
#include "extras.h"
#include "FoodItem.h"

class ShoppingCart{
public:
    ShoppingCart(){}

    void addToCart(FoodItem* item){
        m_cartItems.push_back(item);
    }

    QVector<QString> getCartItemNames(){
        QVector<QString> nameList;
        for(const auto& item : m_cartItems){
            nameList.push_back(item->GetName());
        }
        return nameList;
    }
    QVector<double> getCartItemPrices(){
        QVector<double> priceList;
        for(const auto& item : m_cartItems){
            priceList.push_back(item->GetPrice());
        }
        return priceList;
    }
    double getTotal(){
        double sum = 0.0;
        for(const auto& item : m_cartItems){
            sum += item->GetPrice();
        }
        return sum;
    }
    int getSize(){return m_cartItems.size();}

    // TODO: ADD more formatting
    QVector<QString>fullList(){
        QVector<QString> list;
        for(const auto& item : m_cartItems){
            if(item->isBurger()){
                list.push_back(item->GetName());
                QVector<Extra*> extras = dynamic_cast<Burger*>(item)->getExtras();
                for(const auto& extra : extras){
                    list.push_back("\t+"+extra->GetName());
                }
            }
            else{
               list.push_back(item->GetName());
            }
        }
        return list;
    }

    QVector<QString>getPrices(){
        QVector<QString> prices;
        for(const auto& item: m_cartItems){
            if(item->isBurger()){
                //change this to unit price
                prices.push_back(item->getUnitPrice());
                QVector<Extra*>extras = dynamic_cast<Burger*>(item)->getExtras();
                for(const auto& extra : extras){
                    prices.push_back("+" + extra->getUnitPrice());
                }
            }
            else{
                prices.push_back(item->getUnitPrice());
            }
        }
        return prices;
    }

    void clear(){
        // delete pointers to BurgerCopies
        for(auto& item : m_cartItems){
            if(item->isBurger())
                delete(item);
        }
        m_cartItems.clear();
    }

    ~ShoppingCart(){
        qDeleteAll(m_cartItems.begin(),m_cartItems.end());
    }

private:
    QVector<FoodItem*> m_cartItems;
};

#endif // SHOPPINGCART_H
