#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMutex>
#include <QMessageBox>
#include <QMimeData>
//#include "copythread.cpp"

void MainWindow::dropEvent(QDropEvent *ev)
{
   ui->listView->setModel(filesModel);
   QList<QUrl> urls = ev->mimeData()->urls();
   foreach(QUrl url, urls)
   {
       QString tmp = url.toString();
       //qDebug()<<tmp;
       tmp = tmp.mid(7, tmp.length() - 6);
       selectedFilesList += tmp;
       for(int i = 0; i < selectedFilesList.size(); i++)
       {
           qDebug()<<selectedFilesList.at(i);
       }
       filesModel->setStringList(selectedFilesList);
   }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *ev)
{
   ev->accept();
}

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    setAcceptDrops(true);
    ui->setupUi(this);
    filesModel = new QStringListModel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::getDestinationFile()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::Directory);
    dialog.exec();
    return dialog.selectedFiles();
}

void MainWindow::setDestination(QStringList dialogFolders)
{
    selectedFolder = dialogFolders.at(0);
    ui->destination->setText(selectedFolder);
}

void MainWindow::getFiles()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    if(dialog.exec())
    {
        selectedFilesList << dialog.selectedFiles();
        filesModel->setStringList(selectedFilesList);
    }
    ui->listView->setModel(filesModel);
}

void MainWindow::deleteFiles()
{
    int i;
    for(i = 0; i < filesModel->stringList().size(); i++)
    {
        QFile::remove(selectedFilesList.at(i));
    }
    int tmp = selectedFilesList.size();
    for(i = 0; i < tmp; i++)
    {
        selectedFilesList.removeAt(0);
    }

    filesModel->setStringList(selectedFilesList);
}

bool MainWindow::checkDestination()
{
    if(ui->destination->text() == "<Destination>")
    {
        QMessageBox msgBox;
        msgBox.setText("Select a destination for operation.");
        msgBox.exec();
        return false;
    }
    return true;
}

//start events
void MainWindow::on_selectFileButton_clicked()
{
    setDestination(getDestinationFile());
}

void MainWindow::on_action_Add_triggered()
{
    if(this->checkDestination() == false)
    {
        return;
    }
    getFiles();
}

void MainWindow::on_actionCop_y_triggered()
{
    if(this->checkDestination() == false)
    {
        return;
    }
    x.selectedFiles = filesModel->stringList();
    x.selectedFolder = selectedFolder;
    x.start();
}

void MainWindow::on_actionC_ut_triggered()
{
    if(this->checkDestination() == false)
    {
        return;
    }
    y.selectedFiles = filesModel->stringList();
    y.selectedFolder = selectedFolder;
    y.start();
    int tmp = selectedFilesList.size();
    int i;
    //lol noob forgot to code delete :P
    for(i = 0; i < tmp; i++)
    {
        //QFile::remove(selectedFilesList.at(0));
        selectedFilesList.removeAt(0);
    }
    filesModel->setStringList(selectedFilesList);
}

void MainWindow::on_action_Delete_triggered()
{
    if(this->checkDestination() == false)
    {
        return;
    }
    deleteFiles();
}


void MainWindow::on_actionRemove_triggered()
{
    filesModel->removeRows(ui->listView->currentIndex().row(), 1);
}
