
#include "Programme.h"

void Programme::menuPrincipal() {
    char help;
    do {
        this->writeProducts();
        this->writeClients();
        this->writeOrders();
        std::cout << "\n---{MENU PRINCIPAL}---\n";
        std::cout << "\t1) Gestion du magasin \n";
        std::cout << "\t2) Gestion des utilisateurs \n";
        std::cout << "\t3) Gestion des commandes \n";
        std::cout << "\t4) Quitter le menu\n";

        std::cin >> help;
        this->choix(help);
    } while (help != '4');
}

void Programme::choix(char help) {
    if (help == '1')
        gestionMagasin();
    else if (help == '2')
        gestionUtilisateurs();
    else if (help == '3')
        gestionCommandes();
}

void Programme::gestionMagasin() {
    char help = '6';
    do {
        // le t pour lister tout les otions en forme propre
        std::cout << "\n----{Menu Gestion du Magasin}----\n";
        std::cout << "\t1) Ajouter un produit ou des produits" << std::endl;
        std::cout << "\t2) Modification d'un produit" << std::endl;
        std::cout << "\t3) Affichage de tous les produits" << std::endl;
        std::cout << "\t4) Affichage d'un produit" << std::endl;
        std::cout << "\t5) Revenir au menu precedent\n" << std::endl;
        std::cin >> help;
        choixGestionMagasin(help);
    } while (help != '5');
}

void Programme::choixGestionMagasin(char help) {
    if (help == '1') {
        int nbr_produits;
        std::cout << "Saisir le nombre de produits que vous voulez saisir : ";
        std::cin >> nbr_produits;
        ajoutProduit(nbr_produits);
        writeProducts();
    }
    else if (help == '2') {
        modificationProduit();
        writeProducts();
    }
    else if (help == '3') {
        affichageProduits();
        writeProducts();
    }
    else if (help == '4') {
        affichageProduit();
        writeProducts();
    }
}

void Programme::ajoutProduit(int nbr_produits) {

    for (int i = 0; i < nbr_produits; i++) {
        std::cout << " entrer le nom du produit : ";
        std::string titre;
        std::cin.ignore();
        std::getline(std::cin, titre);
        std::cout << "Saisir la description du produit : ";
        std::string description;
        std::getline(std::cin, description);
        std::cout << "indiquer la quantite du produit : ";
        int quantite;
        std::cin >> quantite;
        std::cout << "Saisir le prix du produit : ";
        double prix;
        std::cin >> prix;

        m_magasin.addProductStore(titre, description, prix, quantite);
        writeProducts();
    }
}

void Programme::modificationProduit() {
    char help = '9';
    while (help != '4') {
        std::cout << "\t1) Modifier la quantité d'un produit\n";
        std::cout << "\t2) Modifier le prix d'un produit\n";
        std::cout << "\t3) Modifier la description d'un produit\n";
        std::cout << "\t4) Revenir au menu precedent\n";
        std::cin >> help;

        if (help != '4') {
            if (help == '1') {
                std::cout << "Le nom du produit : ";
                std::string titre;
                std::cin.ignore();
                std::getline(std::cin, titre);
                //chercher le prodwit du magasin
                if (m_magasin.productExist(titre)) {
                    Product* produit = m_magasin.productFind(titre);
                    int quantite;
                    std::cout << "Entrer la nouvelle quantite du produit : ";
                    std::cin >> quantite;
                    produit->setQuantite(quantite);
                }
                else
                    std::cout << " le produit n'existe pas dans le magasin. \n";
            }

            else if (help == '2') {
                std::cout << "Le nom du produit : ";
                std::string titre;
                std::cin.ignore();
                std::getline(std::cin, titre);
                //chercher le produit dans le magasin
                if (m_magasin.productExist(titre)) {
                    Product* produit = m_magasin.productFind(titre);
                    int prix;
                    std::cout << "Entrer le nouveau prix du produit : ";
                    std::cin >> prix;
                    produit->setPrix(prix);
                }
                else
                    std::cout << "le produit n'existe pas  dans le magasin. \n";
            }

            else if (help == '3') {
                std::cout << "Le nom du produit : ";
                std::string titre;
                std::cin.ignore();
                std::getline(std::cin, titre);
                //chercher le produit dans le magasin
                if (m_magasin.productExist(titre)) {
                    Product* produit = m_magasin.productFind(titre);
                    std::string description;
                    std::cout << "Entrer la nouvelle description du produit : ";
                    std::getline(std::cin, description);
                    produit->setDescription(description);
                }
                else
                    std::cout << "le produit n'existe pas  dans le magasin. \n";
            }

        }

    }
    writeProducts();
}

void Programme::affichageProduits() {
    std::cout << "\tAffichage de tous les produits\n";
    m_magasin.showProducts();
}

void Programme::affichageProduit() {
    std::cout << "Saisir le titre du produit\n";
    std::string titre;
    std::cin.ignore();
    std::getline(std::cin, titre);
    if (m_magasin.productExist(titre)) {
        std::cout << "\tAffichage du produit " << titre << std::endl;
        m_magasin.showProduct(titre);
    }
    else
        std::cout << "le produit n'existe pas  dans le magasin. \n";
}



void Programme::gestionUtilisateurs() {
    char help = '9';
    while (help != '6') {
        std::cout << "\n-----{{Menu Gestion des Utilisateur}}------\n";
        std::cout << "\t1) Ajouter un nouveau client" << std::endl;
        std::cout << "\t2) Modifier le panier d'un client" << std::endl;
        std::cout << "\t3) Afficher tous les clients" << std::endl;
        std::cout << "\t4) Afficher un client" << std::endl;
        std::cout << "\t5) Afficher un client et son panier" << std::endl;
        std::cout << "\t6) Revenir au menu precedent" << std::endl;

        std::cin >> help;
        if (help != '6')
            choixGestionUtilisateurs(help);
    }
}



void Programme::choixGestionUtilisateurs(char help) {
    //Ajouter  d'un nouveau client au amgasin
    if (help == '1') {
        std::cout << "Entrer le prenom du client : ";
        std::string prenom;
        std::cin.ignore();
        std::getline(std::cin, prenom);
        std::cout << "Entrer  le nom du client : ";
        std::string nom;
        std::getline(std::cin, nom);
        m_magasin.AddClient(prenom, nom);
        writeClients();
    }


    else if (help == '2') {
        char aide = '4';
        while (aide != '3') {
            std::cout << "\t1) Modifier le panier d'un client et indiquer le  nom et le  prénom\n";
            std::cout << "\t2) Modifier le panier d'un client et indiquer son ID\n";
            std::cout << "\t3) Revenir au menu precedent\n";
            std::cin >> aide;


            if (aide != '3') {
                if (aide == '1') {
                    std::cout << "Le prenom du client : ";
                    std::string prenom;
                    std::cin.ignore();
                    std::getline(std::cin, prenom);

                    std::cout << "Le nom du client : ";
                    std::string nom;
                    std::getline(std::cin, nom);

                    //See if the customer exists
                    bool client_exist = false;
                    //look for the client
                    for (auto& i : m_magasin.getClients())
                        if (i.getFirstname() == prenom || i.getName() == nom) {
                            client_exist = true;
                            break;
                        }

                    if (client_exist) {
                        std::cout << "\t1) Ajouter un produit au panier du client\n";
                        std::cout << "\t2) Supprimer un produit du panier du client\n";
                        std::cout << "\t3) Modifier la quantité d'un produit dans le panier du client\n";
                        std::cout << "\t4) Revenir au menu precedent\n";
                        char tmp;
                        std::cin >> tmp;

                        if (tmp != '4') {
                            std::cout << "Saisir le nom du produit : ";
                            std::string titre;
                            std::cin.ignore();
                            std::getline(std::cin, titre);
                            if (tmp == '1') {
                                m_magasin.addProductBasket(titre, prenom, nom);
                                std::cout << "Produit ajoute au panier\n";
                            }
                            else if (tmp == '2') {
                                m_magasin.DelProductBasket(titre, prenom, nom);
                                std::cout << "Produit supprimer du panier du clien\n";
                            }
                            else if (tmp == '3') {
                                std::cout << "Saisir la nouvelle quantité du produit\n";
                                int quantite;
                                std::cin >> quantite;
                                m_magasin.updProductQuant(titre, quantite, prenom, nom);
                            }
                        }
                    }
                    // si le client n existe pas
                    else
                        std::cout << "Erreur : client n' existe \n";

                }


                else if (aide == '2') {
                    std::cout << "L'ID du client : ";
                    int id;
                    std::cin >> id;

                    //Voir si le client se trouve
                    bool client_exist = false;
                    //chercher le client
                    for (auto& i : m_magasin.getClients())
                        if (i.getId() == id) {
                            client_exist = true;
                            break;
                        }

                    if (client_exist) {
                        std::cout << "\t1) Ajouter un produit au panier du client\n";
                        std::cout << "\t2) Supprimer un produit du panier du client\n";
                        std::cout << "\t3) Modifier la quantité d'un produit dans le panier du client\n";
                        std::cout << "\t4) Revenir au menu precedent\n";
                        char tmp;
                        std::cin >> tmp;

                        if (tmp != '4') {
                            std::cout << "Saisir le nom du produit : ";
                            std::string titre;
                            std::cin.ignore();
                            std::getline(std::cin, titre);
                            if (tmp == '1') {
                                m_magasin.addProductBasket(titre, id);
                                std::cout << "Produit ajouté au panier\n";
                            }
                            else if (tmp == '2') {
                                m_magasin.delProductBasket(titre, id);
                                std::cout << "Produit supprimer du panier du clien\n";
                            }
                            else if (tmp == '3') {
                                std::cout << "Entrer  la nouvelle quantité du produit\n";
                                int quantite;
                                std::cin >> quantite;
                                m_magasin.updProductQuant(titre, quantite, id);
                            }
                        }
                    }

                }
            }

        }
        writeClients();
    }

    //afficher tous les  clients
    else if (help == '3') {
        std::cout << "\tAffichage de tous les clients\n";
        m_magasin.showClients();
        writeClients(); //make sure the file is up to date
    }


    else if (help == '4') {
        std::cout << "\t1) Saisir le prenom et le nom du client\n";
        std::cout << "\t2) Saisir l'ID du client\n";
        char aide;
        std::cin >> aide;

        if (aide == '1') {
            std::cout << "Saisir le prenom du client : ";
            std::string prenom;
            std::cin.ignore();
            std::getline(std::cin, prenom);
            std::cout << "Saisir le nom du client : ";
            std::string nom;
            std::getline(std::cin, nom);
            //test the customer's existence
            if (m_magasin.IsClient(prenom, nom)) {
                std::cout << "\tAffichage du client\n";
                m_magasin.showClient(prenom, nom);
            }
        }


        if (aide == '2') {
            std::cout << "Saisir l'ID du client : ";
            int id;
            std::cin >> id;

            if (m_magasin.IsClient(id)) {
                std::cout << "\tAffichage du client\n";
                m_magasin.showClient(id);
            }
        }
        writeClients();
    }


    else if (help == '5') {
        std::cout << "\t1) Saisir le prenom et le nom du client\n";
        std::cout << "\t2) Saisir l'ID du client\n";
        char aide;
        std::cin >> aide;

        if (aide == '1') {
            std::cout << "Saisir le prenom du client : ";
            std::string prenom;
            std::cin.ignore();
            std::getline(std::cin, prenom);
            std::cout << "Saisir le nom du client : ";
            std::string nom;
            std::getline(std::cin, nom);

            if (m_magasin.IsClient(prenom, nom)) {
                for (auto& i : m_magasin.getClients())
                    if (i.getFirstname() == prenom && i.getName() == nom) {
                        std::cout << "\tAffichage du client et de son panier\n";
                        std::cout << i << std::endl;
                        break;
                    }
            }
        }


        if (aide == '2') {
            std::cout << "Saisir l'ID du client : ";
            int id;
            std::cin >> id;
            //test the customer's existence
            if (m_magasin.IsClient(id)) {
                for (auto& i : m_magasin.getClients())
                    if (i.getId() == id) {
                        std::cout << "\tAffichage du clien avec son panier\n";
                        std::cout << i << std::endl;
                        break;
                    }
            }
        }
    }
    writeClients();
}


void Programme::gestionCommandes() {
    char help = '9';
    while (help != '5') {
        std::cout << "\n------{{Menu Gestion des Commandes}}------\n";
        std::cout << "\t1) Ajouter une commande" << std::endl;
        std::cout << "\t2) Modifier le statut d'une commande" << std::endl;
        std::cout << "\t3) Afficher toutes les commandes de tous les clients" << std::endl;
        std::cout << "\t4) Afficher toutes les commandes d'un client" << std::endl;
        std::cout << "\t5) Revenir au menu precedent" << std::endl;

        std::cin >> help;
        if (help != '5') {
            choixGestionCommandes(help);
            writeOrders();
        }
    }
}

void Programme::choixGestionCommandes(char help) {

    if (help == '1') {
        std::cout << "\t1) Ajouter  une commande d'un client en indiquant son nom et son prenom\n";
        std::cout << "\t2) Ajouter  une commande d'un client en indiquant  son ID \n";
        char aide;
        std::cin >> aide;

        if (aide == '1') {
            std::cout << "Saisir le prenom du client : ";
            std::string prenom;
            std::cin.ignore();
            std::getline(std::cin, prenom);
            std::cout << "Saisir le nom du client : ";
            std::string nom;
            //std::cin.ignore();
            std::getline(std::cin, nom);

            if (m_magasin.IsClient(prenom, nom)) {
                m_magasin.validOrder(prenom, nom);
                std::cout << "Commande validee" << std::endl;
            }
            else
                std::cout << "la commande n'est pas validee, client n'existe pas .\n";
        }

        if (aide == '2') {
            std::cout << "Saisir l'ID du client : ";
            int id;
            std::cin >> id;

            if (m_magasin.IsClient(id)) {
                m_magasin.validOrder(id);
                std::cout << "Commande valide" << std::endl;
            }
            else
                std::cout << "la commande n'est pas validee , client n'existe pas .\n";
        }

        writeOrders();
    }


    else if (help == '2') {
        std::cout << "1) Modifier le statut d'une commande en indiquant son ID\n";
        std::cout << "2) Modifier le statut d'une commande en indiquant le nom et le prenom du client\n";

        char aide = '3';
        std::cin >> aide;
        //modification du statut en utilisant l'ID
        if (aide == '1') {
            std::cout << "Saisir l'ID de la commande : ";
            int id;
            std::cin >> id;
            std::cout << "Saisir le nouveau statut de la commande : ";
            int status_int;
            std::cin >> status_int;
            bool status;
            // si 0 c est faulse 1 c est vrais
            status_int == 0 ? status = false : status = true;

            m_magasin.updOrderStatus(id, status);
            writeOrders();
        }

        if (aide == '2') {
            std::cout << "Saisir le prenom du client : ";
            std::string prenom;
            std::cin.ignore();
            std::getline(std::cin, prenom);

            std::cout << "Saisir le nom du client : ";
            std::string nom;
            std::getline(std::cin, nom);

            if (m_magasin.IsClient(prenom, nom)) {
                Client* client = m_magasin.clientFind(prenom, nom);
                std::cout << "Saisir le nouveau statut de la commande: ";
                int status_int;
                std::cin >> status_int;
                bool status;
                //equivalent to if statement
                status_int == 0 ? status = false : status = true;

                m_magasin.updOrderStatus(client->getId(), status);
            }
            else
                std::cout << "le  client n esxiste pas .\n";
        }
        writeOrders();
    }


    else if (help == '3') {
        std::cout << "------Affichageles  commandes de tous les clients------\n";

        for (auto& i : m_magasin.getOrders())
            m_magasin.showClientOrders(i.getClient()->getFirstname(), i.getClient()->getName());

        std::cout << std::endl;
    }


    else if (help == '4') {
        std::cout << "1) Afficher les commandes d'un client en indiquant  son ID\n";
        std::cout << "2) Afficher les commandes d'un client en indiquant   son nom et son  prenom\n";
        char aide = '3';
        std::cin >> aide;

        if (aide == '1') {
            std::cout << "Saisir l'ID du client : ";
            int id;
            std::cin >> id;
            m_magasin.showClientOrders(id);
        }

        else if (aide == '2') {
            std::cout << "Saisir le prenom du client : ";
            std::string prenom;
            std::cin.ignore();
            std::getline(std::cin, prenom);
            std::cout << "Saisir le nom du client : ";
            std::string nom;
            std::getline(std::cin, nom);
            m_magasin.showClientOrders(prenom, nom);
        }
    }
}


//ecrire la commande
void Programme::writeOrders() {
    std::ofstream monFlux("./Orders.txt");
    if (monFlux) {
        monFlux << "---FILE  DES COMMANDES--------\n\n";
        for (auto& i : m_magasin.getOrders()) {
            monFlux << std::endl;
            monFlux << i << std::endl;
        }
    }
    else
        std::cout << " on ne peut pas ouvrir le fichier.\n";
}


void Programme::writeClients() {
    std::ofstream monFlux("./Clients.txt");
    if (monFlux) {
        monFlux << "--------FILE  DES CLIENTS--------\n\n";
        for (auto& i : m_magasin.getClients()) {
            monFlux << std::endl;
            monFlux << i << std::endl;
        }
    }
    else
        std::cout << "on ne peut pas ouvrir le fichiers.\n";
}


void Programme::writeProducts() {
    std::ofstream monFlux("./Products.txt");
    if (monFlux) {
        monFlux << "--------FILE DES PRODUITS--------\n\n";
        for (auto& i : m_magasin.getProducts()) {
            monFlux << std::endl;
            monFlux << i << std::endl;
        }
    }
    else
        std::cout << "on ne peut pas ouvrir le fichiers.\n";

}