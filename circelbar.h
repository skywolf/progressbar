#ifndef CIRCELBAR_H
#define CIRCELBAR_H

#include "basewidget.h"

class CircelBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit CircelBar(QWidget *parent = 0);
	explicit CircelBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~CircelBar() {}

protected:
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
};

#endif // CIRCELBAR_H
