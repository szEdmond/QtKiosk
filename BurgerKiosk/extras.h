#ifndef EXTRAS_H
#define EXTRAS_H

#include "FoodItem.h"

class Extra : public FoodItem{
public:
    Extra(const QString& aName, double aPrice,const QString& aImgLink = "")
        : FoodItem(aName, aPrice, aImgLink){}
    ~Extra(){}

    double GetPrice() const override{
        return m_price;
    }
};

#endif // EXTRAS_H
