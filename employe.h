#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include <QVariant>
#include <QComboBox>

class employe
{
public:
    employe();
    employe(int,int,QString,QString);
    int get_codeemploye(){return codeemploye;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    int get_cin(){return cin;}

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    bool modifier(int,QString,int,QString);
    QSqlQueryModel * chercher(int);


private:
    int codeemploye;
    QString nom;
      QString prenom;
    int cin;
};

#endif // employe_H

