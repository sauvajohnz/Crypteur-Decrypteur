#include "fenetreprincipale.h"
#include "fenetresecondaire.h"
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <sstream>
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
    QPushButton *boutonForcerDecryptage = new QPushButton("Forcer le décryptage du texte");
    QPushButton *boutonQuitter = new QPushButton("Quitter");
    zoneText = new QPlainTextEdit;
    ligneCle = new QSpinBox;
    texteCle = new QLabel("Entrez une clé de cryptage/decryptage");
    incr = 0;

    zoneText->setPlainText("Mettez votre texte ici");

    layout->addWidget(ligneCle,0,1);
    layout->addWidget(texteCle,0,0,1,1);
    layout->addWidget(zoneText,1,0,1,2);
    layout->addWidget(boutonCryptage,2,0);
    layout->addWidget(boutonDecryptage,2,1);
    layout->addWidget(boutonForcerDecryptage,3,0,1,2);
    layout->addWidget(boutonQuitter,4,0,1,2);

    ligneCle->setMaximum(100);

    connect(boutonQuitter, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(boutonCryptage, SIGNAL(clicked(bool)), this, SLOT(onBoutonCrypterClicked()));
    connect(boutonDecryptage, SIGNAL(clicked(bool)), this, SLOT(onBoutonDecrypterClicked()));
    connect(boutonForcerDecryptage, SIGNAL(clicked(bool)), this, SLOT(onBoutonForcerDecrypterClicked()));
    setLayout(layout);


}

FenetrePrincipale::~FenetrePrincipale()
{}

FenetrePrincipale::onBoutonCrypterClicked()
{
    operation("Crypter", ligneCle->value());
}

FenetrePrincipale::onBoutonDecrypterClicked()
{
    operation("Decrypter", ligneCle->value());
}

FenetrePrincipale::onBoutonForcerDecrypterClicked()
{

    for (int i = 1; i<=26; i++)
        operation("ForcerDecrypter", i);
}

char Cryptage::decalerLettre(char lettre)
{
    char lettreCrypter;


    lettreCrypter = (lettre + m_decalage - 'A') % 26 + 'A';

    return lettreCrypter;
}

Decryptage::~Decryptage()
{}

void FenetrePrincipale::operation(QString type, int decalage)
{
    string textAMettre;
    QString texte123;
    string texte_crypte;
    //int decalage;
    //decalage = ligneCle->value();

    texte123 = zoneText->toPlainText();
    texte123 = texte123.toUpper();

    textAMettre = texte123.toStdString();

    if(type=="Crypter")
    {
        texte_crypte = " ";
        Cryptage foncteur(decalage);
        for(string::iterator it = textAMettre.begin(); it!= textAMettre.end(); it++)
        {
            if(*it>=65 && *it<=90)
            texte_crypte += foncteur.decalerLettre(*it);
            else
        texte_crypte += *it;
         }
    }

    if(type=="Decrypter")
    {
         Decryptage foncteur(decalage);
         for(string::iterator it = textAMettre.begin(); it!= textAMettre.end(); it++)
          {
            if(*it>=65 && *it<=90)
            texte_crypte += foncteur.decalerLettre(*it);
             else
            texte_crypte += *it;
          }

    }

    if(type=="ForcerDecrypter")
    {
        ostringstream os;
        os << decalage;
        Decryptage foncteur(decalage);
        textCrypter += "Clé [";
        textCrypter += os.str();
        textCrypter += "]  " ;
        for(string::iterator it = textAMettre.begin(); it!= textAMettre.end(); it++)
         {
           if(*it>=65 && *it<=90)
           textCrypter += foncteur.decalerLettre(*it);
            else
           textCrypter += *it;
         }
        textCrypter += "\n\n";
        incr++;

    }

    QString texte_crypterAEnvoyer;

    if (type=="ForcerDecrypter")
    {
        texte_crypterAEnvoyer = QString::fromStdString(textCrypter);
        if(incr==26)
        {
        FenetreSecondaire fenetre(texte_crypterAEnvoyer);
        fenetre.exec();
        incr = 0;
        textCrypter = " ";
        }
    }
    else
    {
    texte_crypterAEnvoyer = QString::fromStdString(texte_crypte);

    FenetreSecondaire fenetre(texte_crypterAEnvoyer);

    fenetre.exec();
    }
}


