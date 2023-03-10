#include "Magasin.h"
#pragma warning(disable : 4703)

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
        if( i.getTitle() == nom_product){
            std::cout << "\n product : \n" ;
            std::cout << i << "\n";
            break;
        }
   
}


// Qauntity method definition

void Magasin::updQuantity(std::string name_product,int quantity){
   
    if(quantity >= 0){
        for(auto& i : m_products){
       
             if( i.getTitle() == name_product){
            i.setQuantite(quantity);
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
        std::cout << i.getFirstname() << " " << i.getName() << std::endl ;
    }
    std::cout << std::endl;
    
}

// Show client (specified) method definition

void Magasin::showClient(std::string firstname, std::string lastname){
    for(auto& i : m_clients){
        if( i.getFirstname() == firstname &&  i.getName() == lastname){
            std::cout << "\t Affichage du client\n";
            std::cout << "Uid" ;
            for(int i = 0 ; i < 9 ; i++)
                std::cout << " ";
            std::cout << "Identifiant\n";
            std::cout << i.getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i.getId()).length() - 3; j++)
                std::cout << " ";
             std::cout << i.getFirstname() << " " << i.getName() << std::endl ;

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
             std::cout << i.getFirstname() << " " << i.getName() << std::endl ;
            break;
        }
    }
}

// Add product to cart method definition

void Magasin::addProductBasket(std::string title, std::string firstname, std::string lastname){
    for(auto& i : m_products)
        if( i.getTitle() == title){
            for(auto& j : m_clients)
                if( j.getFirstname() == firstname || j.getName() == lastname ){
                    j.newProduct(i);
                    break;
                }
            break;
        }
}

// Add product to cart with id method definition

void Magasin::addProductBasket(std::string title, int id ){

    for(auto& i : m_products)
        if( i.getTitle() == title){
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
        if( i.getTitle() == title){
            for(auto& j : m_clients)
                if( j.getFirstname() == firstname || j.getName() == lastname){
                    j.delProduct(title);
                    break;               
                }
            break;}
}

// Delete product basked with id method definition

void Magasin::delProductBasket(std::string title, int id){
    for(auto& i : m_products)
        if( i.getTitle() == title){
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
        if( i.getTitle() == title){
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
        if( i.getTitle() == title){
            for(auto& j : m_clients)
                if( j.getFirstname() == firstname || j.getName() == lastname){
                    j.newQuantity(title, quantity);
                    break;
                }
            break;
        }  
}

//______________________________________________________________


// Order validation method definition

bool Magasin::validOrder(Client& client){
    bool valide = true ;
    for(auto& i:client.getCart())
        for(auto& j:m_products)
            if(i.getTitle() == j.getTitle())
                if( i.getQuantity() >= j.getQuantity()){
                    valide = false;
                    std::cout << " Il y a -- produits "
                              << i.getTitle() << " -- est : " << j.getQuantity();
                    }                                     

    if(valide){
        Commande commande(client);
        m_orders.push_back(commande);
        //modifier la quantit?? des produits est present  apr??s  validation
        for(auto& i :client.getCart())
            for(auto& j: m_products)
                if(i.getTitle() == j.getTitle()){
                    int quantite_restee;
                    quantite_restee = j.getQuantity() - i.getQuantity();
                    j.setQuantite(quantite_restee);
                }

        std::cout << "Valid command" << std::endl;
        client.emptyCart();
    }

    else
        std::cout << " Command not found " << std::endl;
    
    return valide;
}


// (specificated) definition

bool Magasin::validOrder(std::string firstname, std::string lastname){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    //v??rifier que le client existe
    for(auto&i : m_clients)
        if(i.getFirstname() == firstname && i.getName() == lastname ){
            client = &i;
            client_trouve = true ;
            break;
        }

    if(client_trouve)
    for(auto& i:client -> getCart())
        for(auto& j:m_products)
            if(i.getTitle() == j.getTitle())
                if( i.getQuantity() >= j.getQuantity()){
                    valide = false;
                    std::cout << "  Il y a -- produits "
                              << i.getTitle() << " -- est : " << j.getQuantity();
                    }                                     

    if(valide){
        Commande commande(*client);
        m_orders.push_back(commande); 
        for(auto& i :client->getCart())
            for(auto& j: m_products)
                if(i.getTitle() == j.getTitle()){
                    int quantite_restee;
                    quantite_restee = j.getQuantity() - i.getQuantity();
                    j.setQuantite(quantite_restee);
                }

        std::cout << " Valid command" << std::endl;
        client->emptyCart();
    }
    else if(!client_trouve)
        std::cout << "Order nor found , no client found" << std::endl;
    
    return valide;
}
bool Magasin::validOrder(int id){
    bool valide = true ;
    Client *client;
    bool client_trouve = false;
    //v??rification que le  client existe
    for(auto&i : m_clients)
        if(i.getId() == id ){
            client = &i;
            client_trouve = true ;
            break;
        }


    for(auto& i:client->getCart())
        for(auto& j:m_products)
            if(i.getTitle() == j.getTitle())
                if( i.getQuantity() > j.getQuantity()){
                    valide = false;
                    std::cout << "[ERROR - UNVALID] PRODUCT'S QUANTITY   "
                              << i.getTitle() << "  is : " << j.getQuantity() << ". Client asked for " << i.getQuantity() << std::endl;
                    }                                     

    if(valide){
        Commande commande(*client);
        m_orders.push_back(commande); 
        std::cout << "Valid command" << std::endl;
        client->emptyCart();
    }
    else if(!client_trouve)
        std::cout << " Order nor found , no client found" << std::endl;
    
    return valide;
}



// Update order status method definition

bool Magasin::updOrderStatus(int id , bool status){
    //trouver la commande en se servant de son id
    bool commande_trouvee = false;

    for(auto&i : m_orders)
        if(i.getId() == id ){
            i.setdelivery(status);
            commande_trouvee = true ;
            break;
        }    
    
    if(commande_trouvee)
        std::cout << "Update order status successful\n";
    else
        std::cout << "ERROR in update order status  \n";

    return commande_trouvee ;   
}



// Showpastorders method definition

void Magasin::showPastOrders(){
    std::cout << "\t---Affichage des commandes pass??es---\n";
    for(auto& i : m_orders)
        if(i.getdelivery())
            std::cout << i << std::endl;
}


// Show orders from a client (id) method

void Magasin::showClientOrders(int id){
    std::cout << "\t---Affichage des commandes du client qui a l'ID suivant  " << id << " ---\n";
    for(auto& i : m_orders){
        std::cout << " afficher le client avec son ID " << std::endl;
        if( i.getClient()->getId() == id)
            std::cout << i << std::endl;
    }

}


// (specified) definition

void Magasin::showClientOrders(std::string firstname, std::string lastname){
    std::cout << "\t---Affichage des commandes du client " << firstname << " "<< lastname << " ---\n";
    for(auto& i : m_orders)
        if( i.getClient()->getFirstname() == firstname && i.getClient()->getName() == lastname)
            std::cout << i << std::endl;
}

// IsProduct method definition

bool Magasin::productExist(std::string title){
    for(auto&i : m_products)
        if(i.getTitle() == title)
            return true;
    return false;
}

// ProductFind method definition

Product* Magasin::productFind(std::string title){
    for(auto&i : m_products)
        if(i.getTitle() == title)
            return &i;
    //si on trouve pas le produit correspondant on fait un return
    return nullptr;
}

// IsClient method definition

bool Magasin::IsClient(std::string firstname, std::string lastname){
    for(auto& i:m_clients)
        if( i.getFirstname() == firstname && i.getName() == lastname)
            return true ;

    return false ;
}

// IsClient method definition with id

bool Magasin::IsClient(int id){
    for(auto& i:m_clients)
        if( i.getId() == id)
            return true;
    
    return false;
}

// ClientFind method definition

Client* Magasin::clientFind(std::string firstname , std::string lastname){
    if(IsClient(firstname,lastname)){
        for(auto& i:m_clients)
            if( i.getFirstname() == firstname && i.getName() == lastname)
                return &i ;//client trouv??
    } 
    
    else
        std::cout << " client n'existe pas \n";
    
    return nullptr;
}
