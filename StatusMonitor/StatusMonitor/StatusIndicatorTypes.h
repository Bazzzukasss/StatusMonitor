#ifndef STATUSINDICATORTYPES_H
#define STATUSINDICATORTYPES_H

template<typename T>
class StatusIndictorType{
public:
    StatusIndictorType(const T& value)
        :mValue(value)
    {

    }
    void setValue(const T& value)
    {
        mValue = value;
    }
    const T& getValue()
    {
        return mValue;
    }

private:
    T mValue;
};

template<typename T>
class SIDigits     : public StatusIndictorType<T>{
public:
    SIDigits(T value = 0,T min= std::numeric_limits<T>::min(),T max = std::numeric_limits<T>::max())
        :StatusIndictorType<T>(value),mMin(min),mMax(max)
    {}
    T getMaximum(){return mMax;}
    T getMinimum(){return mMin;}
private:
    T mMin;
    T mMax;
};



class SIInteger      : public SIDigits<int>{
public:
    SIInteger(int value = 0,int min= std::numeric_limits<int>::min(),int max = std::numeric_limits<int>::max()):SIDigits<int>(value,min,max){}
};

class SIDouble      : public SIDigits<double>{
public:
    SIDouble(double value = 0,double min= std::numeric_limits<double>::min(),double max = std::numeric_limits<double>::max()):SIDigits<double>(value,min,max){}
};

class SIProgress    : public SIDigits<int>{
public:
    SIProgress(int value = 0,int min= std::numeric_limits<int>::min(),int max = std::numeric_limits<int>::max()):SIDigits<int>(value,min,max){}
};

class SILcd         : public StatusIndictorType<double>{
public:
    enum mode{HEX,DEC,OCT,BIN};
    SILcd(double value = 0,int mode = DEC):StatusIndictorType<double>(value),mDisplayMode(mode){}
    int getDisplayMode(){return mDisplayMode;}
private:
    int mDisplayMode;
};

class SIString      : public StatusIndictorType<QString>{
public:
    SIString(const QString& value = ""):StatusIndictorType<QString>(value){}
};

class SIPlot        : public StatusIndictorType<QVector<double>>{
public:
    SIPlot(const QVector<double>& value = QVector<double>()):StatusIndictorType<QVector<double>>(value){}
};

class SIBars        : public SIPlot{
public:
    SIBars(const QVector<double>& value = QVector<double>()):SIPlot(value){}
};

class SIGraph        : public SIPlot{
public:
    SIGraph(const QVector<double>& value = QVector<double>()):SIPlot(value){}
};

class SIBoolean      : public StatusIndictorType<bool>{
public:
    SIBoolean(bool value = false):StatusIndictorType<bool>(value){}
};

Q_DECLARE_METATYPE(SIBoolean);
Q_DECLARE_METATYPE(SIInteger);
Q_DECLARE_METATYPE(SIDouble);
Q_DECLARE_METATYPE(SILcd);
Q_DECLARE_METATYPE(SIProgress);
Q_DECLARE_METATYPE(SIString);
Q_DECLARE_METATYPE(SIBars);
Q_DECLARE_METATYPE(SIGraph);

#endif //STATUSINDICATORTYPES_H
