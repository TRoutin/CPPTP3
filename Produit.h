#pragma once

#include <string>
#include <iostream>

class Product {

public:
    //constructeur
    Product();
    Product(std::string title, std::string description, int quantity, double price);

    //getters
    std::string getTitle() const;
    std::string getDescription()const;
    int getQuantity() const;

    double getPrix() const;

    //setters
    void setTitre(std::string& title);
    void setDescription(std::string& description);
    void setQuantite(int quantity);
    void setPrix(double price);

    //surcharge
    friend std::ostream& operator<< (std::ostream& output, Product& product);

private:
    // attributes
    std::string m_title;
    std::string m_description;
    int m_quantity;
    double m_price;
};