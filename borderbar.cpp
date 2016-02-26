#include "borderbar.h"
#include <QPainter>

ProgressBar::BorderBar::BorderBar(QWidget *parent) :
	BaseWidget(parent), m_font(), m_pen()
{
	setTextColor(QColor("lightgray"));
	setMinimumSize(50, 50);
}

ProgressBar::BorderBar::BorderBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent), m_font(), m_pen()
{
	setTextColor(QColor("lightgray"));
	setMinimumSize(50, 50);
}

void ProgressBar::BorderBar::paintEvent(QPaintEvent *)
{
	QRectF rect(2, 2, width()-4, height()-4);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);		//	边缘平滑..

	painter.setBrush(backgroundColor());
	painter.setPen(Qt::NoPen);
	painter.drawEllipse(rect);
	painter.setBrush(Qt::NoBrush);

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(4);
	painter.setPen(m_pen);

	painter.drawArc(rect, 0.25 * RADIAN, -percentage() * RADIAN);	//	+： 逆时针 -： 顺时针
	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void ProgressBar::BorderBar::resizeEvent(QResizeEvent * /*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont ProgressBar::BorderBar::font() const
{
	return m_font;
}

void ProgressBar::BorderBar::setFont(const QFont &font)
{
	m_font = font;
}



