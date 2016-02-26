#include "bordersectorbar.h"
#include <QPainter>

ProgressBar::BorderSectorBar::BorderSectorBar(QWidget *parent) :
	BaseWidget(parent), m_pen(), m_font()
{
	setTextColor(QColor("#645454"));
	setMinimumSize(50, 50);
}

ProgressBar::BorderSectorBar::BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent), m_pen(), m_font()
{
	setTextColor(QColor("#645454"));
	setMinimumSize(50, 50);
}


void ProgressBar::BorderSectorBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRectF rect(2, 2, width()-4, height()-4);
	qreal _percentage = percentage();
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setPen(Qt::NoPen);
	painter.setBrush(backgroundColor());
	painter.drawEllipse(rect);

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(2);
	painter.setPen(m_pen);
	painter.drawEllipse(rect);

	if (_percentage)
	{
		painter.setBrush(foregroundColor());
		painter.drawPie(8, 8, width()-16, height()-16, 0.25 * RADIAN,
						-_percentage * RADIAN);		//	+： 逆时针 -： 顺时针
	}
	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void ProgressBar::BorderSectorBar::resizeEvent(QResizeEvent * /*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont ProgressBar::BorderSectorBar::font() const
{
	return m_font;
}

void ProgressBar::BorderSectorBar::setFont(const QFont &font)
{
	m_font = font;
}





