#pragma once

#include <QDateTime>
#include <QString>


class Event
{
public:
    Event(QString eventTitle,
          QString category,
          QDateTime startDateTime,
          QDateTime endDateTime,
          QString location,
          QDateTime reminderTime,
          QString remarks);

    static bool createEventTable();

    bool saveToDatabase();

private:
    QString eventTitle;
    QString category;
    QDateTime startDateTime;
    QDateTime endDateTime;
    QString location;
    QDateTime reminderTime;
    QString remarks;
};
