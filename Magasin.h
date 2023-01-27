#pragma once

#include "Produit.h"
#include "Client.h"
#include "Commande.h"

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

//________________________________________________

    
    void newProduct(Product product); // Add new Product method

    
    void showProducts();               // Show Products method
    void showProduct(std::string name_product); // Show product (with name) method

    
    void newQuantity(std::string name_product, int quantity); //update quantity method


private:

    // Private Attributes

    std::vector<Product> m_products;
    std::vector<Client> m_clients;
    std::vector<Commande> m_orders;
};
