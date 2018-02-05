#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QWidget>
#include <QPlainTextEdit>
#include "fenetresecondaire.h"
#include <QLabel>
#include <QSpinBox>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class FenetrePrincipale : public QWidget
{

    Q_OBJECT

public:
    FenetrePrincipale();
    ~FenetrePrincipale();

    void operation(QString type);

private slots:

    onBoutonCrypterClicked();
    onBoutonDecrypterClicked();

private:
    QPlainTextEdit *zoneText;
    QSpinBox *ligneCle;
    QLabel *texteCle;

    QString text;


};

class Decryptage
{

public:
  Decryptage(int decalage) : m_decalage(decalage)
  {}
  ~Decryptage();


  char decalerLettre(char lettre)
  {
      char lettreCrypter;

      lettreCrypter = (lettre - m_decalage + 'A') % 26 + 'A';

      return lettreCrypter;
  }

private:

  int m_decalage;

};

class Cryptage
{

public:

  Cryptage(int decalage) : m_decalage(decalage)
  {}


  char decalerLettre(char lettre);


private:

  int m_decalage;

};



#endif // FENETREPRINCIPALE_H
