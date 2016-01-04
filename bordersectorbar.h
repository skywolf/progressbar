#ifndef BORDERSECTORBAR_H
#define BORDERSECTORBAR_H

#include "basewidget.h"

class BorderSectorBar : public BaseWidget
{
	Q_OBJECT
public:
	explicit BorderSectorBar(QWidget *parent = 0);
	explicit BorderSectorBar(int _currentValue, int _maxValue, QWidget *parent = 0);
	~BorderSectorBar() {}

protected:
	void paintEvent(QPaintEvent *);
};

#endif // BORDERSECTORBAR_H
