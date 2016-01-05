#ifndef CIRCELBAR_H
#define CIRCELBAR_H

#include "basewidget.h"
#include <QPen>

namespace ProgressBar {
	class CircelBar : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit CircelBar(QWidget *parent = 0);
		explicit CircelBar(int _currentValue, int _maxValue, QWidget *parent = 0);
		~CircelBar() {}

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

#endif // CIRCELBAR_H
