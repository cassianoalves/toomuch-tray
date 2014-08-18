#include <QString>
#include <QtTest>
#include <string>
#include "src/format.h"
#include "src/format.cpp"

class FormatTest : public QObject
{
    Q_OBJECT

public:
    FormatTest();

private Q_SLOTS:
    void testFormatTime();
    void testFormatEvent();
};

FormatTest::FormatTest()
{
}

void FormatTest::testFormatTime()
{
    QCOMPARE(Format::formatTime(120), std::string("02:00"));
}

void FormatTest::testFormatEvent()
{
    QCOMPARE(Format::formatEvent(Pomodoro::POMODORO), std::string("Pomodoro"));
    QCOMPARE(Format::formatEvent(Pomodoro::LONG_BREAK), std::string("Long Break"));
    QCOMPARE(Format::formatEvent(Pomodoro::SHORT_BREAK), std::string("Short Break"));
}



QTEST_APPLESS_MAIN(FormatTest)

#include "tst_format.moc"
