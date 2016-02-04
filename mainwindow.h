#include <QString>
#include <QStringListModel>
#include <QMainWindow>
#include <QThread>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>
#include "copythread.h"
#include "cutthread.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    copyThread x;
    cutThread y;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void dropEvent(QDropEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);

private slots:
    void on_selectFileButton_clicked();

    void on_action_Add_triggered();

    void on_actionCop_y_triggered();

    void on_actionC_ut_triggered();

    void on_action_Delete_triggered();

    void on_actionRemove_triggered();

private:
    Ui::MainWindow *ui;
    QString selectedFolder;
    QStringList getDestinationFile();
    QStringListModel *filesModel;
    QStringList selectedFilesList;
    void setDestination(QStringList);
    void getFiles();
    void copyFiles();
    void deleteFiles();
    bool checkDestination();
};

#endif // MAINWINDOW_H
