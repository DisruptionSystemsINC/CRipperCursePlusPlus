#ifndef WINDOW_H
#define WINDOW_H

#include "QLabel"
#include "QProgressBar"
#include <QWidget>
#include <QFileDialog>
#include <QTextBlock>
#include "iostream"

class QPushButton;
class Window : public QWidget
{
public:
    explicit Window(QWidget *parent = 0);

private:
    QPushButton *cancel_button;
    QPushButton *fsel_button;
    QPushButton *next_button;
    QPushButton *folsel_button;
    QFileDialog fsel_diag;
    QFileDialog folsel_diag;
    QProgressBar *progress;
    QLabel *text;
    QString folder;
    QString zipfile;

Q_OBJECT

public slots:
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
        if (zipfile !="" && folder !=""){
            std::cout << "Success!" << std::endl;
        }
        else{
            std::cout << "Failure" << std::endl;
        }
    }
};


#endif // WINDOW_H