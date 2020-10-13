#pragma once

#include <QDateTime>
#include <QString>
#include <QVector>

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

    static QVector<Event> getAllEvents();

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
