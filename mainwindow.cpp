#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableAvion->setModel(tmpavion.afficher2());

    model = new QSqlTableModel;
    model->select();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    close();

}

void MainWindow::on_pushButton_3_clicked()
{
    close();

}


void MainWindow::afficher2()
{

    Connection c;
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery(c.get_db());
    qry->prepare("SELECT* from avionn");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableAvion->setModel(modal);
}


void MainWindow::on_ajouter_avion_clicked()
{
    bool test;
    int codeavion = ui->lineEdit_code_avion->text().toInt();
    int nbplace = ui->lineEdit_nb->text().toInt();
    QString depart=ui->lineEdit_depart->text();
    QString arrivee=ui->lineEdit_arrivee->text();
    QString datee=ui->lineEdit_date->text();
    QString duree=ui->lineEdit_duree->text();
    avion i(codeavion,depart,nbplace,arrivee,datee,duree);

    if(!(ui->lineEdit_code_avion->text().isEmpty() || ui->lineEdit_depart->text().isEmpty() || ui->lineEdit_arrivee->text().isEmpty()||ui->lineEdit_duree->text().isEmpty() ))

    { test=i.ajouter2();}

    if(test)
    {

        ui->tableAvion->setModel(tmpavion.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un avion"),
                                 QObject::tr("avion ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un avion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_2_clicked()
{
    int codeavion = ui->lineEdit_code_avionmodif->text().toInt();
    int nbplace=ui->lineEdit_nbmodif->text().toInt();//comboBox2
    QString depart=ui->lineEdit_nouv_depart->text();
    QString arrivee=ui->lineEdit_arriveeavion->text();
    QString datee=ui->lineEdit_nvdate->text();
    QString duree=ui->lineEdit_nvduree->text();


    avion i(codeavion,depart,nbplace,arrivee,datee,duree);

    bool test=i.modifier2(codeavion,depart,nbplace,arrivee,datee,duree);
    if(test)
    {
        ui->tableAvion->setModel(tmpavion.afficher2());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un avion !"),
                                 QObject::tr(" avion modifiée ! \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else {

        QMessageBox::critical(nullptr, QObject::tr("Modifier un avion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_2_clicked()
{
        int codeavion = ui->lineEdit_code_avionsupp->text().toInt();
        bool test = tmpavion.supprimer2(codeavion);
        if (test)
        {
            ui->tableAvion->setModel(tmpavion.afficher2());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un avion !"),
                                     QObject::tr(" avion suprimé ! \n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Suppimer un avion"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

void MainWindow::on_pushButton_trie_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableAvion->setModel(tmpavion.trier_codeavion());
        QMessageBox::information(nullptr, QObject::tr("Trier avion par codeavion"),
                                 QObject::tr("avion trié.\n"
                                             "Voulez-vous enregistrer les modifications ?"),
                                 QMessageBox::Save
                                     | QMessageBox::Cancel,
                                 QMessageBox::Save);
    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("avion par codeavion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}





void MainWindow::on_pushButton_stat_clicked()
{
    secDialog = new SecDialog(this);
    secDialog ->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    login login;
    login.setModal(true);
    login.exec();


}



void MainWindow::on_pushButton_imprimer_10_clicked()
{
    avion tmpavione;
    tmpavion.CREATION_PDF();
}


void MainWindow::on_pushButton_4_clicked()
{
    int codeplat = ui->lineEdit_chercher3->text().toInt();
    ui->tableAvion->setModel(tmpavion.chercher(codeplat));
}

void MainWindow::on_checkBox_2_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableAvion->setModel(tmpavion.trier_nbplace());

    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("Trier par nombre de place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."));
}
   }


void MainWindow::on_checkBox_3_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableAvion->setModel(tmpavion.trier_duree());

    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("Trier par durée"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."));
}
     }



void MainWindow::on_checkBox_clicked()
{
    bool test = true;
    if (test)
    {
        ui->tableAvion->setModel(tmpavion.trier_codeavion());
        QMessageBox::information(nullptr, QObject::tr("Trier avion par codeavion"),
                                 QObject::tr("avion trié.\n"
                                             "Voulez-vous enregistrer les modifications ?"),
                                 QMessageBox::Save
                                     | QMessageBox::Cancel,
                                 QMessageBox::Save);
    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("avion par codeavion"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
