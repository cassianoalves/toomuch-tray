#include <QString>
#include <QtTest>
#include <string>
#include "boost/filesystem.hpp"
#include "src/format.h"
#include "src/dao/configdatdao.h"
#include "src/dao/tomatoidao.h"


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
#define TEST_CONFIG_PATH "/tmp/.toomuch/config.json"
    void testWriteNewFile()
    {
        boost::filesystem::remove_all("/tmp/.toomuch");
        ConfigDatDAO dao("/tmp");
        Config config;
        config.source = Config::TOOMUCH;
        config.sourceInfo = "info";
        config.updateTime = 66;
        config.widgetPosition = QPoint(0,10);

        dao.writeConfig(config);
        Config * newConfig = dao.readConfig();

        if (!boost::filesystem::exists(TEST_CONFIG_PATH))
            QFAIL("Arquivo nao foi criado.");

        boost::filesystem::remove_all("/tmp/.toomuch");

        QCOMPARE(newConfig->updateTime, config.updateTime);
        QCOMPARE(newConfig->sourceInfo, config.sourceInfo);
        QCOMPARE(newConfig->widgetPosition, config.widgetPosition);
        QCOMPARE(newConfig->source, config.source);
    }

    void testTomatoiGetStatus() {
        TomatoiDAO dao;
        Pomodoro status = dao.getStatus("bla");
        QCOMPARE(status.timeRemaining, 1489L);
        QCOMPARE((int)status.pomodoroEvent, (int)Pomodoro::POMODORO);

    }

};

QTEST_APPLESS_MAIN(Test)
#include "alltests.moc"





