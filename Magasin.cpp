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

void Magasin::AddProduct(Product product){
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

void Magasin::updQuantity(std::string name_product,int quantity){
   
    if(quantity >= 0){
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


//___________________________________________________________



// Add new client method definition

void Magasin::AddClient(Client& client){
    m_clients.push_back(client) ;
}

// Add new client method definition with name

void Magasin::AddClient(std::string firstname, std::string lastname) {
    std::vector<Product> basket;
    Client client = Client(firstname, lastname, basket);
    m_clients.push_back(client) ;

}

void Magasin::newOrder(Commande& order){
    m_orders.push_back(order) ;

}


// Show all client method definition

void Magasin::showClients(){

    std::cout << "\nClients\n";
    std::cout << "Uid" ;

    for(int i = 0 ; i < 9 ; i++) {
        std::cout << " ";
    }
    std::cout << "Identifiant \n";

    for(auto& i:m_clients){
        std::cout << i.getId() ;
        for(int j = 0 ; j < 12 - (int)std::to_string(i.getId()).length() ; j++)
            {std::cout << " ";}
        std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;
    }
    std::cout << std::endl;
    
}

// Show client (specified) method definition

void Magasin::showClient(std::string firstname, std::string lastname){
    for(auto& i : m_clients){
        if( i.getPrenom() == firstname &&  i.getNom() == lastname){
            std::cout << "\t Affichage du client\n";
            std::cout << "Uid" ;
            for(int i = 0 ; i < 9 ; i++)
                std::cout << " ";
            std::cout << "Identifiant\n";
            std::cout << i.getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i.getId()).length() - 3; j++)
                std::cout << " ";
             std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;

            break;
        }
    }
}

//Show Client id method definition

void Magasin::showClient(int id){
    for(auto& i : m_clients){
        if ( i.getId() == id){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int j = 0 ; j < 7 ; j++)
                std::cout << " ";
            std::cout << "Identifiant\n";
            std::cout << i.getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i.getId()).length() - 3; j++)
                std::cout << " ";
             std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;
            break;
        }
    }
}

// Add product to cart method definition

void Magasin::addProductBasket(std::string title, std::string firstname, std::string lastname){
    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getPrenom() == firstname || j.getNom() == lastname ){
                    j.newProduct(i);
                    break;
                }
            break;
        }
}

// Add product to cart with id method definition

void Magasin::addProductBasket(std::string title, int id ){

    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getId() == id){
                    j.newProduct(i);
                    break;
                }  
             break;
        }
}

// Add product to store method definition

void Magasin::addProductStore(std::string lastname, std::string description, float prix, int quantity){
    Product product = Product(lastname, description, quantity, prix);
    m_products.push_back(product);
}


// Delete product basket method definition

void Magasin::DelProductBasket(std::string title, std::string firstname, std::string lastname){
    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getPrenom() == firstname || j.getNom() == lastname){
                    j.delProduct(title);
                    break;               
                }
            break;}
}

// Delete product basked with id method definition

void Magasin::delProductBasket(std::string title, int id){
    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getId() == id ){
                    j.delProduct(title);
                    break;
                }
            break;
        }
}

// Update product quantity basket method definition with id

void Magasin::updProductQuant(std::string title, int quantity, int id){
    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getId() == id ){
                    j.newQuantity(title, quantity);
                    break;
                }
            break;
        }
}

// Update prodcut quantity basked method definition

void Magasin::updProductQuant(std::string title, int quantity, std::string firstname, std::string lastname){
    for(auto& i : m_products)
        if( i.getTitre() == title){
            for(auto& j : m_clients)
                if( j.getPrenom() == firstname || j.getNom() == lastname){
                    j.newQuantity(title, quantity);
                    break;
                }
            break;
        }  
}