#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class BorderBar;
class BorderSectorBar;
class CircelBar;
class HorizontalBar;

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

	BorderBar *m_borderBar;
	BorderSectorBar *m_borderSectorBar;
	CircelBar *m_circeBar;
	HorizontalBar *m_horizontalBar;

	int m_timeId;
};

#endif // MAINWINDOW_H
