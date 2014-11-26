#include "util.h"

#include <QTime>
#include <QStringListIterator>

QString BakaUtil::FormatTime(int _time, int _totalTime)
{
    QTime time = QTime::fromMSecsSinceStartOfDay(_time * 1000);
    if(_totalTime >= 3600) // hours
        return time.toString("h:mm:ss");
    if(_totalTime >= 60)   // minutes
        return time.toString("mm:ss");
    return time.toString("0:ss");   // seconds
}

QString BakaUtil::FormatNumber(int val, int length)
{
    if(length < 10)
        return QString::number(val);
    else if(length < 100)
        return QString("%1").arg(val, 2, 10, QChar('0'));
    else
        return QString("%1").arg(val, 3, 10, QChar('0'));
}

QString BakaUtil::FormatNumberWithAmpersand(int val, int length)
{
    if(length < 10)
        return "&"+QString::number(val);
    else if(length < 100)
    {
        if(val < 10)
            return "0&"+QString::number(val);
        return QString("%1").arg(val, 2, 10, QChar('0'));
    }
    else
    {
        if(val < 10)
            return "00&"+QString::number(val);
        return QString("%1").arg(val, 3, 10, QChar('0'));
    }
}

QString BakaUtil::HumanSize(qint64 size)
{
    // taken from http://comments.gmane.org/gmane.comp.lib.qt.general/34914
    float num = size;
    QStringList list;
    list << "KB" << "MB" << "GB" << "TB";

    QStringListIterator i(list);
    QString unit("bytes");

    while(num >= 1024.0 && i.hasNext())
     {
        unit = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num,'f',2)+" "+unit;
}


QString BakaUtil::ShortenPathToParent(const QString &path)
{
    int pos = path.lastIndexOf('/');
    if(pos != -1)
    {
        pos = path.lastIndexOf('/', pos-1);
        if(pos != -1)
            return path.mid(pos+1);
    }
    return path;
}
