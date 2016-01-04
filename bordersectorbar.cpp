#include "bordersectorbar.h"
#include <QPainter>

BorderSectorBar::BorderSectorBar(QWidget *parent) :
	BaseWidget(parent)
{
	setTextColor(QColor("#645454"));
}

BorderSectorBar::BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent)
{
	setTextColor(QColor("#645454"));
}


void BorderSectorBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF rect(2, 2, width()-4, height()-4);
	qreal _percentage = percentage();
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setPen(Qt::NoPen);
	painter.setBrush(backgroundColor());
	painter.drawEllipse(rect);

	QPen pen;
	pen.setColor(foregroundColor());
	pen.setWidth(2);
	painter.setPen(pen);
	painter.drawEllipse(rect);

	if (_percentage)
	{
		painter.setBrush(foregroundColor());
		painter.drawPie(8, 8, width()-16, height()-16, 0.25 * RADIAN,
						-_percentage * RADIAN);		//	+： 逆时针 -： 顺时针
	}
	drawLineText(painter);
}

void BorderSectorBar::resizeEvent(QResizeEvent */*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	resize(s, s);
}





