#include "circelbar.h"
#include <QPainter>

ProgressBar::CircelBar::CircelBar(QWidget *parent) :
	BaseWidget(parent), m_font(), m_pen()
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
	setMinimumSize(50, 50);
}

ProgressBar::CircelBar::CircelBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent), m_font(), m_pen()
{
	setTextColor(QColor("#435331"));
	setForegroundColor(QColor("lightblue"));
	setMinimumSize(50, 50);
}

void ProgressBar::CircelBar::paintEvent(QPaintEvent *)
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

	DRAWTEXT(painter, m_pen, m_font);		//	绘画文字..
}

void ProgressBar::CircelBar::resizeEvent(QResizeEvent */*size*/)
{
	int s;
	frameSize().width() > frameSize().height() ?
				s = frameSize().height() : s = frameSize().width();
	m_font.setPixelSize(s / 4);
	resize(s, s);
}

QFont ProgressBar::CircelBar::font() const
{
	return m_font;
}

void ProgressBar::CircelBar::setFont(const QFont &font)
{
	m_font = font;
}
