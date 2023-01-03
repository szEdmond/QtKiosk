#pragma once
#include "mycontroller.h"
#include "itemmanager.h"

myController::myController(QObject *parent)
    : QObject{parent}
{

}

QVector<QString> myController::getBurgers(){return ItemManager::GetSingleton()->getBurgerList();}

QVector<QString> myController::getSides(){return ItemManager::GetSingleton()->getSidesList();}

QVector<QString> myController::getDrinks(){return ItemManager::GetSingleton()->getDrinkList();}

QVector<QString> myController::getExtras(){return ItemManager::GetSingleton()->getExtraList();}

void myController::setChosenItem(QString &chosenName, bool isBurger){
    // TODO: Fix Memory leaks
    // FIX: NOT EVERYTHING IS A BURGER
    if(isBurger){
        m_chosenItem = new Burger(ItemManager::GetSingleton()->getBurgerItem(chosenName));
    }
    else{
        m_chosenItem = ItemManager::GetSingleton()->getItem(chosenName);
    }
}

QString myController::getName(){
    if(m_chosenItem){
        QString name = m_chosenItem->GetName();
        return name;
    }
    return "";
}

void myController::addToCart(){ItemManager::GetSingleton()->getCart()->addToCart(m_chosenItem);}

int myController::getCartSize(){return ItemManager::GetSingleton()->getCart()->getSize(); }

QVector<QString> myController::getCartNames(){return ItemManager::GetSingleton()->getCart()->getCartItemNames();}

QVector<double> myController::getCartPrices(){return ItemManager::GetSingleton()->getCart()->getCartItemPrices();}

double myController::getTotal(){return ItemManager::GetSingleton()->getCart()->getTotal();}

void myController::addItem(QString &ingredient){
    dynamic_cast<Burger*>(m_chosenItem)->addItem(ItemManager::GetSingleton()->getExtra(ingredient));
}

bool myController::isItBurger(){
    if(m_chosenItem->isBurger()){
        return true;
    }
    return false;
}

QVector<QString> myController::getFullList(){return ItemManager::GetSingleton()->getCart()->fullList();}

QVector<QString> myController::getFullPriceList(){return ItemManager::GetSingleton()->getCart()->getPrices();}

QVector<QString> myController::burgerImages(){return ItemManager::GetSingleton()->getBImages();}

QVector<QString> myController::sideImages(){return ItemManager::GetSingleton()->getSImages();}

QVector<QString> myController::drinkImages(){return ItemManager::GetSingleton()->getDImages();}

void myController::clearCart(){
    ItemManager::GetSingleton()->getCart()->clear();
}
