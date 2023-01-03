#ifndef DRINK_H
#define DRINK_H
#include "FoodItem.h"

class Drink :public FoodItem{
public:
    Drink(const QString& aName, double aPrice, const QString& aImgLink)
        :FoodItem(aName,aPrice, aImgLink){}
    double GetPrice() const override{
        return m_price;
    }
    ~Drink(){}
};

#endif // DRINK_H
