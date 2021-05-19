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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

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
