#include "horizontalbar.h"
#include <QPainter>

HorizontalBar::HorizontalBar(QWidget *parent) :
	BaseWidget(parent)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);
}

HorizontalBar::HorizontalBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);
}

void HorizontalBar::paintEvent(QPaintEvent *)
{
	qreal radius = ((qreal)height()) / 2;
	qreal _percentage = percentage();
	QPainter painter(this);
	QRectF rect(2, 2, width()-4, height()-4);
	QRectF rectForeground(2, 2, width() * _percentage - 4, height() - 4);
	QPen pen;
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	pen.setColor(foregroundColor());
	pen.setWidth(1);
	painter.setPen(pen);
	painter.setBrush(backgroundColor());
	painter.drawRoundedRect(rect, radius, radius);

	if (_percentage != 0)
	{
		painter.setBrush(foregroundColor());
		painter.drawRoundedRect(rectForeground, radius, radius);

		pen.setColor(textColor());
		painter.setPen(pen);
		painter.drawText(rectForeground, Qt::AlignRight | Qt::AlignVCenter,
						 QString::number(int(_percentage * 100)) + "% ");
	}
}
