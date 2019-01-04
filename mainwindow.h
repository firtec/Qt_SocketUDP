#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   

private:
    Ui::MainWindow *ui;
    QUdpSocket *socket = nullptr;
    
private slots:
    void processPendingDatagrams();

};

#endif // MAINWINDOW_H
