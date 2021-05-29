#ifndef DBCONN_H
#define DBCONN_H

#endif // DBCONN_H

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>

class dbConn{
private:
    QString dbPath;
    QSqlDatabase sdb;
public:
    dbConn();
    dbConn(QString path);
    ~dbConn();
    void createTable();
    void addDataToTable(QString path, QDateTime dateTime, QString size);
};


