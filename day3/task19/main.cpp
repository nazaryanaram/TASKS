#include <Qlabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel* label = new QLabel ("Hello, World!");
    label->resize(400, 500);
    label->show();

    return a.exec();
}
