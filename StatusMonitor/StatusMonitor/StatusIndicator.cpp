#include "StatusIndicator.h"

StatusIndicator::StatusIndicator()
{
    addProperty("name","name");
    addProperty("value","value");
    addProperty("description","description");
}

StatusIndicator::StatusIndicator(const QString &name, const QVariant &value, const QString &description)
{
    addProperty("name",name);
    addProperty("value",value);
    addProperty("description",description);
}

StatusIndicator &StatusIndicator::operator=(const StatusIndicator &indicator)
{
    mProperties = indicator.mProperties;
    mIndexes = indicator.mIndexes;
    mPropertiesCount = indicator.mPropertiesCount;
    return *this;
}

void StatusIndicator::addProperty(const QString &propertyName, const QVariant &propertyValue)
{
    if(!mIndexes.contains(propertyName))
    {
        mProperties.push_back( IndicatorProperty(propertyName,propertyValue) );
        mIndexes[propertyName] = mPropertiesCount;
        ++mPropertiesCount;
    }
}

void StatusIndicator::setProperty(const QString &propertyName, const QVariant &propertyValue)
{
    if(mIndexes.contains(propertyName))
    {
        int index = mIndexes[propertyName];
        mProperties[index].mValue = propertyValue;
    }
}

QVariant StatusIndicator::getPropertyValue(const QString &propertyName) const
{
    if(mIndexes.contains(propertyName))
    {
        int index = mIndexes[propertyName];
        return mProperties[index].mValue;
    }
    else
        return QVariant();
}

QVariant StatusIndicator::getPropertyValue(int propertyIndex) const
{
    if( (0 <= propertyIndex) && (propertyIndex < mPropertiesCount) )
        return mProperties[propertyIndex].mValue;
    return QVariant();
}
