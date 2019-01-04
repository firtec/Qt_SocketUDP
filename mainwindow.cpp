#include <stdint.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString string("192.168.1.103");
    QHostAddress address(QHostAddress::Any);
    address.setAddress(string);
    socket = new QUdpSocket(this);
    socket->bind(address , 30000);
    statusBar()->showMessage(tr("Desconectado!!"));
    connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()),Qt::QueuedConnection);

    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
 {
			QHostAddress sender;
			uint16_t port;
            QByteArray datagram;
         datagram.resize(socket->pendingDatagramSize());
         socket->readDatagram(datagram.data(),datagram.size(),&sender,&port);

    if ( datagram.size() > 0 ){
        ui->IP->setText(sender.toString());
        ui->l1->setText(datagram);
        statusBar()->showMessage(tr(" Conectado en puerto %1").arg(port));

    }
}
