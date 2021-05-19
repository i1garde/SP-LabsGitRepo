#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Аналізатор дискового простору");
    setGeometry(600, 100, 1000, 800);
    setMinimumSize(1000, 800);
    setMaximumSize(1000, 800);

    model = new QFileSystemModel(this);
    model->setReadOnly(false);

    treeField = new QTreeView(this);
    treeField->setGeometry(10, 10, 980, 740);
    treeField->setModel(model);
    treeField->hideColumn(2);
    treeField->hideColumn(3);

    inputField = new QLineEdit(this);
    inputField->setGeometry(10, 760, 480, 30);
    okButton = new QPushButton(this);
    okButton->setGeometry(500, 760, 55, 30);
    okButton->setText("Browse");
    connect(okButton, SIGNAL(released()), this, SLOT(handleButton()));
}

void MainWindow::handleButton()
{
    QString path;
    path = inputField->text();
    //Перехід до вказаної папки
    QModelIndex rootIndex = model->setRootPath(path);
    treeField->setModel(model);
    treeField->setRootIndex(rootIndex);
    //Запис у файл
    std::ofstream myFile;
    std::string recordPath = "D:\\Prog Proj\\Qt\\SP-Lab3\\text.txt"; //Шлях запису
    myFile.open(recordPath);
    if (myFile.is_open())
    {
        std::string recordText = path.toStdString();
        myFile.write(recordText.c_str(), sizeof(char)*recordText.size());
        myFile.close();
    }
    inputField->clear(); //Очистка строки вводу
}

MainWindow::~MainWindow()
{

}
