
#include "employe.h"
#include "connection.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
employe::employe()
{
    codeemploye=0;
    cin=0;
    nom="";
    prenom="";
    
}

employe::employe(int codeemploye,int cin, QString nom,QString prenom)
{
    this->codeemploye=codeemploye;
    this->cin=cin;
    this->prenom=prenom;
    this->nom=nom;
    
}

bool employe::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(codeemploye);
    QString ress=QString::number(cin);
    query.prepare("INSERT INTO employe(codeemploye,cin,nom,prenom)""VALUES(:codeemploye,:cin,:nom,:prenom)");
    query.bindValue(":codeemploye",res);
    query.bindValue(":cin",ress);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    return query.exec();

}

bool employe::supprimer(int i)
{
    QSqlQuery query;
    QString res=QString::number(i);
    query.prepare("DELETE FROM employe where codeemploye=:codeemploye");
    query.bindValue(":codeemploye",res);
    return query.exec();
}

QSqlQueryModel *employe::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,"codeemploye");
    model->setHeaderData(1,Qt::Horizontal,"cin");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(4,Qt::Horizontal,"prenom");
    return model ;
}

bool employe::modifier(int codeemploye,QString nom,int cin,QString prenom)
{
    QSqlQuery query;
    query.prepare("UPDATE employe SET codeemploye=:codeemploye,cin=:cin,nom=:nom,prenom=:prenom WHERE codeemploye=:codeemploye");
    QString res= QString::number(codeemploye);
    QString ress=QString::number(cin);
    query.bindValue(":codeemploye",res);
    query.bindValue(":cin",ress);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    return query.exec();
}

QSqlQueryModel *  employe::chercher(int codeemploye)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(codeemploye);
    model->setQuery("SELECT * FROM employe WHERE (codeemploye LIKE '"+res+"' ) ");
    return  model;

}
