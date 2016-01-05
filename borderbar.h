#ifndef BORDERBAR_H
#define BORDERBAR_H

#include "basewidget.h"
#include <QPen>

namespace ProgressBar {
	class BorderBar : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit BorderBar(QWidget *parent = 0);
		explicit BorderBar(int _currentValue, int _maxValue, QWidget *parent = 0);
		~BorderBar() {}

		QFont font() const;
		void setFont(const QFont &font);

	protected:
		void paintEvent(QPaintEvent *);
		void resizeEvent(QResizeEvent *);

	private:
		QFont m_font;
		QPen m_pen;
	};
}

#endif // BORDERBAR_H
