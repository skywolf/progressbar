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

	protected:
		void paintEvent(QPaintEvent *);
		void resizeEvent(QResizeEvent *);

	private:
		QPen pen;
		QFont m_font;
	};
}

#endif // HORIZONTALBAR_H
