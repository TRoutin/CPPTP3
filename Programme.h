#pragma once

#include <iostream>
#include <fstream>
#include "Magasin.h"


class Programme {
public:

    void menuPrincipal();

    //méthodes pour les données
    void writeOrders();
    void writeClients();
    void writeProducts();
private:
    void choix(char help);
    void gestionMagasin();
    void choixGestionMagasin(char help);
    void ajoutProduit(int nbr_produits);
    void modificationProduit();
    void affichageProduits();
    void affichageProduit();
    void gestionUtilisateurs();
    void choixGestionUtilisateurs(char help);
    void gestionCommandes();
    void choixGestionCommandes(char help);

private:
    Magasin m_magasin;
};