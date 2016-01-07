/*
 *	可做进度条，也可做滑动条来使用。
 *	进度条： 设置不可拖动,setDrag(false); setCursorChange(false);
 *	滑动条： 设置不可拖动,setDrag(true); setCursorChange(true);
 *
 *	m_cursorChange(鼠标样式是否改变) 默认是： true
 *	m_drag（是否拖拽）默认是： false
 * */

#ifndef HORIZONTALBAR_H
#define HORIZONTALBAR_H

#include "basewidget.h"

#include <QPen>
class QFont;

namespace ProgressBar {
	class HorizontalBar : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit HorizontalBar(QWidget *parent = 0);
		explicit HorizontalBar(int _currentValue, int _maxValue, QWidget *parent = 0);
		~HorizontalBar() {}

		QFont font() const;
		void setFont(const QFont &font);

		inline bool drag() const { return m_drag; }
		inline void setDrag(bool drag) { m_drag = drag; }
		inline bool cursorChange() const { return m_cursorChange; }
		inline void setCursorChange(bool cursorChange) { m_cursorChange = cursorChange; }

		Qt::CursorShape normalCursor() const;
		void setNormalCursor(const Qt::CursorShape &normalCursor);

		Qt::CursorShape enterCursor() const;
		void setEnterCursor(const Qt::CursorShape &enterCursor);

	signals:
		void currentValueChanged(int);

	protected:
		void paintEvent(QPaintEvent *);
		void resizeEvent(QResizeEvent *);

		// 进度条拖动...
		void mousePressEvent(QMouseEvent *e);
		void mouseReleaseEvent(QMouseEvent *e);
		void mouseMoveEvent(QMouseEvent *e);

		// 鼠标样式..
		void enterEvent(QEvent *);
		void leaveEvent(QEvent *);

	private:
		QPen m_pen;
		QFont m_font;

		bool m_drag;		//	控制进度条是否可以拖动.. 默认不可拖动
		bool m_isPressed;	//	鼠标是否按下..

		// 鼠标正常和进入样式..
		bool m_cursorChange;		//	鼠标样式是否改变..
		Qt::CursorShape m_normalCursor;
		Qt::CursorShape m_enterCursor;
	};
}

#endif // HORIZONTALBAR_H
