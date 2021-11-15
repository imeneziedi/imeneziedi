#ifndef AVION_H
#define AVION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>
class avion
{
public:
    avion();
    avion(int,QString,int,int);
    int get_code_ingredient(){return codeingredient;}
    QString get_type_ingredient(){return type;}
    int get_prix_ingredient(){return prix;}
    int get_quantite(){return quantite;}

    bool ajouter2();
    bool supprimer2(int);
    QSqlQueryModel *afficher2();
    bool modifier2(int,QString,int,int);
    QSqlQueryModel *trier_codeingredient();
    QSqlQueryModel *stat();


private:
    int codeingredient;
    QString type;
    int prix;
    int quantite;
};


#endif
