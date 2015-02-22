#include "widget.h"
#include "ui_widget.h"
#include <QCryptographicHash>
#include <QList>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    sol = "0000";
    true_count = 0;
    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("abitur.sqlite");
    //dbase.setDatabaseName("student.sqlite");
    if (!dbase.open())
        qDebug() << "not open db!";
    a_query = new QSqlQuery;

    if (!a_query->exec("SELECT * FROM my_history"))
        qDebug() << "error! not exec select.";
    //QList<QString> history;
    while(a_query->next())
    {
        rec = a_query->record();
        history.append(a_query->value(rec.indexOf("text")).toString());
    }
    if (!a_query->exec("SELECT * FROM my_table"))
        qDebug() << "error! not exec select.";
    // setup fon widget!
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/fon")));
    this->setPalette(palette);
    // setup widget view
    ui->setupUi(this);
    ui->label->hide();
    ui->formFrame->hide();
    ui->progressBar->setValue(0);
    a_query->last();
    rec = a_query->record();
    ui->progressBar->setMaximum(a_query->value(rec.indexOf("id")).toInt()+1);
    if (!a_query->exec("SELECT * FROM my_table"))
        qDebug() << "error! not exec select.";
    rec = a_query->record();
    //ui->textBrowser_2->setText(history.first());
   // history.removeFirst();
    ui->progressBar->setMinimum(1);
    //qDebug() << a_query->value(rec.indexOf("id")).toString();
    get_next();
}
bool Widget::get_next()
{

    rec = a_query->record();
    ui->textBrowser_2->setText(history.first());
    if (history.first() != history.last()) history.removeFirst();
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if (a_query->next())
    {
        ui->textBrowser->setText(a_query->value(rec.indexOf("what")).toString());
        ui->pushButton->setText(a_query->value(rec.indexOf("1")).toString());
        ui->pushButton_2->setText(a_query->value(rec.indexOf("2")).toString());
        ui->pushButton_3->setText(a_query->value(rec.indexOf("3")).toString());
        ui->pushButton_4->setText(a_query->value(rec.indexOf("4")).toString());

        return true;
    }
    ui->textBrowser_2->setText(history.last());
    ui->label_5->setNum(ui->progressBar->maximum()-1);
    ui->label_4->setNum(true_count);
    ui->label_6->setNum(ui->progressBar->maximum()- true_count-1);
    if (true_count > ui->progressBar->maximum()- true_count-1)
        ui->lineEdit_2->setToolTip("Молодец! Так держать!");
    else
        ui->lineEdit_3->setToolTip("Не получилось. В следующий раз ты справишься лучше!");
    return false;
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButton_clicked()
{
    //TODO: вставить обработку ответа!
    QString str;
    str = sol + a_query->value(rec.indexOf("1")).toString() + sol;
    if (QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex() == a_query->value(rec.indexOf("hash")).toString())
        true_count++;
    qDebug() << QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex();
    if (!get_next())
    {
        ui->verticalFrame->setHidden(1);
        ui->formFrame->show();
    }
}

void Widget::on_pushButton_5_clicked()
{
    if (this->isFullScreen())
    {
        this->showNormal();
        ui->pushButton_5->setText("В полный экран!");
    } else
    {
        this->showFullScreen();
        ui->pushButton_5->setText("В окне!");
    }
}

void Widget::on_pushButton_2_clicked()
{
    //TODO: вставить обработку ответа!
    QString str;
    str = sol + a_query->value(rec.indexOf("2")).toString() + sol;
    if (QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex() == a_query->value(rec.indexOf("hash")).toString())
        true_count++;
    qDebug() << QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex();
    if (!get_next())
    {
        ui->verticalFrame->setHidden(1);
        ui->formFrame->show();
    }
}

void Widget::on_pushButton_3_clicked()
{
    //TODO: вставить обработку ответа!
    QString str;
    str = sol + a_query->value(rec.indexOf("3")).toString() + sol;
    if (QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex() == a_query->value(rec.indexOf("hash")).toString())
        true_count++;
    qDebug() << QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex();
    if (!get_next())
    {
        ui->verticalFrame->setHidden(1);
        ui->formFrame->show();
    }
}

void Widget::on_pushButton_4_clicked()
{
    //TODO: вставить обработку ответа!
    QString str;
    str = sol + a_query->value(rec.indexOf("4")).toString() + sol;
    if (QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex() == a_query->value(rec.indexOf("hash")).toString())
        true_count++;
    qDebug() << QCryptographicHash::hash(str.toUtf8(),QCryptographicHash::Md5).toHex();
    if (!get_next())
    {
        ui->verticalFrame->setHidden(1);
        ui->formFrame->show();
    }
}
