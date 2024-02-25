#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

    int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QWidget mainWindow;
    mainWindow.setWindowTitle("Counter Application");

    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);

    // counter start 0
    QLabel counterLabel("Counter: 0");
    layout->addWidget(&counterLabel);

    // new QPushButton button
    QPushButton button("Increment");
    layout->addWidget(&button);

    // click -> inc count
    int counter = 0;
    QObject::connect(&button, &QPushButton::clicked, [&counter, &counterLabel]() {
        counter++;
        counterLabel.setText(QString("Counter: %1").arg(counter));
    });

    mainWindow.setLayout(layout);


    mainWindow.show();

    return app.exec();
}
