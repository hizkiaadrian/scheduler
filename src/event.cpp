#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "event.h"
#include "eventcategory.h"


extern QSqlDatabase* dbConnectionPtr;

Event::Event(QString eventTitle,
             QString category,
             QDateTime startDateTime,
             QDateTime endDateTime,
             QString location,
             QDateTime reminderTime,
             QString remarks) :
    eventTitle(eventTitle),
    category(category),
    startDateTime(startDateTime),
    endDateTime(endDateTime),
    location(location),
    reminderTime(reminderTime),
    remarks(remarks) {}


bool Event::createEventTable() {
    QSqlQuery sqlQuery(*dbConnectionPtr);

    return sqlQuery.exec("CREATE TABLE IF NOT EXISTS events("
                         "event_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "event_title TEXT NOT NULL,"
                         "category_id INTEGER NOT NULL,"
                         "start_date_time TEXT NOT NULL,"
                         "end_date_time TEXT,"
                         "location TEXT,"
                         "reminder_time TEXT NOT NULL,"
                         "remarks TEXT,"
                         "FOREIGN KEY (category_id)"
                         "  REFERENCES categories (category_id)"
                         "      ON UPDATE CASCADE"
                         "      ON DELETE CASCADE);");

}


bool Event::saveToDatabase() {
    QSqlQuery sqlQuery(*dbConnectionPtr);

    sqlQuery.prepare("INSERT INTO events "
                         "(event_title,"
                         " category_id,"
                         " start_date_time,"
                         " end_date_time,"
                         " location,"
                         " reminder_time,"
                         " remarks)"
                         "VALUES (:event_title,"
                         " :category_id,"
                         " :start_date_time,"
                         " :end_date_time,"
                         " :location,"
                         " :reminder_time,"
                         " :remarks)");

    sqlQuery.bindValue(":event_title", eventTitle);
    sqlQuery.bindValue(":category_id", EventCategory::getCategoryById(category));
    sqlQuery.bindValue(":start_date_time", startDateTime);
    sqlQuery.bindValue(":end_date_time", endDateTime);
    sqlQuery.bindValue(":location", location);
    sqlQuery.bindValue(":reminder_time", reminderTime);
    sqlQuery.bindValue(":remarks", remarks);

    return sqlQuery.exec();
}
