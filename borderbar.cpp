#include "borderbar.h"
#include <QPainter>

BorderBar::BorderBar(QWidget *parent) :
	BaseWidget(parent)
{
	setTextColor(QColor("lightgray"));
}

BorderBar::BorderBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent)
{
	setTextColor(QColor("lightgray"));
}

void BorderBar::paintEvent(QPaintEvent *)
{
	QRectF rect(2, 2, width()-4, height()-4);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setBrush(backgroundColor());
	painter.setPen(Qt::NoPen);
	painter.drawEllipse(rect);
	painter.setBrush(Qt::NoBrush);

	QPen pen;
	pen.setColor(foregroundColor());
	pen.setWidth(4);
	painter.setPen(pen);

	painter.drawArc(rect, 0.25 * RADIAN, -percentage() * RADIAN);	//	+： 逆时针 -： 顺时针

	drawLineText(painter);		//	绘画文字..
}

void BorderBar::resizeEvent(QResizeEvent */*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	resize(s, s);
}



