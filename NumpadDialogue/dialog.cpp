#include <NumpadDialogue/dialog.h>
QString myString;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{    
    ui.setupUi(this);
    this->setWindowTitle("Numpad");
    ui.labelMINMAX->setText("Last: " + myString + " Min: " + QString::number(ValMin) + " Max: " + QString::number(ValMax));
    myString = "";
    ui.lineEdit->setText("0");
}
Dialog::Dialog(double Min, double Max, int iMode, QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    ValMin = Min;
    ValMax = Max;
    iValMode = iMode;
    this->setWindowTitle("Numpad");
    ui.labelMINMAX->setText("Last: " + myString + " Min: " + QString::number(ValMin) + " Max: " + QString::number(ValMax));
    myString = "";
    ui.lineEdit->setText("0");
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui.retranslateUi(this);
        break;
    default:
        break;
    }
}

void Dialog::on_CLEAR_pressed()
{
    myString.clear();
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_tire_pressed()
{
   if(myString.contains("-"))
    {
        myString.remove("-");
    }
    else{
        myString.push_front("-");
    }    
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_dot_pressed()
{
    if(myString.isEmpty())myString.append("0"); //If string is empty - put a zero before decimal point
    myString.append(".");                       //Put decimal point
    ui.lineEdit->setText(myString);
}

void Dialog::on_ENTER_pressed()
{
    bool checkNum;                              // Flag for convertion check
    ui.lineEdit->text().toDouble(&checkNum);    // Convert to double number to check for right covertion
    if(!checkNum)return;                        // Do nothing if there are some letters    
    switch(iValMode)
    {
    case 0: //STRING
        emit Entered(ui.lineEdit->text());              // Return entered number as String
    break;

    case 1: //DOUBLE
        if(ValMin > ui.lineEdit->text().toDouble()) return; //Check if entered value is smaller then minimum?
        if(ValMax < ui.lineEdit->text().toDouble())return;  //Check if entered value is greather than maximum?
        emit dEntered(ui.lineEdit->text().toDouble());    // Return entered number as Double
    break;

    case 2: //INT
        if(ValMin > ui.lineEdit->text().toDouble()) return; //Check if entered value is smaller then minimum?
        if(ValMax < ui.lineEdit->text().toDouble())return;  //Check if entered value is greather than maximum?
        emit iEntered(ui.lineEdit->text().toInt());          // Return entered number as Integer
    break;
    }
    this->close();
}

void Dialog::on_pushButton_pressed()
{
    this->close();                              //Close NUMPAD
}

void Dialog::on_B_1_pressed()
{
    myString.append("1");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_2_pressed()
{
    myString.append("2");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_3_pressed()
{
    myString.append("3");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_4_pressed()
{
    myString.append("4");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_5_pressed()
{
    myString.append("5");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_6_pressed()
{
    myString.append("6");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_7_pressed()
{
    myString.append("7");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_8_pressed()
{
    myString.append("8");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_9_pressed()
{
    myString.append("9");
    ui.lineEdit->setText(myString);
}

void Dialog::on_B_0_pressed()
{
    myString.append("0");
    ui.lineEdit->setText(myString);
}

void Dialog::on_lineEdit_returnPressed()
{
    bool checkNum;                              // Flag for convertion check
    ui.lineEdit->text().toDouble(&checkNum);    // Convert to double number to check for right covertion
    if(!checkNum)return;                        // Do nothing if there are some letters
    switch(iValMode)
    {
        case 0: //STRING
            emit Entered(ui.lineEdit->text());              // Return entered number as String
        break;

        case 1: //DOUBLE
            if(ValMin > ui.lineEdit->text().toDouble()) return; //Check if entered value is smaller then minimum?
            if(ValMax < ui.lineEdit->text().toDouble())return;  //Check if entered value is greather than maximum?
            emit dEntered(ui.lineEdit->text().toDouble());    // Return entered number as Double
        break;

        case 2: //INT
            if(ValMin > ui.lineEdit->text().toDouble()) return; //Check if entered value is smaller then minimum?
            if(ValMax < ui.lineEdit->text().toDouble())return;  //Check if entered value is greather than maximum?
            emit iEntered(ui.lineEdit->text().toInt());          // Return entered number as Integer
        break;
    }
    this->close();
}
