#ifndef BURGER_H
#define BURGER_H

#include <QObject>
#include "FoodItem.h"
#include "extras.h"
#include <string>

class Burger : public FoodItem{
public:
    Burger(){}
    Burger(const QString& aName, double aPrice, const QString& aImgLink)
        :FoodItem(aName, aPrice, aImgLink)
    {}
    Burger(Burger* item){
        m_name = item->GetName();
        m_price = item->GetPrice();
        m_imglink = item->m_imglink;
        m_extra = item->m_extra;
    }
    ~Burger(){
        m_extra.clear();
    }

    double GetPrice() const override{
        double sum = m_price;
        for(const auto& x : m_extra){
            sum+=x->GetPrice();
        }
        return sum;
    }
    void addItem(Extra* extra){
        m_extra.push_back(extra);
    }
    bool isBurger() override {return true;}
    QVector<Extra*>& getExtras() {return m_extra;}
private:
    QVector<QString> m_extras;
    QVector<Extra*> m_extra;
};

#endif // BURGER_H
