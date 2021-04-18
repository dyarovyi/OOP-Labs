#ifndef SENDINGS_HPP
#define SENDINGS_HPP

#include <iostream>

using namespace std;

// Міста
//----------------------------------------------------------------------------------
const string citiesEng[] = {"Lviv", "Kyiv", "Kharkiv", "Odesa", "Zaporizhzhia", "Vinnytsia"};
const string citiesUkr[] = {"Львів", "Київ", "Харків", "Одеса", "Запоріжжя", "Вінниця"};
const double otherCitiesTax = 1.5;


// Відправлення
//----------------------------------------------------------------------------------
class Sendings
{
protected:
    int quantity;

public:
    Sendings();
    Sendings(int);
    ~Sendings();

    void setQuantity(int);
    int getQuantity();

    virtual string print();
};


// Бандероль
//----------------------------------------------------------------------------------
class Package: public Sendings
{
protected:
    static double tarriff;

    double weight;
    string city;

public:
    Package();
    Package(int, double, string);
    ~Package();

    void setWeight(int);
    void setCity(string);

    double getTarriff();
    double getWeight();
    string getCity();

    double calculatePrice();

    virtual string print();
};


/*// Бандероль з оголошеною цінністю
//----------------------------------------------------------------------------------
class Value: public Sendings
{
protected:
    static double tarriff;

    double weight;
    double value;
    string city;

public:
    Value();
    Value(int, double, double, string);
    ~Value();

    void setWeight(int);
    void setValue(int);
    void setCity(string);

    double getTarriff();
    double getWeight();
    double getValue();
    string getCity();

    double calculatePrice();
};*/


// Бандероль з оголошеною цінністю
//----------------------------------------------------------------------------------
class Value: protected Package
{
protected:
    static double tarriff;

    double value;

public:
    Value();
    Value(int, double, double, string);
    ~Value();

    void setValue(int);
    double getValue();

    double calculatePrice();

    virtual string print();
};


// Електронний переказ
//----------------------------------------------------------------------------------
class Transfer: public Sendings
{
protected:
    static double tarriff;

public:
    Transfer();
    Transfer(int);
    ~Transfer();

    double getTarriff();

    double calculatePrice();

    virtual string print();
};

#endif // SENDINGS_HPP
