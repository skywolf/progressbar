#include "horizontalbar.h"
#include <QPainter>
#include <QMouseEvent>

ProgressBar::HorizontalBar::HorizontalBar(QWidget *parent) :
	BaseWidget(parent), m_pen(), m_font(), m_isPressed(false), m_cursorChange(false)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);

	// 默认进入区域鼠标样式..
	m_enterCursor = Qt::PointingHandCursor;
	m_normalCursor = Qt::ArrowCursor;
}

ProgressBar::HorizontalBar::HorizontalBar(int _currentValue, int _maxValue, QWidget *parent) :
	BaseWidget(_currentValue, _maxValue, parent),m_pen(),
	m_font(), m_isPressed(false), m_cursorChange(false)
{
	setTextColor(QColor("#645454"));
	resize(300, 30);

	// 默认进入区域鼠标样式..
	m_enterCursor = Qt::PointingHandCursor;
	m_normalCursor = Qt::ArrowCursor;
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

	m_pen.setColor(foregroundColor());
	m_pen.setWidth(1);
	painter.setPen(m_pen);
	painter.setBrush(backgroundColor());
	painter.drawRoundedRect(rect, radius, radius);

	painter.setBrush(foregroundColor());
	painter.drawRoundedRect(rectForeground, radius, radius);

	m_pen.setColor(textColor());
	painter.setPen(m_pen);
	painter.setFont(m_font);
	painter.drawText(rectForeground, Qt::AlignRight | Qt::AlignVCenter,
					 QString::number(int(_percentage * 100)) + "% ");

}

void ProgressBar::HorizontalBar::resizeEvent(QResizeEvent * /* e */)
{
	m_font.setPixelSize(height() / 2);
}

void ProgressBar::HorizontalBar::mousePressEvent(QMouseEvent *e)
{
	if (!m_drag || e->button() != Qt::LeftButton)
		return;

	m_isPressed = true;
	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..
}

void ProgressBar::HorizontalBar::mouseReleaseEvent(QMouseEvent *e)
{
	m_isPressed = false;
	if (!m_drag)
		return;

	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..

	emit currentValueChanged(currentValue());
}

void ProgressBar::HorizontalBar::mouseMoveEvent(QMouseEvent *e)
{
	if (!m_isPressed)
		return;
	qreal value = qreal(e->pos().x()) / width();
	setCurrentValue(value);				//	注意value参数类型..
}

void ProgressBar::HorizontalBar::enterEvent(QEvent *)
{
	if (m_cursorChange)
		setCursor(m_enterCursor);
}

void ProgressBar::HorizontalBar::leaveEvent(QEvent *)
{
	if (m_cursorChange)
		setCursor(m_normalCursor);
}

Qt::CursorShape ProgressBar::HorizontalBar::enterCursor() const
{
	return m_enterCursor;
}

void ProgressBar::HorizontalBar::setEnterCursor(const Qt::CursorShape &enterCursor)
{
	m_enterCursor = enterCursor;
}

Qt::CursorShape ProgressBar::HorizontalBar::normalCursor() const
{
	return m_normalCursor;
}

void ProgressBar::HorizontalBar::setNormalCursor(const Qt::CursorShape &normalCursor)
{
	m_normalCursor = normalCursor;
}



QFont ProgressBar::HorizontalBar::font() const
{
	return m_font;
}

void ProgressBar::HorizontalBar::setFont(const QFont &font)
{
	m_font = font;
}
