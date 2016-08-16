#ifndef STATUSINDICATOR_H
#define STATUSINDICATOR_H

#include <QMap>
#include <QString>
#include <QVariant>
#include <QVector>

class StatusIndicator
{
    struct IndicatorProperty{
        IndicatorProperty(const QString& name, const QVariant& value)
            :mName(name),mValue(value)
        {}
        IndicatorProperty(){}
        QString     mName;
        QVariant    mValue;
    };
public:
    StatusIndicator();
    StatusIndicator(const QString& name,const QVariant& value,const QString& description = "");

    StatusIndicator& operator=(const StatusIndicator& indicator);

    void addProperty(const QString& propertyName, const QVariant& propertyValue);

    void setProperty(const QString& propertyName, const QVariant& propertyValue);

    QVariant getPropertyValue(const QString& propertyName) const;
    QVariant getPropertyValue(int propertyIndex) const;
private:
    QVector<IndicatorProperty> mProperties;
    QMap<QString,int> mIndexes;
    int mPropertiesCount{0};
};

Q_DECLARE_METATYPE(StatusIndicator)

#endif // STATUSINDICATOR_H
