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



    progress = new QProgressBar(this);
    progress->setGeometry(20, 100, 960, 250);
    progress->setRange(0, 100);
    progress->setValue(0);
    progress->setTextVisible(true);

    auto *jsonManip = new JsonManip();

    // Connect signal and slot
    connect(jsonManip, SIGNAL(progressUpdated(int)), this, SLOT(setProgress(int)));

    cancel_button = new QPushButton("Cancel", this);
    cancel_button->setGeometry(10, 450, 80, 30);

    next_button = new QPushButton("Next", this);
    next_button->setGeometry(910, 450, 80, 30);

    text = new QLabel("Welcome to the DisruptionSystems CurseRipper.", this);
    text->setGeometry(0, 100, 1000, 100);
    QFont font = text->font();
    font.setPointSize(15);
    font.setBold(true);
    text->setFont(font);
    text->setAlignment(Qt::AlignCenter);
    text->show();

    connect(fsel_button, SIGNAL (clicked()), this, SLOT (spawnZipSelWindow()));
    connect(folsel_button, SIGNAL (clicked()), this, SLOT(spawnFolSelWindow()));
    connect(cancel_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
    connect(next_button, SIGNAL (clicked()), this, SLOT (checkIfFilesAreThere()));

}


void Window::setProgress(int progressValue)
{
    progress->setValue(progressValue);
    text = new QLabel("Mods are being downloaded. " + QString(progressValue) + "% Done. ", this);
    text->setFont(font());
    text->setAlignment(Qt::AlignCenter);
    text->show();
}