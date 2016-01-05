#include "horizontalbar.h"
#include <QPainter>

ProgressBar::HorizontalBar::HorizontalBar(QWidget *parent) :
	BaseWidget(parent), m_font()
{
	setTextColor(QColor("#645454"));
	resize(300, 30);
}

ProgressBar::HorizontalBar::HorizontalBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent), m_font()
{
	setTextColor(QColor("#645454"));
	resize(300, 30);
}

void ProgressBar::HorizontalBar::paintEvent(QPaintEvent *)
{
	qreal _width = width();
	qreal _height = height();
	qreal radius = _height / 2;
	qreal _percentage = percentage();
	QPainter painter(this);
	QRectF rect(2, 2, _width - 4, _height - 4);
	QRectF rectForeground(2, 2, _height + ((_width - _height) * _percentage)- 4, _height - 4);

	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	pen.setColor(foregroundColor());
	pen.setWidth(1);
	painter.setPen(pen);
	painter.setBrush(backgroundColor());
	painter.drawRoundedRect(rect, radius, radius);

	painter.setBrush(foregroundColor());
	painter.drawRoundedRect(rectForeground, radius, radius);

	pen.setColor(textColor());
	painter.setPen(pen);
	painter.setFont(m_font);
	painter.drawText(rectForeground, Qt::AlignRight | Qt::AlignVCenter,
					 QString::number(int(_percentage * 100)) + "% ");

}

void ProgressBar::HorizontalBar::resizeEvent(QResizeEvent * /* e */)
{
	m_font.setPixelSize(height() / 2);
}

QFont ProgressBar::HorizontalBar::font() const
{
	return m_font;
}

void ProgressBar::HorizontalBar::setFont(const QFont &font)
{
	m_font = font;
}
