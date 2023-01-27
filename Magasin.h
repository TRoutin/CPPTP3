#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Magasin {
public:

    Magasin(); // Default Constructor 

    Magasin(std::vector<Product> &products, std::vector<Client> &clients, std::vector<Commande> &orders); // Parametrized constructor

//_________________________________________________

    // Getters Declaration

    std::vector<Product> getProducts() const;

    std::vector<Client> getClients() const;

    std::vector<Commande> getOrders() const;


private:

    // Private Attributes

    std::vector<Product> m_products;
    std::vector<Client> m_clients;
    std::vector<Commande> m_orders;
};
