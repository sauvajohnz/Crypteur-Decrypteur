#include "fenetresecondaire.h"
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QApplication>
#include <QPushButton>

FenetreSecondaire::FenetreSecondaire(QString text)
{
    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *boutonQuitter = new QPushButton("Quitter");
    QPlainTextEdit *zoneText = new QPlainTextEdit;

    zoneText->setPlainText(text);
    zoneText->setReadOnly(true);


    layout->addWidget(zoneText);
    layout->addWidget(boutonQuitter);

    setLayout(layout);
    connect(boutonQuitter, SIGNAL(clicked(bool)), this, SLOT(accept()));

}

void FenetreSecondaire::setTextZone(QString nouveauText)
{
    m_text = nouveauText;
    m_text = "lol";
}

void FenetreSecondaire::setDecalage(int nouveauDecalage)
{
    m_decalage = nouveauDecalage;
}
