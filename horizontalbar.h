#ifndef HORIZONTALBAR_H
#define HORIZONTALBAR_H

#include "basewidget.h"

class HorizontalBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit HorizontalBar(QWidget *parent = 0);
	explicit HorizontalBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~HorizontalBar() {}

protected:
	void paintEvent(QPaintEvent *);
};

#endif // HORIZONTALBAR_H
