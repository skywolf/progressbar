#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "borderbar.h"
#include "bordersectorbar.h"
#include "circelbar.h"
#include "horizontalbar.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void timerEvent(QTimerEvent *);
	void paintEvent(QPaintEvent *);

private slots:
	void start();

private:
	int m_pos;
	bool m_started;

	ProgressBar::BorderBar *m_borderBar;
	ProgressBar::BorderSectorBar *m_borderSectorBar;
	ProgressBar::CircelBar *m_circeBar;
	ProgressBar::HorizontalBar *m_horizontalBar;

	int m_timeId;
};

#endif // MAINWINDOW_H
