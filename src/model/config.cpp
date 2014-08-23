#include "src/model/config.h"

Config::Config()
{
    source = Config::OFFLINE;
    sourceInfo = "";
    updateTime = 0;
    widgetPosition = QPoint(30,30);
}


void Config::setSource(int i)
{
    switch(i)
    {
    case Config::OFFLINE:
        source = Config::OFFLINE;
        break;
    case Config::TOMATOI:
        source = Config::TOMATOI;
        break;
    case Config::SHELL:
        source = Config::SHELL;
        break;
    case Config::TOOMUCH:
        source = Config::TOOMUCH;
        break;
    }
}
