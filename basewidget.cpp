#include "basewidget.h"
#include <QPainter>

BaseWidget::BaseWidget(QWidget *parent) :
	QWidget(parent), m_currentValue(0), m_maxValue(100),
	m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
{
	resize(100, 100);
}

BaseWidget::BaseWidget(int _currentValue, int _maxValue, QWidget *parent) :
	QWidget(parent), m_currentValue(_currentValue), m_maxValue(_maxValue),
	m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
{
	resize(100, 100);
}

qreal BaseWidget::percentage()
{
	return (qreal)m_currentValue / m_maxValue;
}

void BaseWidget::setCurrentValue(int currentValue)
{
	m_currentValue = currentValue;
	update();
}

void BaseWidget::setMaxValue(int maxValue)
{
	m_maxValue = maxValue;
	update();
}



void BaseWidget::drawLineText(QPainter &painter)
{
	QPen pen;
	QFont font = painter.font();
	font.setPixelSize(25);
	painter.setFont(font);
	pen.setColor(m_textColor);
	painter.setPen(pen);
	painter.drawText(0, 0, width(), height(), Qt::AlignCenter,
					 QString::number(100 * currentValue() / maxValue()) + "%");
}


QColor BaseWidget::backgroundColor() const
{
	return m_backgroundColor;
}

void BaseWidget::setBackgroundColor(const QColor &backgroundColor)
{
	m_backgroundColor = backgroundColor;
}

QColor BaseWidget::foregroundColor() const
{
	return m_foregroundColor;
}

void BaseWidget::setForegroundColor(const QColor &foregroundColor)
{
	m_foregroundColor = foregroundColor;
}

QColor BaseWidget::textColor() const
{
	return m_textColor;
}

void BaseWidget::setTextColor(const QColor &textColor)
{
	m_textColor = textColor;
}

