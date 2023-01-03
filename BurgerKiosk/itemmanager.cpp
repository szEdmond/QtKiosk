#pragma once
#include "itemmanager.h"
#include <fstream>
#include <QDebug>
#include <QVariant>
ItemManager* ItemManager::m_itemManager = nullptr;
std::map<QString, Burger*> ItemManager::m_burgerList;
std::map<QString, Sides*> ItemManager::m_sidesList;
std::map<QString, Drink*> ItemManager::m_drinkList;
std::map<QString, Extra*> ItemManager::m_extraList;

std::map<QString, FoodItem*> ItemManager::m_allItemList;

ItemManager* ItemManager::GetSingleton(){
    if(m_itemManager == nullptr){
        m_itemManager = new ItemManager(new ShoppingCart);
    }
    return m_itemManager;
}

void ItemManager::InitBurgers(const QString& path){

    std::ifstream f(path.toStdString());
    std::string name, list, price, link;

    while(!f.eof()){
        f >> name >> list >> price >> link;

        m_burgerList[name.c_str()] =
                new Burger(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                );
        m_allItemList[name.c_str()] =
                new Burger(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                );
    }
    f.close();
}

QVector<QString> ItemManager::getBurgerList()
{
    QVector<QString> burgers;
    for(const auto& burger : m_burgerList){
        burgers.push_back(burger.first);
    }
    return burgers;
}

void ItemManager::InitSides(const QString &path)
{
    std::ifstream f(path.toStdString());
    std::string name, price, link;
    while(!f.eof()){
        f >> name >> price >> link;
        m_sidesList[name.c_str()] =
                new Sides(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                    );
        m_allItemList[name.c_str()] =
                new Sides(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                    );
    }
    f.close();
}

QVector<QString> ItemManager::getSidesList()
{
    QVector<QString> sides;
    for(const auto& side : m_sidesList)
        sides.push_back(side.first);
    return sides;

}

void ItemManager::InitDrinks(const QString &path)
{
    std::ifstream f(path.toStdString());
    std::string name, price, link;
    while(!f.eof()){
        f >> name >> price >> link;
        m_drinkList[name.c_str()] =
                new Drink(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                    );
        m_allItemList[name.c_str()] =
                new Drink(
                    name.c_str(),
                    stod(price),
                    link.c_str()
                    );
    }
    f.close();
}

QVector<QString> ItemManager::getDrinkList()
{
    QVector<QString> drinks;
    for(const auto& drink : m_drinkList)
        drinks.push_back(drink.first);
    return drinks;
}

void ItemManager::InitExtras(const QString &path)
{
    std::ifstream f(path.toStdString());
    std::string name, price;
    while(!f.eof()){
        f >> name >> price;
        m_extraList[name.c_str()] =
                new Extra(
                    name.c_str(),
                    stod(price),""
                    );
    }
    f.close();
}

QVector<QString> ItemManager::getExtraList()
{
    QVector<QString> extras;
    for(const auto& item : m_extraList)
        extras.push_back(item.first);
    return extras;
}

QVector<QString> ItemManager::getBImages(){
    QVector<QString> imgs;
    for(const auto& item : m_burgerList)
        imgs.push_back(item.second->getLink());
    return imgs;
}

QVector<QString> ItemManager::getSImages(){
    QVector<QString> imgs;
    for(const auto& item : m_sidesList)
        imgs.push_back(item.second->getLink());
    return imgs;
}

QVector<QString> ItemManager::getDImages(){
    QVector<QString> imgs;
    for(const auto& item : m_drinkList)
        imgs.push_back(item.second->getLink());
    return imgs;
}

ItemManager::~ItemManager(){
    for(auto& item : m_burgerList)
        delete(item.second);
    for(auto& item: m_sidesList)
        delete(item.second);
    for(auto& item: m_drinkList)
        delete(item.second);
    for(auto& item: m_extraList)
        delete(item.second);
    for(auto& item : m_allItemList)
        delete(item.second);
}
