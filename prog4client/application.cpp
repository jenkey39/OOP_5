#include "application.h"

TApplication::TApplication(int& argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    communicator = new TCommunicator(pars, this);

    interface = new TInterface();
    interface->show();

    connect(communicator,SIGNAL(recieved(QByteArray)),this,
            SLOT(fromCommunicator(QByteArray)));
    connect(interface,SIGNAL(request(QString)),
            this,SLOT(toCommunicator(QString)));

}

void TApplication::fromCommunicator(QByteArray msg)
{
    interface->answer(QString(msg));
}

void TApplication::toCommunicator(QString msg)
{
    communicator->send(QByteArray().append(msg));
}
