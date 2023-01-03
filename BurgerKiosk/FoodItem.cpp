#pragma once
#include "FoodItem.h"

FoodItem::FoodItem(const QString& aName, double aPrice, const QString& aImgLink)
    : m_name(aName)
    , m_price(aPrice)
    , m_imglink(aImgLink)
{}

FoodItem& FoodItem::operator=(const FoodItem& other){
    if(this != &other){
        m_name = other.m_name;
        m_price = other.m_price;
        m_imglink = other.m_imglink;
    }
    return *this;
}

QString FoodItem::getUnitPrice(){
    //return QString::fromStdString(std::to_string(std::trunc(m_price*100)/100));
    std::string num_text = std::to_string(m_price);
    std::string rounded = num_text.substr(0, num_text.find(".")+3);
    return QString::fromStdString(rounded);
}
