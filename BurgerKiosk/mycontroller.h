#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "FoodItem.h"
#include <QObject>

class myController : public QObject
{
    Q_OBJECT
public:
    explicit myController(QObject *parent = nullptr);
    // Q_INVOKABLE void init();
    Q_INVOKABLE QVector<QString> getBurgers();
    Q_INVOKABLE QVector<QString> getSides();
    Q_INVOKABLE QVector<QString> getDrinks();
    Q_INVOKABLE QVector<QString> getExtras();

    // add error checking
    Q_INVOKABLE void setChosenItem(QString& chosenName, bool isBurger);
    Q_INVOKABLE QString getName();

    // Cart Operations
    Q_INVOKABLE void addToCart();
    Q_INVOKABLE int getCartSize();

    Q_INVOKABLE QVector<QString> getCartNames();
    Q_INVOKABLE QVector<double> getCartPrices();

    Q_INVOKABLE double getTotal();

    // ItemBuilder
    Q_INVOKABLE void addItem(QString& ingredient);
    Q_INVOKABLE bool isItBurger();
    Q_INVOKABLE QVector<QString>getFullList();
    Q_INVOKABLE QVector<QString>getFullPriceList();

    // images
    Q_INVOKABLE QVector<QString>burgerImages();
    Q_INVOKABLE QVector<QString>sideImages();
    Q_INVOKABLE QVector<QString>drinkImages();

    Q_INVOKABLE void clearCart();
signals:

private:
    FoodItem* m_chosenItem = nullptr;
};

#endif // MYCONTROLLER_H
