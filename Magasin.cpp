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


//______________________________________________________

//  Add product method definition

void Magasin::newProduct(Product product){
    m_products.push_back(product);
}


// Show products method definition

void Magasin::showProducts(){
    for (int i =0 ; i< m_products.size(); i++)
    {
        std::cout<< m_products[i]<<std::endl;
    }
}


// Show products (with name) method definition

void Magasin::showProduct(std::string nom_product){
    for(auto& i : m_products)
        if( i.getTitre() == nom_product){
            std::cout << "\n product : \n" ;
            std::cout << i << "\n";
            break;
        }
   
}


// Qauntity method definition

void Magasin::newQuantity(std::string name_product,int quantity){
   
    if(quantite >= 0){
        for(auto& i : m_products){
       
             if( i.getTitre() == name_product){
            i.setQuantity(quantity);
            break;
             }
        }
    }
    else
        std::cout << " Invalid name ." << std::endl;
}