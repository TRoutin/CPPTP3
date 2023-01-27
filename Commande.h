#pragma once
#include "Client.h"
#include <vector>

class Commande {

public:
    //constructors
    Commande();
    Commande(Client& client, bool delivery = false);

    // setters
    void setClient(Client& client);
    void setdelivery(bool delivery);

    //getters
    Client* getClient() const;
    std::vector<Product> getProduct() const;
    int getId() const;
    bool getdelivery() const;

    // methode pour surcharger l'opérateur
    friend std::ostream& operator<< (std::ostream& output, Commande& commande);
private:
    // private member
    Client* m_client;
    std::vector<Product> m_products;
    bool m_delivery;
    int m_id;
    int identifiant_auto_int();
};