#ifndef TOPMESSAGE_H
#define TOPMESSAGE_H

#include <QWidget>

namespace Ui {
class TopMessage;
}

class TopMessage : public QWidget
{
    Q_OBJECT

public:
    explicit TopMessage(QWidget *parent = nullptr);
    ~TopMessage();
    void display(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::TopMessage *ui;
};

#endif // TOPMESSAGE_H
