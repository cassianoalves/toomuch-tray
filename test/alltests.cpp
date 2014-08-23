#include <QString>
#include <QtTest>
#include <string>
#include "boost/filesystem.hpp"
#include "src/format.h"
#include "src/dao/configdatdao.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test() {}

private Q_SLOTS:
    // Format
    void testFormatTime()
    {
        QCOMPARE(Format::formatTime(120), std::string("02:00"));
    }

    void testFormatEvent()
    {
        QCOMPARE(Format::formatEvent(Pomodoro::POMODORO), std::string("Pomodoro"));
        QCOMPARE(Format::formatEvent(Pomodoro::LONG_BREAK), std::string("Long Break"));
        QCOMPARE(Format::formatEvent(Pomodoro::SHORT_BREAK), std::string("Short Break"));
    }


    // ConfigDatDao
    void testWriteNewFile()
    {
        boost::filesystem::remove("/tmp/config.json");
        ConfigDatDAO dao("/tmp");
        Config config;
        config.source = Config::TOOMUCH;
        config.sourceInfo = "info";
        config.updateTime = 66;
        config.widgetPosition = QPoint(0,10);

        dao.writeConfig(config);
        Config * newConfig = dao.readConfig();

        if (!boost::filesystem::exists("/tmp/config.json"))
            QFAIL("Arquivo nao foi criado.");

        boost::filesystem::remove("/tmp/config.json");

        QCOMPARE(newConfig->updateTime, config.updateTime);
        QCOMPARE(newConfig->sourceInfo, config.sourceInfo);
        QCOMPARE(newConfig->widgetPosition, config.widgetPosition);
        QCOMPARE(newConfig->source, config.source);
    }

};

QTEST_APPLESS_MAIN(Test)
#include "alltests.moc"





