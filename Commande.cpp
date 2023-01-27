#include "Commande.h"

// definition des constructors
Commande::Commande() {
    m_id = identifiant_auto_int();
}

Commande::Commande(Client& client, bool delivery) : m_client(&client), m_delivery(delivery) {
    m_id = identifiant_auto_int();

    m_products.reserve(m_client->getCart().size());
    for (auto& i : m_client->getCart()) {
        m_products.push_back(i);
    }

}


// definition des setters
void Commande::setClient(Client& client) { m_client = &client; }

void Commande::setdelivery(bool delivery) { m_delivery = delivery; }



// defenition des getteurs getters
Client* Commande::getClient()const { return m_client; }
std::vector<Product> Commande::getProduct() const { return m_products; }
int Commande::getId() const { return m_id; }
bool Commande::getdelivery() const { return m_delivery; }

//Surcharge d'opérateur
std::ostream& operator<< (std::ostream& output, Commande& commande) {
    std::string status;
    commande.m_delivery ? status = "Delivered" : status = "Not Delivered";

    output << "\nCommande n°" << commande.getId() << "\t Status: " << status;
    // \t est utilisé pour mise en forme la listation (tabulation)
    output << "\n\t" << "(" << commande.m_client->getId() << ")" << commande.m_client->getName()
        << "\t" << commande.m_client->getFirstname() << std::endl;

    for (auto& i : commande.m_products)
        output << "\t\t" << i << std::endl;

    output << "\n";
    return output;
}


int Commande::identifiant_auto_int() {
    static int index = 0;
    index++;
    return index;
}