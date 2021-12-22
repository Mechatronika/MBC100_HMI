#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QStringList>

class Status
{
public:

    int iOK = 1;
    QString arrStatus[10];
    QString arrMessages[1000];

    Status()
    {


        //============================ Read Status TEXT
        QFile statusfile("Status.txt");
        if(statusfile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&statusfile);
           in.setCodec("UTF-8");
           QStringList list;
           QStringList templist;
           int num = 0;
           while(!in.atEnd()) list.append(in.readLine());
           for(int i = 0; i<list.count(); i++)
           {
                templist = list.at(i).split("=");
                if(templist.count() == 2)
                {
                    num = templist.at(0).toInt();
                    if(num <101)
                        if(num >=0)
                            arrStatus[num] = templist.at(1);
                }
                templist.clear();
           }
           iOK = 0;
           statusfile.close();
        }
        else
        {
            iOK = -1;
            for(int i = 0; i < 10; i++ ) arrStatus[i] = "-";
        }


        //============================ Read Message TEXT
        QFile messagefile("Messages.txt");
        if(messagefile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&messagefile);
           in.setCodec("UTF-8");
           QStringList list;
           QStringList templist;
           int num = 0;
           while(!in.atEnd()) list.append(in.readLine());
           for(int i = 0; i<list.count(); i++)
           {
                templist = list.at(i).split("=");
                if(templist.count() == 2)
                {
                    num = templist.at(0).toInt();
                    if(num <101)
                        if(num >=0)
                            arrMessages[num] = templist.at(1);
                }
                templist.clear();
           }
           iOK = 0;
           messagefile.close();
        }
        else
        {
            iOK = -2;
            for(int i = 0; i < 1000; i++ ) arrMessages[i] = "-";
        }
    }
};

#endif // STATUS_H
