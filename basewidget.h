#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

#define RADIAN 360 * 16

class BaseWidget : public QWidget
{
	Q_OBJECT
//	Q_PROPERTY(int currentValue READ currentValue WRITE setCurrentValue)
//	Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue)
//	Q_PROPERTY(QString foregroundColor READ foregroundColor WRITE setForegroundColor)
//	Q_PROPERTY(QString backgroundColor READ backgroundColor WRITE setBackgroundColor)
//	Q_PROPERTY(QString textColor READ textColor WRITE setTextColor)
public:
	explicit BaseWidget(QWidget *parent = 0);
	explicit BaseWidget(int _currentValue, int _maxValue, QWidget *parent = 0);
	virtual ~BaseWidget() {}

	qreal percentage();

	inline int currentValue() const { return m_currentValue; }
	inline int maxValue() const { return m_maxValue; }

	QColor backgroundColor() const;
	void setBackgroundColor(const QColor &backgroundColor);

	QColor foregroundColor() const;
	void setForegroundColor(const QColor &foregroundColor);

	QColor textColor() const;
	void setTextColor(const QColor &testColor);

signals:
	void done();

public slots:
	void setCurrentValue(int currentValue);
	void setMaxValue(int maxValue);

protected:
	virtual void paintEvent(QPaintEvent *) = 0;
	void drawLineText(QPainter &painter);

private:
	int m_currentValue, m_maxValue;
	QColor m_backgroundColor;
	QColor m_foregroundColor;
	QColor m_textColor;
};

#endif // BASEWIDGET_H
