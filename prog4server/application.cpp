#include "application.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));

    p.change_size(2);
    p.change_an(2);
    p.change_root(1, 0);
    p.change_root(3, 1);
}

void TApplication::recieve(QByteArray message)
{
    QString answer, s;
    TComplex an, x, v, root;
    int size, root_pos;
    int pos = message.indexOf(separator);
    int t = message.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            message = message.right(message.length()-pos-1);
            message>>x;
            v = p.count_value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.set_print_mode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case PRINT_CANONIC_REQUEST:
            p.set_print_mode(EPrintModeCanonic);
            s << p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case CHANGE_AN_REQUEST:
            message = message.right(message.length()-pos-1);
            message >> an;
            p.change_an(an);
            answer << QString().setNum(CHANGE_LAST_ANSWER);
            break;
        case CHANGE_POL_AN_REQUEST:
            message = message.right(message.length()-pos-1);
            message >> an;
            p.change_an(an);
            answer << QString().setNum(CHANGE_POL_ANSWER);
            break;
        case CHANGE_SIZE_REQUEST:
            message = message.right(message.length()-pos-1);
            pos = message.indexOf(separator);
            size = message.left(pos).toInt();
            p.change_size(size);
            answer << QString().setNum(CHANGE_LAST_ANSWER);
            break;
        case CHANGE_ROOT_REQUEST:
            message = message.right(message.length()-pos-1);
            message >> root;
            pos = message.indexOf(separator);
            root_pos = message.left(pos).toInt();
            p.change_root(root, root_pos);
            answer << QString().setNum(CHANGE_LAST_ANSWER);
            break;
        case CHANGE_POL_ROOTS_REQUEST:
            message = message.right(message.length()-pos-1);
            message >> root;
            pos = message.indexOf(separator);
            root_pos = message.left(pos).toInt();
            p.change_root(root, root_pos);
            if (root_pos == p.get_size() - 1)
                answer << QString().setNum(CHANGE_LAST_ANSWER);
            else
                answer << QString().setNum(CHANGE_POL_ANSWER);
            break;
        default: return;
    }
    comm->send(QByteArray().append(answer));
}
