#include "basewidget.h"
#include <QPainter>
#include <QStyleOption>

namespace ProgressBar
{
	BaseWidget::BaseWidget(QWidget *parent) :
		QWidget(parent), m_currentValue(0), m_maxValue(100),
		m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
	{
		resize(100, 100);
		//setAttribute(Qt::WA_TranslucentBackground);		//	背景透明..
	}

	BaseWidget::BaseWidget(int _currentValue, int _maxValue, QWidget *parent) :
		QWidget(parent), m_currentValue(_currentValue), m_maxValue(_maxValue),
		m_backgroundColor("#5f8aa4"), m_foregroundColor("#a6becd"), m_textColor("#5f8aa4")
	{
		resize(100, 100);
		//setAttribute(Qt::WA_TranslucentBackground);		//	背景透明..
	}

	qreal BaseWidget::percentage()
	{
		return (qreal)m_currentValue / m_maxValue;
	}

	void BaseWidget::setCurrentValue(int currentValue)
	{
		if (currentValue >= m_maxValue)
			m_currentValue = m_maxValue;
		else if	(currentValue <= 0)
			m_currentValue = 0;
		else
			m_currentValue = currentValue;
		update();
	}

	void BaseWidget::setMaxValue(int maxValue)
	{
		m_maxValue = maxValue;
		update();
	}

	void BaseWidget::setCurrentValue(qreal value)
	{
		setCurrentValue(int(value * m_maxValue));
	}

	void BaseWidget::paintEvent(QPaintEvent *)
	{
		QPainter painter(this);
		QStyleOption opt;
		opt.init(this);
		style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
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

}


