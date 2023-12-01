#ifndef WINDOW_H
#define WINDOW_H

#include "QLabel"
#include "QProgressBar"
#include <QWidget>
#include <QFileDialog>
#include <QTextBlock>
#include <QThread>
#include "iostream"
#include "nlohmann/json.hpp"
#include "thread"
#include "JsonManip.h"

class QPushButton;
class Window : public QWidget {
public:
    explicit Window(QWidget *parent = 0);

private:
    QPushButton *cancel_button;
    QPushButton *fsel_button;
    QPushButton *next_button;
    QPushButton *folsel_button;
    QFileDialog fsel_diag;
    QFileDialog folsel_diag;
    QLabel *text;
    QString folder;
    QString zipfile;
    QProgressBar *progress;


Q_OBJECT

public slots:

    void setProgress(int progress);

    void spawnZipSelWindow() {
        fsel_diag.setFileMode(QFileDialog::ExistingFile);
        fsel_diag.setNameFilter("Zip Archives (*.zip)");
        fsel_diag.setViewMode(QFileDialog::List);
        zipfile = fsel_diag.getOpenFileName();
    }

    void spawnFolSelWindow() {
        folsel_diag.setFileMode(QFileDialog::ExistingFile);
        folsel_diag.setViewMode(QFileDialog::List);
        folder = folsel_diag.getExistingDirectory(this, "Open Directory", "/home", QFileDialog::ShowDirsOnly);
    }

    void checkIfFilesAreThere() {
        if (!zipfile.isEmpty() && !folder.isEmpty()) {
            std::cout << "Success!" << std::endl;
            system((std::string("unzip " + zipfile.toStdString() + " -d " + folder.toStdString()).c_str()));
            system((std::string(
                    "cd " + folder.toStdString() + "/overrides && cp -r * .. && cd .. && mkdir mods")).c_str());

            QThread *t1 = JsonManip::getJson(progress, folder.toStdString());
            t1->start();
        } else {
            std::cout << "Failure" << std::endl;
        }
    }
};


#endif // WINDOW_H