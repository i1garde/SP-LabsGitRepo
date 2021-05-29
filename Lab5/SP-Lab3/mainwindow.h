#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QToolBar>
#include <QDialog>
#include <QFileSystemModel>
#include <fstream>
#include <QSql>
#include <QtDebug>
#include <QMessageBox>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QSqlDatabase>
#include <QDateTime>
#include <QtWidgets>
#include "dbConn.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    dbConn* sqliteDb;
    qint64 dirSize(QString dirPath);
    QString formatSize(qint64 size);
    ~MainWindow();
private slots:
    void handleButton();

private:
    QLineEdit *inputField;
    QTreeView *treeField;
    QPushButton *okButton;
    QFileSystemModel *model;
};
#endif // MAINWINDOW_H
