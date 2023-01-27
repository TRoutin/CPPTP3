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

    
    void AddProduct(Product product); // Add new Product method

    
    void showProducts();               // Show Products method
    void showProduct(std::string name_product); // Show product (with name) method

    
    void updQuantity(std::string name_product, int quantity); //update quantity method

//________________________________________________


  // Add a new Client method

void AddClient(Client &client);


  // Add a new Client (specified method)

void AddClient(std::string firstname, std::string lastname);


  //Show all clients method

void showClients();


  // Show specified client method

void showClient(std::string firstname, std::string lastname);


void showClient(int id);


    // Add product to basket method

void addProductBasket(std::string title, std::string firstname, std::string lastname);


void addProductBasket(std::string title, int id); // With ID indeed (as it is asked)


    // Erase product from basket method

void DelProductBasket(std::string title, std::string firstname, std::string lastname);


void delProductBasket(std::string title, int id); // With ID indeed (as it is asked)


    // Updating quantity in client's basket method
    
void updProductQuant(std::string title, int quantity, int id);


void updProductQuant(std::string title, int quantity, std::string firstname, std::string lastname);

//____________________________________________________________


private:

    // Private Attributes

    std::vector<Product> m_products;
    std::vector<Client> m_clients;
    std::vector<Commande> m_orders;
};
