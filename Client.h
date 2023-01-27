#pragma once
#include <string>
#include <vector>
#include "Produit.h"

class Client {
public:
    //constructeur
    Client();
    Client(std::string firstname, std::string name, std::vector<Product> cart);

    //getters
    std::string getName() const;
    std::string getFirstname() const;
    int getId() const;
    std::vector<Product> getCart() const;

    // methode pour ajouter un produit au panier
    void newProduct(Product product, int quantity = 1);

    // methode pour  vider le panier
    void emptyCart();

    //  methode pour modifier la quantité d'un produit ajouté au panier
    void newQuantity(Product product, int quantity);
    void newQuantity(std::string title, int quantity);
    //Supprimer un produit du panier
    void delProduct(Product product);
    void delProduct(std::string title);

    // methode de Surcharger l'opérateur
    friend std::ostream& operator<< (std::ostream& output, Client& client);

private:
    //attribues
    std::string m_firstname;
    std::string m_name;
    int m_id;
    std::vector<Product> m_cart;

    // add unique id to client
    int identifiant_auto_int();

};

