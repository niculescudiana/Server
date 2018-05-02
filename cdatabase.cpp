#include "cdatabase.h"

CDataBase::CDataBase(){}
CDataBase::~CDataBase(){}

CDataBase* CDataBase::mp_Instance = nullptr;

CDataBase* CDataBase::getInstance() {

return (!mp_Instance) ?
    mp_Instance = new CDataBase:
    mp_Instance;
}

void CDataBase::setDataBase()
{


    QDomDocument doc("mydocument");

    //Create the root element
    QDomElement docRootElem = doc.createElement("Users");
    doc.appendChild(docRootElem);

    QDomElement newUser = doc.createElement("user");

    /*QDomElement lastUser = docRootElem.lastChildElement("user");
    int lastUserID = lastUser.attribute("id").toInt();
    int newUserID = lastUserID + 1;
    newUser.setAttribute("id", lastUserID + 1);
*/

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
