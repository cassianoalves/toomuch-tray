#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <QPoint>
class Config
{
public:
    typedef enum {
        OFFLINE,
        TOOMUCH,
        TOMATOI,
        SHELL
    } Source;

    Config();
    Config(Source, std::string, long);

    Source source;
    std::string sourceInfo;
    long updateTime;
    QPoint widgetPosition;
};

#endif // CONFIG_H
