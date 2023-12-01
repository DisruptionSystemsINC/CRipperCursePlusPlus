// JsonManip.cpp
#include <fstream>
#include <QCoreApplication>
#include "JsonManip.h"
#include "QtGlobal"

QThread* JsonManip::getJson(QProgressBar* progress, std::string folder) {
    auto* thread = new QThread();

    // Move the JsonManip instance to the new thread
    auto* jsonManip = new JsonManip();
    jsonManip->moveToThread(thread);

    // Connect signals and slots for progress updates
    QObject::connect(jsonManip, &JsonManip::progressUpdated, progress, &QProgressBar::setValue);

    // Connect thread finished signal to delete the JsonManip instance
    QObject::connect(thread, &QThread::finished, jsonManip, &QObject::deleteLater);

    // Connect the thread started signal to the run method of JsonManip
    QObject::connect(thread, &QThread::started, [jsonManip, folder, &progress]() {
        jsonManip->run(progress, folder);
    });

    return thread;
}

void JsonManip::DownloadMod(int ProjectID, int fileID, std::string folder) {
        system(std::string ("cd " + folder + "/mods && wget --content-disposition " + "https://www.curseforge.com/api/v1/mods/" + std::to_string(ProjectID) + "/files/" + std::to_string (fileID) + "/download").c_str());
    }
    // Your DownloadMod implementation remains the same

void JsonManip::run(QProgressBar* progress, std::string folder) {
    std::ifstream f(folder + "/manifest.json");
    json object = json::parse(f);
    auto FilesArray = object["files"];

    int slope = (100) / FilesArray.size();

    for (int i = 0; i < FilesArray.size(); i++) {
        auto ProjectID = FilesArray[i]["projectID"];
        auto fileID = FilesArray[i]["fileID"];
        DownloadMod(ProjectID, fileID, folder);
        // Update the progress
        int progressValue;
        progressValue = qBound(0, ((i + 1) * 100 / int (FilesArray.size())), 100);
        emit progressUpdated(progressValue);
    }

    emit progressUpdated(100);
}