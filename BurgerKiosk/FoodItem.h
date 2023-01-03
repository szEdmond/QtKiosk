#ifndef FOODITEM_H
#define FOODITEM_H

#include <QString>


class FoodItem{
public:
    FoodItem() : m_price(0.0) {}
    FoodItem( const QString& aName, double aPrice, const QString& aImgLink );

    FoodItem& operator=( const FoodItem& other );

    virtual ~FoodItem(){}

    QString GetName() { return m_name; }
    virtual double GetPrice() const = 0;
    virtual bool isBurger() {return false;}
    QString getUnitPrice();
    QString getLink(){return m_imglink;}
protected:
    QString m_name;
    double m_price;
    QString m_imglink;

};

#endif // FOODITEM_H
