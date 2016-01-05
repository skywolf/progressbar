#include "basewidget.h"
#include <QPainter>

ProgressBar::BaseWidget::BaseWidget(QWidget *parent) :
	QWidget(parent), m_currentValue(0), m_maxValue(100),
	m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
{
	resize(100, 100);
}

ProgressBar::BaseWidget::BaseWidget(int _currentValue, int _maxValue, QWidget *parent) :
	QWidget(parent), m_currentValue(_currentValue), m_maxValue(_maxValue),
	m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
{
	resize(100, 100);
}

qreal ProgressBar::BaseWidget::percentage()
{
	return (qreal)m_currentValue / m_maxValue;
}

void ProgressBar::BaseWidget::setCurrentValue(int currentValue)
{
	if (currentValue >= m_maxValue)
		m_currentValue = 100;
	else if	(currentValue <= 0)
		m_currentValue = 0;
	else
		m_currentValue = currentValue;
	update();
}

void ProgressBar::BaseWidget::setMaxValue(int maxValue)
{
	m_maxValue = maxValue;
	update();
}



QColor ProgressBar::BaseWidget::backgroundColor() const
{
	return m_backgroundColor;
}

void ProgressBar::BaseWidget::setBackgroundColor(const QColor &backgroundColor)
{
	m_backgroundColor = backgroundColor;
}

QColor ProgressBar::BaseWidget::foregroundColor() const
{
	return m_foregroundColor;
}

void ProgressBar::BaseWidget::setForegroundColor(const QColor &foregroundColor)
{
	m_foregroundColor = foregroundColor;
}

QColor ProgressBar::BaseWidget::textColor() const
{
	return m_textColor;
}

void ProgressBar::BaseWidget::setTextColor(const QColor &textColor)
{
	m_textColor = textColor;
}


