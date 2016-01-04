#include "circelbar.h"
#include <QPainter>

CircelBar::CircelBar(QWidget *parent) :
	BaseWidget(parent)
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
}

CircelBar::CircelBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent)
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
}

void CircelBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF rect(2, 2, width()-4, height()-4);
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setPen(Qt::NoPen);
	painter.setBrush(backgroundColor());
	painter.drawEllipse(rect);

	painter.setBrush(foregroundColor());
	painter.drawPie(rect, 0.25 * RADIAN,
					-percentage() * RADIAN);

	drawLineText(painter);
}

