
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <iostream>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
/*class Windows : public QWidget
{
public:
    Window(QWidget* parent = nullptr): QWidget(parent)
    {
        setFixedSize(500,500);
        name_edit = new QLineEdit(this);
        name_edit->move(100,100);
        name_edit->setStyleSheet("background:red;font:bold 15px;color:white");
        name = new QLabel("Name: ",this);
        name->move(50,100);
        button = new QPushButton("Press me",this);
        button->move(200,200);
        connect(button,&QPushButton::clicked,this,&Window::ButtonClicked);
    }
    void EnterPressed()
    {
        QMessageBox msg;
        msg.setText(name_edit->text());
        msg.exec();
    }
    void ButtonClicked()
    {
        QMessageBox msg;
        msg.setText(name_edit->text());
        msg.exec();
    }
private:
    QLabel* name;
    QLineEdit* name_edit;
    QPushButton* button;
};*/
class Window:public QWidget{
private:
    QVBoxLayout* mainLayout;
    QVBoxLayout* row1Layout;
    QVBoxLayout* row2Layout;
    QVBoxLayout* row3Layout;
    QVBoxLayout* row4Layout;

    QLabel* name_lable;
    QLabel* password_lable;
    QLabel* Water_Mark;

    QLineEdit* name_box;
    QLineEdit* password_box;

    QPushButton* login_button;
    QPushButton* cancel_button;
public:
    Window(QWidget* parent = nullptr): QWidget(parent)
    {
        /* allocate objects */
        mainLayout = new QVBoxLayout();
        row1Layout = new QVBoxLayout();
        row2Layout = new QVBoxLayout();
        row3Layout = new QVBoxLayout();
        row4Layout = new QVBoxLayout();

        name_lable = new QLabel("Name: ");
        password_lable = new QLabel("Password: ");
        Water_Mark = new QLabel("This Program made by Ahmed Emad");

        name_box = new QLineEdit();
        password_box = new QLineEdit();

        login_button = new QPushButton("Login");
        cancel_button = new QPushButton("Cancel");

        /* Properties */
        this->setWindowTitle("Login Screen");
        this->setMinimumWidth(300);
        password_box->setEchoMode(QLineEdit::EchoMode::Password);
        row1Layout->setSpacing(5);
        row2Layout->setSpacing(5);
        row3Layout->setSpacing(5);
        row4Layout->setSpacing(5);

        /* Events */
        connect(login_button,&QPushButton::clicked,this,&Window::LoginEvent);
        connect(cancel_button,&QPushButton::clicked,this,&Window::CancelEvent);
        /* insert widgets */
        row1Layout->addWidget(name_lable);
        row1Layout->addWidget(name_box);

        row2Layout->addWidget(password_lable);
        row2Layout->addWidget(password_box);

        row3Layout->addWidget(login_button);
        row3Layout->addWidget(cancel_button);

        row4Layout->addWidget(Water_Mark);

        /* Set Layouts */
        setLayout(mainLayout);
        mainLayout->addLayout(row1Layout);
        mainLayout->addLayout(row2Layout);
        mainLayout->addLayout(row3Layout);
        mainLayout->addLayout(row4Layout);
    }
    void LoginEvent()
    {
        QMessageBox* msgbox = new QMessageBox();
        msgbox->setWindowTitle("Login Msg");
        msgbox->setText("Login Succedded");
        msgbox->exec();
        delete msgbox;
        msgbox = nullptr;
    }
    void CancelEvent()
    {
        QMessageBox* msgbox = new QMessageBox();
        msgbox->setWindowTitle("Login Msg");
        msgbox->setText("Login Canceled");
        msgbox->exec();
        delete msgbox;
        msgbox = nullptr;
    }
    ~Window()
    {
        delete mainLayout;
        delete row1Layout;
        delete row2Layout;
        delete row3Layout;
        delete row4Layout;

        delete name_lable;
        delete password_lable;
        delete Water_Mark;

        delete name_box;
        delete password_box;

        delete login_button;
        delete cancel_button;
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();
}
