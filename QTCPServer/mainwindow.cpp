#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server = new QTcpServer();


    //Conecta timer al slot que maneja el timer
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));

    //Conecta cada boton al mismo slot, que averiguará qué botón se presionó y mostrará su archivo de imagen asociado en consecuencia
    connect(ui->tarjeta01, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta02, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta03, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta04, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta05, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta06, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta07, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta08, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta09, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta10, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta11, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta12, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta13, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta14, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta15, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta16, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta17, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta18, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta19, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta20, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta21, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta22, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta23, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta24, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta25, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta26, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta27, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta28, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta29, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta30, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta31, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta32, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta33, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta34, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta35, SIGNAL(clicked()), this, SLOT(discoveredCard()));
    connect(ui->tarjeta36, SIGNAL(clicked()), this, SLOT(discoveredCard()));

    initializeGame();

    //Establece el Address al cual se conectan el servidor y el cliente
    if(m_server->listen(QHostAddress::Any, 8080))
    {
       connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
       connect(m_server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
       ui->statusbar->showMessage("Server is listening...");
    }
    else
    {
        QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(m_server->errorString()));
        exit(EXIT_FAILURE);
    }
}

MainWindow::~MainWindow()
{
    foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }

    m_server->close();
    m_server->deleteLater();

    delete ui;
}

//Establece una nueva coneccion de un un nuevo cliente en el server
void MainWindow::newConnection()
{
    while (m_server->hasPendingConnections())
        appendToSocketList(m_server->nextPendingConnection());
}

//Adjunta el nuevo socket conectado
void MainWindow::appendToSocketList(QTcpSocket* socket)
{
    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
    ui->comboBox_receiver->addItem(QString::number(socket->socketDescriptor()));
    displayMessage(QString("INFO :: Client with sockd:%1 has just entered the room").arg(socket->socketDescriptor()));
}


//Lee y interpreta el input del mensaje que se envio basado en sockets
void MainWindow::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> buffer;

    QString header = buffer.mid(0,128);
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);

    QString tar1 =  "23 :: aa";
    QString tar2 =  "23 :: ab";
    QString tar3 =  "23 :: ac";
    QString tar4 =  "23 :: ad";
    QString tar5 =  "23 :: ae";
    QString tar6 =  "23 :: af";
    QString tar7 =  "23 :: ba";
    QString tar8 =  "23 :: bb";
    QString tar9 =  "23 :: bc";
    QString tar10 = "23 :: bd";
    QString tar11 = "23 :: be";
    QString tar12 = "23 :: bf";
    QString tar13=  "23 :: ca";
    QString tar14=  "23 :: cb";
    QString tar15=  "23 :: cc";
    QString tar16=  "23 :: cd";
    QString tar17 = "23 :: ce";
    QString tar18=  "23 :: cf";
    QString tar19=  "23 :: da";
    QString tar20 = "23 :: db";
    QString tar21=  "23 :: dc";
    QString tar22=  "23 :: dd";
    QString tar23=  "23 :: de";
    QString tar24=  "23 :: df";
    QString tar25=  "23 :: ea";
    QString tar26 = "23 :: eb";
    QString tar27 = "23 :: ec";
    QString tar28 = "23 :: ed";
    QString tar29=  "23 :: ee";
    QString tar30=  "23 :: ef";
    QString tar31=  "23 :: fa";
    QString tar32=  "23 :: fb";
    QString tar33 = "23 :: fc";
    QString tar34 = "23 :: fd";
    QString tar35 = "23 :: fe";
    QString tar36 = "23 :: ff";

    QString dtar1 =  "24 :: aa";
    QString dtar2 =  "24 :: ab";
    QString dtar3 =  "24 :: ac";
    QString dtar4 =  "24 :: ad";
    QString dtar5 =  "24 :: ae";
    QString dtar6 =  "24 :: af";
    QString dtar7 =  "24 :: ba";
    QString dtar8 =  "24 :: bb";
    QString dtar9 =  "24 :: bc";
    QString dtar10 = "24 :: bd";
    QString dtar11 = "24 :: be";
    QString dtar12 = "24 :: bf";
    QString dtar13=  "24 :: ca";
    QString dtar14=  "24 :: cb";
    QString dtar15=  "24 :: cc";
    QString dtar16=  "24 :: cd";
    QString dtar17 = "24 :: ce";
    QString dtar18=  "24 :: cf";
    QString dtar19=  "24 :: da";
    QString dtar20 = "24 :: db";
    QString dtar21=  "24 :: dc";
    QString dtar22=  "24 :: dd";
    QString dtar23=  "24 :: de";
    QString dtar24=  "24 :: df";
    QString dtar25=  "24 :: ea";
    QString dtar26 = "24 :: eb";
    QString dtar27 = "24 :: ec";
    QString dtar28 = "24 :: ed";
    QString dtar29=  "24 :: ee";
    QString dtar30=  "24 :: ef";
    QString dtar31=  "24 :: fa";
    QString dtar32=  "24 :: fb";
    QString dtar33 = "24 :: fc";
    QString dtar34 = "24 :: fd";
    QString dtar35 = "24 :: fe";
    QString dtar36 = "24 :: ff";

    std::once_flag onceFlag;

    if (dual == true){
        std::uniform_int_distribution<int> distribution(1,2);
        int value = distribution(*QRandomGenerator::global());
        qDebug()<< value;
        if (value == 1){
            e+=2;
            codet+=2;
            emit newMessage("Empieza en cliente2(24) :)");
        }else{
            ed+=2;
            codet2+=4;
            emit newMessage("Empieza en cliente1(23) :)");
        }
        dual = false;
    }

    if(fileType == "message"){
        //Establece el nombre del socket
        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
        qDebug() << message;

        emit newMessage(message);

        if (e < f){
            //Compara el mensaje con la trjeta y la abre, asigna valores necesario para el funcionamiento del juego
            if (QString::compare(tar1, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta01->clicked(true);
            }
            if (QString::compare(tar2, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta02->clicked(true);
            }
            if (QString::compare(tar3, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta03->clicked(true);
            }
            if (QString::compare(tar4, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta04->clicked(true);
            }
            if (QString::compare(tar5, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta05->clicked(true);
            }
            if (QString::compare(tar6, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta06->clicked(true);
            }
            if (QString::compare(tar7, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta07->clicked(true);
            }
            if (QString::compare(tar8, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta08->clicked(true);
            }
            if (QString::compare(tar9, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta09->clicked(true);
            }
            if (QString::compare(tar10, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta10->clicked(true);
            }
            if (QString::compare(tar11, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta11->clicked(true);
            }
            if (QString::compare(tar12, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta12->clicked(true);
            }
            if (QString::compare(tar13, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta13->clicked(true);
            }
            if (QString::compare(tar14, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta14->clicked(true);
            }
            if (QString::compare(tar15, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta15->clicked(true);
            }
            if (QString::compare(tar16, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta16->clicked(true);
            }
            if (QString::compare(tar17, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta17->clicked(true);
            }
            if (QString::compare(tar18, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta18->clicked(true);
            }
            if (QString::compare(tar19, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta19->clicked(true);
            }
            if (QString::compare(tar20, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta20->clicked(true);
            }
            if (QString::compare(tar21, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta21->clicked(true);
            }
            if (QString::compare(tar22, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta22->clicked(true);
            }
            if (QString::compare(tar23, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta23->clicked(true);
            }
            if (QString::compare(tar24, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta24->clicked(true);
            }
            if (QString::compare(tar25, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta25->clicked(true);
            }
            if (QString::compare(tar26, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta26->clicked(true);
            }
            if (QString::compare(tar27, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e +=1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta27->clicked(true);
            }
            if (QString::compare(tar28, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta28->clicked(true);
            }
            if (QString::compare(tar29, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta29->clicked(true);
            }
            if (QString::compare(tar30, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta30->clicked(true);
            }
            if (QString::compare(tar31, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta31->clicked(true);
            }
            if (QString::compare(tar32, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta32->clicked(true);
            }
            if (QString::compare(tar33, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta33->clicked(true);
            }
            if (QString::compare(tar34, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta34->clicked(true);
            }
            if (QString::compare(tar35, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta35->clicked(true);
            }
            if (QString::compare(tar36, message,Qt::CaseInsensitive) == 0){
                emit newMessage("<3");
                e += 1;
                ed-=1;
                codet +=1;
                codet2-=2;
                ui->tarjeta36->clicked(true);
            }
        }

        if(ed < f){
            if (QString::compare(dtar1, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta01->clicked(true);
            }
            if (QString::compare(dtar2, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta02->clicked(true);
            }
            if (QString::compare(dtar3, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta03->clicked(true);
            }
            if (QString::compare(dtar4, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta04->clicked(true);
            }
            if (QString::compare(dtar5, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta05->clicked(true);
            }
            if (QString::compare(dtar6, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta06->clicked(true);
            }
            if (QString::compare(dtar7, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta07->clicked(true);
            }
            if (QString::compare(dtar8, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta08->clicked(true);
            }
            if (QString::compare(dtar9, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta09->clicked(true);
            }
            if (QString::compare(dtar10, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta10->clicked(true);
            }
            if (QString::compare(dtar11, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta11->clicked(true);
            }
            if (QString::compare(dtar12, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta12->clicked(true);
            }
            if (QString::compare(dtar13, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta13->clicked(true);
            }
            if (QString::compare(dtar14, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta14->clicked(true);
            }
            if (QString::compare(dtar15, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta15->clicked(true);
            }
            if (QString::compare(dtar16, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta16->clicked(true);
            }
            if (QString::compare(dtar17, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta17->clicked(true);
            }
            if (QString::compare(dtar18, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta18->clicked(true);
            }
            if (QString::compare(dtar19, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta19->clicked(true);
            }
            if (QString::compare(dtar20, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta20->clicked(true);
            }
            if (QString::compare(dtar21, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta21->clicked(true);
            }
            if (QString::compare(dtar22, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta22->clicked(true);
            }
            if (QString::compare(dtar23, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta23->clicked(true);
            }
            if (QString::compare(dtar24, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta24->clicked(true);
            }
            if (QString::compare(dtar25, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta25->clicked(true);
            }
            if (QString::compare(dtar26, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta26->clicked(true);
            }
            if (QString::compare(dtar27, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta27->clicked(true);
            }
            if (QString::compare(dtar28, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta28->clicked(true);
            }
            if (QString::compare(dtar29, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta29->clicked(true);
            }
            if (QString::compare(dtar30, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta30->clicked(true);
            }
            if (QString::compare(dtar31, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta31->clicked(true);
            }
            if (QString::compare(dtar32, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta32->clicked(true);
            }
            if (QString::compare(dtar33, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta33->clicked(true);
            }
            if (QString::compare(dtar34, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta34->clicked(true);
            }
            if (QString::compare(dtar35, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta35->clicked(true);
            }
            if (QString::compare(dtar36, message,Qt::CaseInsensitive) == 0){
                emit newMessage(":3");
                ed += 1;
                e -= 1;
                codet -=1;
                codet2+=2;
                ui->tarjeta36->clicked(true);
            }
        }
    }
}

//Descarta el socket cuando el ciente es cerrado o expulsado
void MainWindow::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = connection_set.find(socket);
    if (it != connection_set.end()){
        displayMessage(QString("INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        connection_set.remove(*it);
    }
    refreshComboBox();

    socket->deleteLater();
}

//Envia el mensaje al precionar el boton
void MainWindow::on_pushButton_sendMessage_clicked()
{
    QString receiver = ui->comboBox_receiver->currentText();

    if(receiver=="Broadcast")
    {
        foreach (QTcpSocket* socket,connection_set)
        {
            sendMessage(socket);
        }
    }
    else
    {
        foreach (QTcpSocket* socket,connection_set)
        {
            if(socket->socketDescriptor() == receiver.toLongLong())
            {
                sendMessage(socket);
                break;
            }
        }
    }
    ui->lineEdit_message->clear();
}

//Envia un mensaje del server al cliente
//Esta funcion no es utlisada
void MainWindow::sendMessage(QTcpSocket* socket)
{
    if(socket)
    {
        if(socket->isOpen())
        {
            QString str = ui->lineEdit_message->text();

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray header;
            header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
            header.resize(128);

            QByteArray byteArray = str.toUtf8();
            byteArray.prepend(header);

            socketStream.setVersion(QDataStream::Qt_5_15);
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this,"QTCPServer","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPServer","Not connected");
}

//Refresca la caja de mensajes, para que los mensajes se muestren en la pantalla
void MainWindow::refreshComboBox(){
    ui->comboBox_receiver->clear();
    ui->comboBox_receiver->addItem("Broadcast");
    foreach(QTcpSocket* socket, connection_set)
        ui->comboBox_receiver->addItem(QString::number(socket->socketDescriptor()));
}

//Muestra los mensajes en la pantalla
void MainWindow::displayMessage(const QString& str)
{
    ui->textBrowser_receivedMessages->append(str);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Muestra las cartas descuviertas
void MainWindow::discoveredCard(){
    //obtiene la caja que fue presionada
    tarjetaActual=qobject_cast<QPushButton*>(sender());

    //Obtiene la imagen linkiada a la caja y muesta la imagen
    showImage();

    //Desabilita la caja precionada para que no pueda volverse a precionar
    tarjetaActual->setEnabled(false);

    //Establce un funcionamiento dependiendo de si es la segunda o primera tarjeta abierta
    if (!jugadaIniciada){
        tarjetaAnterior=tarjetaActual;
        jugadaIniciada=true;
    }
    else{
        //cambiar la puntuación y la muestra
        definePartialResult();

        //reinicia el turno
        jugadaIniciada=false;
    }
}

//Funcion que muestra la imagen
void MainWindow::showImage(){
    QString nombre_tarjeta=tarjetaActual->objectName();
    QString img=reparto[nombre_tarjeta];
    tarjetaActual->setStyleSheet("#" + nombre_tarjeta + "{ background-image: url(://" + img + ") }");
}


//Resetea las cartas al estado original
void MainWindow::resetCards(){
    //debuelve las terjetas al estado original
    tarjetaAnterior->setStyleSheet("#" + tarjetaAnterior->objectName() + "{ }");
    tarjetaActual->setStyleSheet("#" + tarjetaActual->objectName() + "{ }");

    //Vuelve a abilitar las tarjetas
    tarjetaActual->setEnabled(true);
    tarjetaAnterior->setEnabled(true);

    //Re avilita las tarjetas
    ui->frame->setEnabled(true);
}

//Define el resultado final
void MainWindow::defineFinalResult(){
    msgBox.setWindowTitle("Juego terminado");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setEscapeButton(QMessageBox::No);

    if (parejasRestantes==0){
        timer->stop();
        if(puntaje >= 180){
            msgBox.setText("¡Ganaste Cliente1! Puntaje final: " + QString::number(puntaje) + "\nVolver a jugar?");
        }else if (puntaje2 >= 180) {
            msgBox.setText("¡Ganaste Cliente2! Puntaje final: " + QString::number(puntaje2) + "\nVolver a jugar?");
        }

        if (QMessageBox::Yes == msgBox.exec()){
            initializeGame();
        }
        else{
            QCoreApplication::quit();
        }
    }
    else{
        if (time.toString()=="00:00:00"){
            timer->stop();
            ui->frame->setEnabled(false);
            msgBox.setText("Perdiste ;( \n¿Volver a jugar?");
            if (QMessageBox::Yes == msgBox.exec()){
                initializeGame();
            }
            else{
                QCoreApplication::quit();
            }
        }
    }
}



//Define el resultado final de la partida y de los maches de cada carta (por turno) y agrega las funciones de power ups
void MainWindow::definePartialResult(){
    //comprobar si hay una coincidencia
    if(testc == codet){
        if (reparto[tarjetaActual->objectName()]==reparto[tarjetaAnterior->objectName()]){
            if (puntaje<0){
                puntaje = 0;
            }
            codet-=2;
            codet2+=4;
            puntaje+=5;

            //Borra las tarjetas que si tienen pareja de la memoria
            tarjetaActual->deleteLater();
            tarjetaAnterior->deleteLater();
            ui->lblPuntaje->setText(QString::number(puntaje));
            ui->lblPuntaje2->setText(QString::number(puntaje2));
            parejasRestantes--;

            //Power up de volver a jugar
            e-=2;
            ed+=2;

            //Crea el tercio de las tarjetas de memoria y la revuelve de manera aleatoria si hay pareja
            mixC(tarjetas);

            //Power up por ganar 3 rondas
            if(puntaje == 15){
                puntaje += 180;
                parejasRestantes == 0;
                defineFinalResult();
            }

            //Si hay pareja se acegura de que queden cartas
            defineFinalResult();


        }
        else{
            puntaje-=5;
            //Power up de perdida por 3 rondas
            if(puntaje <= -15){
                timer->stop();
                ui->frame->setEnabled(false);
                msgBox.setText("Perdiste ;( \n¿Volver a jugar?");
                if (QMessageBox::Yes == msgBox.exec()){
                    initializeGame();
                }
                else{
                    QCoreApplication::quit();
                }
            }
            ui->lblPuntaje->setText(QString::number(puntaje));
            ui->lblPuntaje2->setText(QString::number(puntaje2));
            ui->frame->setEnabled(false);

            //Da un segundo para que el jugador se aprenda la tarjeta sacada
            QTimer::singleShot(1000, this, SLOT(resetCards()));
        }
    }

    //comprobar si hay una coincidencia
    if(testc2 == codet2){
        if (reparto[tarjetaActual->objectName()]==reparto[tarjetaAnterior->objectName()]){
            if (puntaje<0){
                puntaje = 0;
            }
            puntaje2+=5;
            codet+=2;
            codet2-=4;

            //Borra las tarjetas que si tienen pareja de la memoria
            tarjetaActual->deleteLater();
            tarjetaAnterior->deleteLater();
            ui->lblPuntaje->setText(QString::number(puntaje));
            ui->lblPuntaje2->setText(QString::number(puntaje2));
            parejasRestantes--;

            //Power up de volver a jugar
            e+=2;
            ed-=2;

            //Crea el tercio de las tarjetas de memoria y la revuelve de manera aleatoria si hay pareja
            mixC(tarjetas);

            //Power up por ganar 3 rondas
            if(puntaje2 == 15){
                puntaje2 += 180;
                parejasRestantes == 0;
                defineFinalResult();
            }

           //Si hay pareja se acegura de que queden cartas
            defineFinalResult();
        }

        else{
            puntaje2-=5;
            //Power up de perdida por 3 rondas
            if(puntaje2 <= -15){
                timer->stop();
                ui->frame->setEnabled(false);
                msgBox.setText("Perdiste ;( \n¿Volver a jugar?");
                if (QMessageBox::Yes == msgBox.exec()){
                    initializeGame();
                }
                else{
                    QCoreApplication::quit();
                }
            }
            ui->lblPuntaje->setText(QString::number(puntaje));
            ui->lblPuntaje2->setText(QString::number(puntaje2));
            ui->frame->setEnabled(false);

            //Da un segundo para que el jugador se aprenda la tarjeta sacada
            QTimer::singleShot(1000, this, SLOT(resetCards()));
        }
    }
}

void MainWindow::initializeGame(){
    //Empiesa el turno
    jugadaIniciada=false;

    //setea el puntaje
    puntaje=0;
    puntaje2=0;
    ui->lblPuntaje->setText(QString::number(puntaje));
    ui->lblPuntaje2->setText(QString::number(puntaje2));

    //setea la cantidad de maches
    parejasRestantes=6;

    //Setea el temporisador
    time.setHMS(0,5,0);

    //Inicia el temporisador
    ui->cronometro->setText(time.toString("m:ss"));

    // Setea el temporisador al tiempo signafo
    timer->start(1000);
    tiempor->start(100);

    //Crea el tercio de las tarjetas de memoria y la revuelve de manera aleatoria si hay pareja
    mixC(tarjetas);

    //Asigna el nombre de memoria de cada tarjeta
    distribute(tarjetas, reparto);

    //Abilita el frame de las tarjetas
    ui->frame->setEnabled(true);

    QList<QPushButton *> botones =  ui->centralwidget->findChildren<QPushButton*>();
    foreach (QPushButton* b, botones) {
        b->setEnabled(true);
        b->setStyleSheet("#" + b->objectName() + "{ }");
    }
}

//Acualisa el temporisador
void MainWindow::updateTimer(){
    time=time.addSecs(-1);
    ui->cronometro->setText(time.toString("m:ss"));
}

//Actualisa el status
void MainWindow::updateStatus(){
    updateTimer();
    defineFinalResult();
}

//Crea el tercio de las tarjetas de memoria y la revuelve de manera aleatoria si hay pareja
void MainWindow::mixC(QVector<QString> &tarjetas){
    for (int n=1; n<=18/3; n++){
        std::shuffle(tarjetas.begin(),tarjetas.end(),std::random_device());
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (tarjetas.begin(), tarjetas.end(), std::default_random_engine(seed));
    }
}

//Revuelve las imagenes de las terjetas para el juego
void MainWindow::distribute(QVector<QString> &tarjetas, QHash<QString, QString> &reparto){
    auto iterador=tarjetas.begin();
    for (int i=1; i<=18; i++){
        QString file_name="0"+QString::number(i)+".png";
        reparto[(*iterador)]=file_name;
        iterador++;
        reparto[(*iterador)]=file_name;
        iterador++;
    }
}

