#include "messages.h"
#include <QDebug>

Messages::Messages()
{
    //==============================================XML processiing===========================================================
       QFile xmlFile("Messages.xml");
              if(xmlFile.exists())
              {
                if (xmlFile.open(QIODevice::ReadOnly))
                {
                    //The QDomDocument class represents an XML document.
                    QDomDocument xmlBOM;
                    // Set data into the QDomDocument before processing
                    xmlBOM.setContent(&xmlFile);
                    //close reader and flush file
                    xmlFile.close();
                    //==========================================================================================================================================================


                    // Extract the root markup
                    QDomElement root=xmlBOM.documentElement();

                    // Get root names and attributes
                    QString Type=root.tagName();
                    int Version=root.attribute("Version","0").toInt();

                    // Display root data
                    qDebug() << "Type  = " << Type;
                    qDebug() << "Version = " << Version;

                     //==========================================================================================================================================================
                    // Get the first child of the root (Markup COMPONENT is expected)
                    QDomElement Component=root.firstChild().toElement();

                    // Loop while there is a child
                    while(!Component.isNull())
                    {
                        // Check if the child tag name is COMPONENT
                        if (Component.tagName()=="Status")
                        {

                            // Read and display the component ID
                            int ID = Component.attribute("id","No ID").toInt();
                            // Read and display the component TEXT
                            arrStatus[ID] = Component.text();
                        }
                        else
                        if (Component.tagName()=="Message")
                        {

                            // Read and display the component ID
                            int ID = Component.attribute("id","No ID").toInt();
                            // Read and display the component TEXT
                            arrMessages[ID] = Component.text();
                        }
                        // Next component
                        Component = Component.nextSibling().toElement();
                    }

                }
                else
                {
                    OK = -2;      // File Not Open
                    return;
                }
              }
              else
              {
                  OK = -1;      // File Not Found
                  return;
              }
    /*
    QFile file("ErrorText.txt");
    if(file.open(QIODevice::ReadOnly))
    {
       QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
       QTextStream in(&file);
       in.setCodec("UTF-8");
       QStringList list;
       QStringList templist;
       int num = 0;
       while(!in.atEnd())
       list.append(in.readLine());
       for(int i = 0; i<list.count(); i++)
       {
            templist = list.at(i).split("=");
            if(templist.count() == 2)
            {
                num = templist.at(0).toInt();
                if(num < 1001)
                    if(num >=0)
                        arrMessages[num] = templist.at(1);
            }
            templist.clear();
       }
       boOK = true;
    }
    else
    {
        boOK = false;
        for(int i = 0; i < 1000; i++ ) arrMessages[i] = "-";
    }
    */
              for(int a = 0; a<10; a++)qDebug()<<arrStatus[a];
}
