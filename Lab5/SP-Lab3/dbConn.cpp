#include "dbConn.h"

dbConn::dbConn(){
    //init db name
    this->dbPath = "D:/Code/Qt/SP-Lab3/mydb.db";

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    this->sdb.setDatabaseName(this->dbPath);

    //check db conn
    if (!sdb.open())
        {
            qInfo() << "Can't access db!!!";
            qDebug() << sdb.lastError().text();
            return;
        }
    else
    {
        qInfo() << "Db connected.";
    }
}

dbConn::dbConn(QString path){
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    this->sdb.setDatabaseName(path);

    //check db conn
    if (!sdb.open())
        {
            qInfo() << "Can't access db!!!";
            qDebug() << sdb.lastError().text();
            return;
        }
    else
    {
        qInfo() << "Db connected.";
    }
}

void dbConn::createTable(){
    QSqlQuery query;
    QString qstr = "CREATE TABLE IF NOT EXISTS FILE_TABLE ("
     "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
     "PATH VARCHAR(255), "
     "DATETIME VARCHAR(255), "
     "SIZE VARCHAR(255) "
     ");";
    QString output;
    if(query.exec(qstr))
    {
        output = "Table created!\n";
    }
    qInfo() << output;
    qInfo() << "output";
}

void dbConn::addDataToTable(QString path, QDateTime dateTime, QString size){
    QString stringDate = dateTime.toString();//convert DateTime to string

    QSqlQuery query;
    query.prepare("INSERT INTO FILE_TABLE (PATH, DATETIME, SIZE) VALUES (:PATH, :DATETIME, :SIZE)");
    query.bindValue(":PATH", path);
    query.bindValue(":DATETIME", stringDate);
    query.bindValue(":SIZE", size);
    QString output;
    if(query.exec())
    {
        output = "Added values to the table!\n";
    }
    qInfo() << output;
    qInfo() << "output";
}

dbConn::~dbConn(){
    //Close db conn
    this->sdb.close();
}
