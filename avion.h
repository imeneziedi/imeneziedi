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
    avion(int,QString,int,QString,QString,QString);
    int get_codeavion(){return codeavion;}
    QString get_depart(){return depart;}
    int get_nbplace(){return nbplace;}
    QString get_arrivee(){return arrivee;}
     QString get_date(){return datee;}
      QString get_duree(){return duree;}

    bool ajouter2();
    bool supprimer2(int);
    void CREATION_PDF();

    QSqlQueryModel *afficher2();
    bool modifier2(int,QString,int,QString,QString,QString);
    QSqlQueryModel *trier_codeavion();
    QSqlQueryModel *trier_nbplace();
    QSqlQueryModel *trier_duree();


    QSqlQueryModel *stat();
    QSqlQueryModel * chercher(int);



private:
    int codeavion;
    QString depart;
    int nbplace;
    QString arrivee ;
    QString datee ;
    QString duree ;

};


#endif
