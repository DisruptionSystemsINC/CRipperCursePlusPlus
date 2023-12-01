#ifndef JSONMANIP_H
#define JSONMANIP_H

#include <QThread>
#include "QObject"
#include <QProgressBar>
#include "nlohmann/json.hpp"

class JsonManip : public QObject
{
Q_OBJECT

public:
    using json = nlohmann::json;

    static QThread* getJson(QProgressBar* progress, std::string folder);

signals:
    void progressUpdated(int progress);

private:
    void DownloadMod(int ProjectID, int fileID, std::string folder);

public slots:
    void run(QProgressBar* progress, std::string folder);
};

#endif
