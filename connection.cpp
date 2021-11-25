#include "connection.h"
#include <QSqlError>
Connection::Connection(){
}
bool Connection::ouvrirconnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("imen");//inserer nom de l'utilisateur
    db.setPassword("Imene12345");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;

    else throw QString ("Erreur Paramétres"+db.lastError().text());
    return  test;
}
void Connection::fermerconnexion()
{QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.close();}
QSqlDatabase Connection::get_db()
{
    return db;
}
