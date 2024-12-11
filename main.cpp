#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Path to the image you want to display in the welcome dialog
    QString imagePath = "pieindialogo.jpg";  // Adjust path as needed

    // Show the welcome dialog with the image
    WelcomeDialog welcomeDialog(imagePath);
    welcomeDialog.exec();  // Blocks until the dialog closes

    MainWindow w;
    w.setWindowIcon(QIcon("pieIndiaLogo.ico"));
    w.setWindowTitle("Fatigue Testing");
    w.show();

    return a.exec();
}
