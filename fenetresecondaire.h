#ifndef FENETRESECONDAIRE_H
#define FENETRESECONDAIRE_H

#include <QDialog>

class FenetreSecondaire : public QDialog
{
    Q_OBJECT

public:
    FenetreSecondaire(QString text);
    void setTextZone(QString nouveauText);
    void setDecalage(int nouveauDecalage);

private:

    QString m_text;
    int m_decalage;
};

#endif // FENETRESECONDAIRE_H
