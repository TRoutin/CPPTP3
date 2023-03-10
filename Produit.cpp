#include "Produit.h"
#include "Produit.h"
// defenition des constructeur
Product::Product() {

}

Product::Product(std::string title, std::string description, int quantity, double price) :
    m_title(title), m_description(description), m_quantity(quantity), m_price(price) {

}
// definition des getters
std::string Product::getTitle() const { 
    return m_title;
}
std::string Product::getDescription() const { 
    return m_description;
}
int Product::getQuantity() const { 
    return m_quantity; 
}
double Product::getPrix() const { 
    return m_price; 
}
// definition des setters
void Product::setTitre(std::string& title) { 
    m_title = title; 
}
void Product::setDescription(std::string& description) { 
    m_description = description;
}
void Product::setQuantite(int quantity) {
    if (quantity > 0 || quantity == 0)
        m_quantity = quantity;
    else {
        m_quantity = 0;
        std::cout << " la quantite d'un produit par defaut   " << getTitle() << " est 0.\n";
    }
}
void Product::setPrix(double prix) {
    while (prix < 0 || prix == 0) {
        std::cout << " Inserer le  prix valide " << std::endl;
        std::cin >> prix;
    }
    if (prix > 0)
        m_price = prix;
}

//defenition de surcharge de l operateur
std::ostream& operator<< (std::ostream& output, Product& product) {
    output << "title = " << product.getTitle() << std::endl << "description = " << product.getDescription() << std::endl << "quantity = " << product.getQuantity() << std::endl << " price =" << product.getPrix() << std::endl;
    return output;
}