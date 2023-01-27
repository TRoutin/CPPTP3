#include "Client.h"

Client::Client() {
    m_id = identifiant_auto_int();
}

Client::Client(std::string firstname, std::string name, std::vector<Product> cart) : m_firstname(firstname),
m_name(name), m_cart(cart) {
    m_id = identifiant_auto_int();
}
// declaration des getters
std::string Client::getName() const { 
    return m_name;
}
std::string Client::getFirstname() const { 
    return m_firstname; 
}
int Client::getId() const { 
    return m_id; 
}
std::vector<Product> Client::getCart() const { 
    return m_cart;
}

//  methode pour ajouter un produit
void Client::newProduct(Product produit, int quantite)
{
    produit.setQuantite(quantite);
    m_cart.push_back(produit);
}
// methode pour Vider le panier
void Client::emptyCart() {
    m_cart.erase(m_cart.begin(), m_cart.end());
}
// modification de la quantité d'un produit ajoute

void Client::newQuantity(Product produit, int quantite) {

    for (int i = 0; i < (int)m_cart.size(); i++)
        if (m_cart.at(i).getTitle() == produit.getTitle()) {
            m_cart.at(i).setQuantite(quantite);
            break;
        }
}

void Client::newQuantity(std::string titre, int quantite) {
    for (auto& i : m_cart)
        if (i.getTitle() == titre) {
            i.setQuantite(quantite);
            break;
        }
}

// methode pour Supprimer un produit du panier
void Client::delProduct(Product product) {
    for (int i = 0; i < (int)m_cart.size(); i++)
        if ((m_cart.at(i)).getTitle() == product.getTitle()) {
            m_cart.erase(m_cart.begin() + i);
            break;
        }
}

void Client::delProduct(std::string titre) {
    for (int i = 0; i < (int)m_cart.size(); i++)
        if ((m_cart.at(i)).getTitle() == titre) {
            m_cart.erase(m_cart.begin() + i);
            break;
        }

}

//  methode pour surcharge des operateur
std::ostream& operator<< (std::ostream& output, Client& client)
{
    output << "ID(" << client.getId() << ") " << client.getFirstname() << "\t" << client.getName();
    // \t est utilisé pour mise en forme la listation (tabulation)
    output << "\n \tCart:";
    for (int i = 0; i < (int)client.m_cart.size(); i++)
        output << "\n \t\t" << client.m_cart.at(i);
    output << "\n";

    return output;
}

int Client::identifiant_auto_int() {
    static int index = 0;
    index++;
    return index;
}