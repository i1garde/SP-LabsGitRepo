#include "mainwindow.h"
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Аналізатор дискового простору");
    setGeometry(600, 100, 1000, 800);
    setMinimumSize(1000, 800);
    setMaximumSize(1000, 800);

    //DB init
    this->sqliteDb = new dbConn();

    //sqliteDb drivers check
    qDebug() << QSqlDatabase::drivers();

    this->sqliteDb->createTable();

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
    std::string recordPath = "D:\\Code\\Qt\\SP-Lab3\\text.txt"; //Шлях запису
    myFile.open(recordPath);
    if (myFile.is_open())
    {
        std::string recordText = path.toStdString();
        myFile.write(recordText.c_str(), sizeof(char)*recordText.size());
        myFile.close();
    }
    inputField->clear(); //Очистка строки вводу

    QDateTime dateTime = dateTime.currentDateTime();
    QString currentDateTime = dateTime.toString("yyyy-MM-dd HH.mm.ss");
    qDebug() << currentDateTime;

    qDebug() << this->formatSize(dirSize(path));
    //add to the table
    this->sqliteDb->addDataToTable(path, dateTime, this->formatSize(dirSize(path)));
}

qint64 MainWindow::dirSize(QString dirPath){
    qint64 size = 0;
    QDir dir(dirPath);
    //calculate total size of current directories' files
    QDir::Filters fileFilters = QDir::Files|QDir::System|QDir::Hidden;
    for(QString filePath : dir.entryList(fileFilters)) {
        QFileInfo fi(dir, filePath);
        size+= fi.size();
    }
    //add size of child directories recursively
    QDir::Filters dirFilters = QDir::Dirs|QDir::NoDotAndDotDot|QDir::System|QDir::Hidden;
    for(QString childDirPath : dir.entryList(dirFilters))
        size+= dirSize(dirPath + QDir::separator() + childDirPath);
    return size;
}

QString MainWindow::formatSize(qint64 size) {
    QStringList units = {"Bytes", "KB", "MB", "GB", "TB", "PB"};
    int i;
    double outputSize = size;
    for(i=0; i<units.size()-1; i++) {
        if(outputSize<1024) break;
        outputSize= outputSize/1024;
    }
    return QString("%0 %1").arg(outputSize, 0, 'f', 2).arg(units[i]);
}

MainWindow::~MainWindow()
{

}
