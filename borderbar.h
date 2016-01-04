#ifndef BORDERBAR_H
#define BORDERBAR_H

#include "basewidget.h"

class BorderBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit BorderBar(QWidget *parent = 0);
	explicit BorderBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~BorderBar() {}

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
};

#endif // BORDERBAR_H
