#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
//#include <QFileDialog>
#include <QMessageBox>
#include <QMetaType>
#include <QSet>
#include <QStandardPaths>
#include <QTcpServer>
#include <QTcpSocket>


#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QVector>
#include <QHash>
#include <QPushButton>
#include <QMessageBox>
#include <random>
#include <QRandomGenerator64>
#include <mutex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int e = 0;
    int ed = 0;
    int f = 2;
    int ff = 1;
    int fff = 3;
    int codet = 10;
    int codet2 =20;
    int testc = 12;
    int testc2 = 24;
    int x = 0;
    int y = 0;


    bool dual = true;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer=new QTimer();
    QTime time;
    QTimer *tiempor=new QTimer();
    QTime tiempo;
    QVector<QString> tarjetas{"tarjeta01", "tarjeta02", "tarjeta03", "tarjeta04",
                              "tarjeta05", "tarjeta06", "tarjeta07", "tarjeta08",
                              "tarjeta09", "tarjeta10", "tarjeta11", "tarjeta12",
                              "tarjeta13", "tarjeta14", "tarjeta15", "tarjeta16",
                              "tarjeta17", "tarjeta18", "tarjeta19", "tarjeta20",
                              "tarjeta21", "tarjeta22", "tarjeta23", "tarjeta24",
                              "tarjeta25", "tarjeta26", "tarjeta27", "tarjeta28",
                              "tarjeta29", "tarjeta30", "tarjeta31", "tarjeta32",
                              "tarjeta33", "tarjeta34", "tarjeta35", "tarjeta36"};





    QHash<QString, QString> reparto;
    int puntaje=0;
    int puntaje2=0;
    bool jugadaIniciada;
    QPushButton* tarjetaAnterior;
    QPushButton* tarjetaActual;
    int parejasRestantes;

    QMessageBox msgBox;

signals:
    void newMessage(QString);
private slots:
    void newConnection();
    void appendToSocketList(QTcpSocket* socket);
    void readSocket();
    void discardSocket();
    void displayMessage(const QString& str);
    void sendMessage(QTcpSocket* socket);
    void on_pushButton_sendMessage_clicked();
    void refreshComboBox();


    void updateTimer();
    void discoveredCard();
    void mixC(QVector<QString> &tarjetas);
    void distribute(QVector<QString> &tarjetas, QHash<QString, QString> &reparto);
    void definePartialResult();
    void resetCards();
    void showImage();
    void defineFinalResult();
    void updateStatus();
    void initializeGame();

private:
    Ui::MainWindow *ui;

    QTcpServer* m_server;
    QSet<QTcpSocket*> connection_set;
};

#endif // MAINWINDOW_H
