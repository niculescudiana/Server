#include "cdatabase.h"
#include<QDebug>
#include<QList>

CDataBase::CDataBase(){}
CDataBase::~CDataBase(){}

CDataBase* CDataBase::mp_Instance = nullptr;

CDataBase* CDataBase::getInstance() {

return (!mp_Instance) ?
    mp_Instance = new CDataBase:
    mp_Instance;
}

void CDataBase::setDataBaseRegistered()
{


    QDomDocument doc("mydocument");

    //Create the root element
    QDomElement docRootElem = doc.createElement("Users");
    doc.appendChild(docRootElem);

    QDomElement newUser = doc.createElement("user");

    QDomElement usernameElement = doc.createElement("username");
    usernameElement.appendChild(doc.createTextNode("S2524"));
    newUser.appendChild(usernameElement);

    QDomElement passwordElement = doc.createElement("password");
    passwordElement.appendChild(doc.createTextNode("abcdef"));
    newUser.appendChild(passwordElement);

    QDomElement userTypeElement = doc.createElement("type");
    userTypeElement.appendChild(doc.createTextNode("student"));
    newUser.appendChild(userTypeElement);

    docRootElem.appendChild(newUser);


    QFile file("users.xml");

    //qDebug()<<"exists:" << file->exists();
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
        qDebug() <<"Could not open file";
    else
        {
        QTextStream stream(&file);
        stream << doc.toString();
        file.close();
        }

}

void CDataBase::setDataBaseUnregistered()
{
    QFile file("unregisteredaccounts.txt");
    if (!file.open(QIODevice::ReadOnly)){
        qDebug() <<"Nu s-a putut deschide fisierul 2";
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        qDebug() <<"Am citit user";
        QString username;

        username=in.readLine();
        qDebug() << username.toStdString().c_str();
        unregistered_accounts.append(username);

    }
   // for (std::list<std::string>::iterator it=unregistered_accounts.begin(); it != unregistered_accounts.end(); ++it)
    //    qDebug()<<*it->c_str();
}

void CDataBase::addUser(std::string username, std::string password)
{
    QFile file("users.xml");

    //qDebug()<<"exists:" << file->exists();
    QDomDocument doc("mydocument");
    if (!file.open(QIODevice::ReadWrite))
    {qDebug() <<"Nu s-a putut deschide fisierul 1"; return;}
    if (!doc.setContent(&file)) {
        qDebug() <<"Nu s-a putut reface continutul fisierului";
        file.close(); return;

    }

    //Get the root element
    QDomElement docRootElem = doc.documentElement();   // =Users
    qDebug()<<docRootElem.tagName().toStdString().c_str();

    QDomElement newUser = doc.createElement("user");

    QDomElement usernameElement = doc.createElement("username");
    usernameElement.appendChild(doc.createTextNode(username.c_str()));
    newUser.appendChild(usernameElement);

    qDebug()<<"1";

    QDomElement passwordElement = doc.createElement("password");
    passwordElement.appendChild(doc.createTextNode(password.c_str()));
    newUser.appendChild(passwordElement);

     qDebug()<<"2";

    QDomElement userTypeElement = doc.createElement("usertype");
    if(username[0]=='S')
        userTypeElement.appendChild(doc.createTextNode("student"));
    else  if(username[0]=='C')
         userTypeElement.appendChild(doc.createTextNode("cadru"));
    newUser.appendChild(userTypeElement);
 qDebug()<<"3";

    docRootElem.appendChild(newUser);
     qDebug()<<"4";

     file.resize(0);
    QTextStream stream(&file);
    stream<<doc.toString();
     qDebug()<<"5";
    file.close();
}


bool CDataBase::verifyLogin(std::string username, std::string password)
{
    QFile file("users.xml");


    /* QDomDocument takes any QIODevice. as well as QString buffer*/
    //qDebug()<<"exists:" << file.exists();
    QDomDocument doc("mydocument");
    if (!file.open(QIODevice::ReadOnly))
        return 0;
    if (!doc.setContent(&file)) {
        file.close();
        return 0;
    }

    //Get the root element
    QDomElement docElem = doc.documentElement();

    // you could check the root tag name here if it matters
    QString rootTag = docElem.tagName(); // == users

    // get the node's interested in, this time only caring about person's
    QDomNodeList nodeList = docElem.elementsByTagName("user");

    //Check each node one by one.
    int p=0;
    for(int ii = 0;ii < nodeList.count(); ii++)
    {

        // get the current one as QDomElement
        QDomElement el = nodeList.at(ii).toElement();


        bool usernameMatches = 0;
        bool passwordMatches=0;


        //get all data for the element, by looping through all child elements
        QDomNode pEntries = el.firstChild();
        while(!pEntries.isNull()) {
            QDomElement peData = pEntries.toElement();
            QString tagNam = peData.tagName();

            if(tagNam == "username") { /* We've found username. */
                if(peData.text().toStdString() == username)
                    usernameMatches = 1;

                else {
                    usernameMatches =0 ;
                    p++;
                }

            }
            else if(tagNam == "password") { /* We've found password. */
                if(usernameMatches == 1)
                {
                    if(peData.text().toStdString() == password)
                    {
                      passwordMatches=1;
                      return 1;
                    }
                    else
                         p++;

                }
            }
            pEntries = pEntries.nextSibling();
        }
    }
    if(p==nodeList.count())
        return 0;
}

bool CDataBase::verifyUnregisteredUser(QString username, QString password)
{
    /*for (std::list<const char*>::iterator it=unregistered_accounts.begin(); it != unregistered_accounts.end(); ++it)
    {

        qDebug() << *it ;
        if(*it ==username)
            return true;
    }
    return false;

    std::list<const char*>::iterator itr;
    std::list<int>::iterator x;
    itr.

    */

    /*
    QList<const char*>::iterator it;
    for(it=unregistered_accounts.begin();it!=unregistered_accounts.end();it++){
        qDebug() << *it;
        if(*it==username)
            return true;
    }*/

    QMutableListIterator<QString> iter(unregistered_accounts);
    while(iter.hasNext())
    {
       if(iter.next()==username){
           qDebug()<<"Match!";
           addUser(username.toStdString(),password.toStdString());
           iter.remove();
           qDebug()<<"removed";
           return 1;
       }
    }


    return false;
}

