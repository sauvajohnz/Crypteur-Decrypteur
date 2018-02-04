#include "fenetreprincipale.h"
#include "fenetresecondaire.h"
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <QLabel>
#include <QPlainTextEdit>
#include <QSpinBox>

using namespace std;

FenetrePrincipale::FenetrePrincipale()
{
    setFixedSize(400,325);

    //Creation du layout de la fenêtre
    QGridLayout *layout = new QGridLayout;

    QPushButton *boutonCryptage = new QPushButton("Crypter");
    QPushButton *boutonDecryptage = new QPushButton("Decrypter");
    QPushButton *boutonQuitter = new QPushButton("Quitter");
    zoneText = new QPlainTextEdit;
    ligneCle = new QSpinBox;
    texteCle = new QLabel("Entrez une clé de cryptage/decryptage");

    zoneText->setPlainText("Mettez votre texte ici");

    layout->addWidget(ligneCle,0,1);
    layout->addWidget(texteCle,0,0,1,1);
    layout->addWidget(zoneText,1,0,1,2);
    layout->addWidget(boutonCryptage,2,0);
    layout->addWidget(boutonDecryptage,2,1);
    layout->addWidget(boutonQuitter,3,0,1,2);

    ligneCle->setMaximum(100);

    connect(boutonQuitter, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(boutonCryptage, SIGNAL(clicked(bool)), this, SLOT(onBoutonCrypterClicked()));
    connect(boutonDecryptage, SIGNAL(clicked(bool)), this, SLOT(onBoutonDecrypterClicked()));
    setLayout(layout);


}

FenetrePrincipale::~FenetrePrincipale()
{}

FenetrePrincipale::onBoutonCrypterClicked()
{
    string textAMettre;
    QString texte123;
    string texte_crypte;
    int decalage;
    decalage = ligneCle->value();

    texte123 = zoneText->toPlainText();
    texte123 = texte123.toUpper();

    textAMettre = texte123.toStdString();


    Cryptage foncteur(decalage);

    for(string::iterator it = textAMettre.begin(); it!= textAMettre.end(); it++)
    {
        if(*it>=65 && *it<=90)
        texte_crypte += foncteur.decalerLettre(*it);
        else
        texte_crypte += *it;
    }

    QString texte_crypterAEnvoyer;
    texte_crypterAEnvoyer = QString::fromStdString(texte_crypte);

    FenetreSecondaire fenetre(texte_crypterAEnvoyer);

    fenetre.exec();
}

FenetrePrincipale::onBoutonDecrypterClicked()
{
    string texteADecrypter;
    QString texte123;
    string texteDecrypter;
    int decalage;
    decalage = ligneCle->value();

    texte123 = zoneText->toPlainText();
    texte123 = texte123.toUpper();

    texteADecrypter = texte123.toStdString();


    Decryptage foncteur(decalage);

    for(string::iterator it = texteADecrypter.begin(); it!= texteADecrypter.end(); it++)
    {
        if(*it>=65 && *it<=90)
        texteDecrypter += foncteur.decalerLettre(*it);
        else
        texteDecrypter += *it;
    }

    QString texte_crypterAEnvoyer;
    texte_crypterAEnvoyer = QString::fromStdString(texteDecrypter);

    FenetreSecondaire fenetre(texte_crypterAEnvoyer);

    fenetre.exec();

}

char Cryptage::decalerLettre(char lettre)
{
    char lettreCrypter;


    lettreCrypter = (lettre + m_decalage - 'A') % 26 + 'A';

    return lettreCrypter;
}

