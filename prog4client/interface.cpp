#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Interface");
    setFixedSize(1000,500);

    coefficientLabel = new QLabel("a = ", this);
    coefficientLabel->setGeometry(100, 30, 20, 20);
    coefficientRealPart = new QLineEdit(this);
    coefficientRealPart->setGeometry(120, 30, 30, 20);
    imaginaryDelimiter = new QLabel("+ i ", this);
    imaginaryDelimiter->setGeometry(150, 30, 20, 20);
    coefficientImaginaryPart = new QLineEdit(this);
    coefficientImaginaryPart->setGeometry(170, 30, 30, 20);
    coefficientLabel->hide();
    coefficientRealPart->hide();
    imaginaryDelimiter->hide();
    coefficientImaginaryPart->hide();

     enterModeLabel = new QLabel("Введите an", this);
     enterModeLabel->setGeometry(100, 10, 150, 20);
     enterModeLabel->hide();

    constantTermLabel = new QLabel("a = ", this);
    constantTermLabel->setGeometry(100, 30, 20, 20);
    an_re = new QLineEdit(this);
    an_re->setGeometry(120, 30, 30, 20);
    an_delimiter = new QLabel("+ i ", this);
    an_delimiter->setGeometry(150, 30, 20, 20);
    an_im = new QLineEdit(this);
    an_im->setGeometry(170, 30, 30, 20);
    constantTermLabel->hide();
    an_re->hide();
    an_delimiter->hide();
    an_im->hide();

    pos_root_name = new QLabel("Индекс:", this);
    pos_root_name->setGeometry(100, 70, 60, 20);
    pos_root_val = new QLineEdit(this);
    pos_root_val->setGeometry(160, 70, 20, 20);
    pos_root_name->hide();
    pos_root_val->hide();

    x_name = new QLabel("x = ", this);
    x_name->setGeometry(100, 30, 20, 20);
    x_re = new QLineEdit(this);
    x_re->setGeometry(120, 30, 30, 20);
    x_delimiter = new QLabel("+ i ", this);
    x_delimiter->setGeometry(150, 30, 20, 20);
    x_im = new QLineEdit(this);
    x_im->setGeometry(170, 30, 30, 20);
    x_name->hide();
    x_re->hide();
    x_delimiter->hide();
    x_im->hide();

    new_size_name = new QLabel("Новый размер - ", this);
    new_size_name->setGeometry(100, 30, 120, 20);
    new_size_value = new QLineEdit(this);
    new_size_value->setGeometry(220, 30, 30, 20);
    new_size_name->hide();
    new_size_value->hide();

    value_btn = new QPushButton("Вычислить значение в x", this);
    value_btn->setGeometry(10, 150, 200, 30);
    change_an_btn = new QPushButton("Изменить an", this);
    change_an_btn->setGeometry(10, 210, 150, 30);
    print_btn = new QPushButton("Вывести полином", this);
    print_btn->setGeometry(10, 270, 150, 30);
    write_btn = new QPushButton("Ввести полином", this);
    write_btn->setGeometry(10, 330, 150, 30);
    change_size_btn = new QPushButton("Изменить размер", this);
    change_size_btn->setGeometry(10, 390, 150, 30);
    change_root_btn = new QPushButton("Изменить корень по индексу", this);
    change_root_btn->setGeometry(10, 450, 188, 30);

    submit_value_btn = new QPushButton("Выполнить", this);
    submit_value_btn->setStyleSheet("background-color: green; color: white;");
    submit_value_btn->setGeometry(200, 150, 150, 30);
    submit_value_btn->hide();
    submit_an_btn = new QPushButton("Выполнить", this);
    submit_an_btn->setStyleSheet("background-color: green; color: white;");
    submit_an_btn->setGeometry(200, 150, 150, 30);
    submit_an_btn->hide();
    submit_print_btn = new QPushButton("Выполнить", this);
    submit_print_btn->setStyleSheet("background-color: green; color: white;");
    submit_print_btn->setGeometry(200, 150, 150, 30);
    submit_print_btn->hide();
    submit_write_btn = new QPushButton("Далее", this);
    submit_write_btn->setGeometry(200, 150, 150, 30);
    submit_write_btn->hide();
    submit_change_size_btn = new QPushButton("Выполнить", this);
    submit_change_size_btn->setStyleSheet("background-color: green; color: white;");
    submit_change_size_btn->setGeometry(200, 150, 150, 30);
    submit_change_size_btn->hide();
    submit_change_root_btn = new QPushButton("Выполнить", this);
    submit_change_root_btn->setStyleSheet("background-color: green; color: white;");
    submit_change_root_btn->setGeometry(200, 150, 150, 30);
    submit_change_root_btn->hide();

    print_mode = new QComboBox(this);
    print_mode->addItem("Форма 1");
    print_mode->addItem("Форма 2");
    print_mode->setGeometry(100, 30, 130, 20);
    print_mode->hide();

    output = new QLabel(this);
    output->setGeometry(350, 350, 600, 50);

    connect(value_btn, SIGNAL(pressed()), this, SLOT(value()));
    connect(change_an_btn, SIGNAL(pressed()), this, SLOT(change_an()));
    connect(print_btn, SIGNAL(pressed()), this, SLOT(print()));
    connect(write_btn, SIGNAL(pressed()), this, SLOT(write()));
    connect(change_size_btn, SIGNAL(pressed()), this, SLOT(change_size()));
    connect(change_root_btn, SIGNAL(pressed()), this, SLOT(change_root()));
    connect(submit_an_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_value_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_print_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_write_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_change_size_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_change_root_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete value_btn;
    delete change_an_btn;
    delete print_btn;
    delete write_btn;
    delete change_size_btn;
    delete change_root_btn;

    delete submit_an_btn;
    delete submit_value_btn;
    delete submit_print_btn;
    delete submit_write_btn;
    delete submit_change_size_btn;
    delete submit_change_root_btn;

    delete print_mode;

    delete coefficientLabel;
    delete imaginaryDelimiter;
    delete coefficientRealPart;
    delete coefficientImaginaryPart;

    delete  enterModeLabel;

    delete x_name;
    delete x_delimiter;
    delete x_re;
    delete x_im;

    delete constantTermLabel;
    delete an_delimiter;
    delete an_re;
    delete an_im;

    delete new_size_name;
    delete new_size_value;

    delete output;
}

void TInterface::value()
{
    output->setText("");
    x_name->show();
    x_re->show();
    x_delimiter->show();
    x_im->show();
    submit_value_btn->show();
}

void TInterface::print()
{
    output->setText("");
    print_mode->show();
    submit_print_btn->show();
}

void TInterface::change_an()
{
    output->setText("");
    constantTermLabel->show();
    an_re->show();
    an_delimiter->show();
    an_im->show();
    submit_an_btn->show();
}

void TInterface::change_size()
{
    output->setText("");
    new_size_name->show();
    new_size_value->show();
    submit_change_size_btn->show();
}

void TInterface::change_root()
{
    output->setText("");
    coefficientLabel->show();
    coefficientRealPart->show();
    imaginaryDelimiter->show();
    coefficientImaginaryPart->show();
    pos_root_name->show();
    pos_root_val->show();
    submit_change_root_btn->show();
}

void TInterface::write()
{
    QString s =  enterModeLabel->text();
    if (s == "Введите an" && coefficientRealPart->text() == "")
    {
        output->setText("");
        submit_write_btn->show();
        coefficientLabel->show();
        coefficientRealPart->show();
        imaginaryDelimiter->show();
        coefficientImaginaryPart->show();
         enterModeLabel->show();
    }
}

void TInterface::formRequest()
{
    QString msg;
    //msg << b_re->text() << b_im->text();
    //msg << c_re->text() << c_im->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == submit_value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << x_re->text() << x_im->text();
    }
    if (btn == submit_print_btn)
    {
        if (print_mode->currentText() == "Форма 1")
            msg << QString().setNum(PRINT_CLASSIC_REQUEST);
        else
            msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }
    if (btn == submit_an_btn)
    {
        msg << QString().setNum(CHANGE_AN_REQUEST);
        msg << an_re->text() << an_im->text();
    }
    if (btn == submit_change_size_btn)
    {
        msg << QString().setNum(CHANGE_SIZE_REQUEST);
        msg << new_size_value->text();
    }
    if (btn == submit_change_root_btn)
    {
        msg << QString().setNum(CHANGE_ROOT_REQUEST);
        msg << coefficientRealPart->text() << coefficientImaginaryPart->text();
        msg << pos_root_val->text();
    }
    if (btn == submit_write_btn)
    {
        QString s =  enterModeLabel->text();
        int i = 0;
        if (s == "Введите an" && coefficientRealPart->text() != "")
        {
            msg << QString().setNum(CHANGE_POL_AN_REQUEST);
            msg << coefficientRealPart->text() << coefficientImaginaryPart->text();
             enterModeLabel->setText("Введите корень 1");
            coefficientRealPart->setText("");
            coefficientImaginaryPart->setText("");
        }
        if (s != "Введите an")
        {
            s.remove(0, 15);
            i = s.toInt();
            msg << QString().setNum(CHANGE_POL_ROOTS_REQUEST);
            msg << coefficientRealPart->text() << coefficientImaginaryPart->text();
            msg << QString().setNum(i-1);
            s = "Введите корень ";
            s += QString().setNum(i+1);
             enterModeLabel->setText(s);
            coefficientRealPart->setText("");
            coefficientImaginaryPart->setText("");
        }
    }
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            x_name->hide();
            x_re->hide();
            x_delimiter->hide();
            x_im->hide();
            submit_value_btn->hide();
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            print_mode->hide();
            submit_print_btn->hide();
            break;
        case CHANGE_POL_ANSWER:
            coefficientRealPart->setText("");
            coefficientImaginaryPart->setText("");
            break;
        case CHANGE_LAST_ANSWER:
            new_size_name->hide();
            new_size_value->hide();
            new_size_value->setText("");
            submit_change_size_btn->hide();
            coefficientLabel->hide();
            coefficientRealPart->hide();
            coefficientRealPart->setText("");
            imaginaryDelimiter->hide();
            coefficientImaginaryPart->hide();
            coefficientImaginaryPart->setText("");
            pos_root_name->hide();
            pos_root_val->hide();
            pos_root_val->setText("");
            submit_change_root_btn->hide();
            constantTermLabel->hide();
            an_re->hide();
            an_re->setText("");
            an_delimiter->hide();
            an_im->hide();
            an_im->setText("");
            submit_an_btn->hide();
            submit_write_btn->hide();
             enterModeLabel->hide();
             enterModeLabel->setText("Введите an");
            output->setText("Полином изменен");
            break;
        default: break;
    }
}
