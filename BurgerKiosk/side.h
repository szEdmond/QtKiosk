#ifndef SIDE_H
#define SIDE_H
#include "FoodItem.h"

class Sides :public FoodItem{
public:
    Sides(const QString& aName, double aPrice, const QString& aImgLink)
        :FoodItem(aName,aPrice, aImgLink){}
    double GetPrice() const override{
        return m_price;
    }
    ~Sides(){}
};


#endif // SIDE_H
