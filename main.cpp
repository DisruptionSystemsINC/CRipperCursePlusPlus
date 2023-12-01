#include <QApplication>
#include <QPushButton>
#include "Window.h"


int main(int argc, char **argv){
        QApplication app (argc, argv);

        Window window;
        window.show();
        QThread thread;

        return app.exec();
    }
