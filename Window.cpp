#include "Window.h"
#include <QPushButton>
#include <QApplication>


Window::Window(QWidget *parent) :
        QWidget(parent)
{
    // Set size of the window
    setFixedSize(1000, 500);

    // Create and position the button
    fsel_button = new QPushButton("Select Modpack", this);
    fsel_button->setGeometry(100, 450, 140, 30);

    folsel_button = new QPushButton("Select Game Folder", this);
    folsel_button->setGeometry(250, 450, 140, 30);

    cancel_button = new QPushButton("Cancel", this);
    cancel_button->setGeometry(10, 450, 80, 30);

    next_button = new QPushButton("Next", this);
    next_button->setGeometry(910, 450, 80, 30);

    text = new QLabel("Welcome to the DisruptionSystems CurseRipper.", this);
    text->setGeometry(355, 50, 1000, 400);
    text->show();

    progress = new QProgressBar(this);
    progress->setGeometry(50, 50, 900, 50);
    progress->setRange(0, 100);
    progress->setValue(0);

    connect(fsel_button, SIGNAL (clicked()), this, SLOT (spawnZipSelWindow()));
    connect(folsel_button, SIGNAL (clicked()), this, SLOT(spawnFolSelWindow()));
    connect(cancel_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    connect(next_button, SIGNAL (clicked()), this, SLOT (checkIfFilesAreThere()));

}
