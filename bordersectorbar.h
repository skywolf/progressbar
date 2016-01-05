#ifndef BORDERSECTORBAR_H
#define BORDERSECTORBAR_H

#include "basewidget.h"
#include <QPen>

namespace ProgressBar {
	class BorderSectorBar : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit BorderSectorBar(QWidget *parent = 0);
		explicit BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent = 0);
		~BorderSectorBar() {}

		QFont font() const;
		void setFont(const QFont &font);

	protected:
		void paintEvent(QPaintEvent *);
		void resizeEvent(QResizeEvent *);

	private:
		QPen m_pen;
		QFont m_font;
	};
}

#endif // BORDERSECTORBAR_H
