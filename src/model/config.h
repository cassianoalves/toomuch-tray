#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <QPoint>


class Config
{
public:
    typedef enum {
        OFFLINE = 0,
        TOOMUCH = 1,
        SHELL = 2,
        TOMATOI = 3
    } Source;

    Config();

    Source source;
    std::string sourceInfo;
    long updateTime;
    QPoint widgetPosition;
    void setSource(int);


};

#endif // CONFIG_H
