#include "avion.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

avion::avion()
{
    codeavion=0;
    nbplace=0;
    QString depart="";
     QString arrivee="";
     QString datee="";
     QString duree="";
}



avion::avion(int codeavion,QString depart,int nbplace,QString arrivee,QString datee,QString duree)
{
    this->codeavion=codeavion;
    this->depart=depart;
    this->nbplace=nbplace;
    this->arrivee=arrivee;
    this->datee=datee;
    this->duree=duree;
}

bool avion::ajouter2()
{
    QSqlQuery query;
    QString res=QString::number(codeavion);
    QString ress=QString::number(nbplace);
    query.prepare("INSERT INTO avionn(codeavion,depart,nbplace,arrivee,datee,duree)""VALUES(:codeavion,:depart,:nbplace,:arrivee,:datee,:duree)");
     query.bindValue(":codeavion",res);
     query.bindValue(":nbplace",ress);
    return query.exec();
}

bool avion::supprimer2(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM avionn where codeavion=:codeavion");
    query.bindValue(":codeavion",res);
    return query.exec();
}

QSqlQueryModel *avion::afficher2()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select* from avionn ");
    model->setHeaderData(0,Qt::Horizontal,"codeavion");
    model->setHeaderData(1,Qt::Horizontal,"depart");
    model->setHeaderData(2,Qt::Horizontal,"nbplace");
    model->setHeaderData(3,Qt::Horizontal,"arrivee");
    model->setHeaderData(4,Qt::Horizontal,"datee");
    model->setHeaderData(5,Qt::Horizontal,"duree");
    return model ;
}

bool avion::modifier2(int codeavion,QString depart,int nbplace,QString arrivee,QString datee,QString duree)
{
    QSqlQuery query;
    query.prepare("UPDATE avionn SET codeavion=:codeavion,depart=:depart,nbplace=:nbplace,arrivee=:arrivee,datee=:datee,duree=:duree WHERE codeavion=:codeavion");
    QString res= QString::number(codeavion);
    QString ress=QString::number(nbplace);
    query.bindValue(":codeavion",res);
    query.bindValue(":depart",depart);
     query.bindValue(":nbplace",ress);
      query.bindValue(":arrivee",arrivee);
       query.bindValue(":datee",datee);
        query.bindValue(":duree",duree);
    return query.exec();
}

QSqlQueryModel * avion::trier_codeavion()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * from avionn ORDER BY codeavion");
    model->setHeaderData(0,Qt::Horizontal,"codeavion");
    model->setHeaderData(1,Qt::Horizontal,"depart");
    model->setHeaderData(2,Qt::Horizontal,"nbplace");
    model->setHeaderData(3,Qt::Horizontal,"arrivee");
    model->setHeaderData(4,Qt::Horizontal,"datee");
    model->setHeaderData(5,Qt::Horizontal,"duree");
    return model;
}
QSqlQueryModel *  avion::chercher(int codeavion)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(codeavion);
    model->setQuery("SELECT * FROM avionn WHERE (codeavion LIKE '"+res+"' ) ");
    return  model;


}

