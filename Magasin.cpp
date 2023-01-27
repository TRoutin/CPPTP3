#include "Magasin.h"

// Default Constructor Definition
Magasin::Magasin(){

}

// Parametrized Consctrucor Definition

Magasin::Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders){
   
}

//______________________________________________________


// Getters Definition
std::vector <Product > Magasin::getProducts() const { return m_products ;}
std::vector <Client > Magasin::getClients() const { return m_clients ;}
std::vector <Commande > Magasin::getOrders() const { return m_orders ;}


// IMPORTANT, J'ai fais le choix de déclarer mes vector avec des types Product Client et Commande,
// car thomas travaille déjà dessus, ça m'évitera de les changer après (bien que je ne pourrai pas tester tout de suite dans le main)