#include "mainwindow.h"
#include "borderbar.h"
#include "bordersectorbar.h"
#include "circelbar.h"
#include "horizontalbar.h"
#include <QPainter>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), m_pos(0), m_started(false)
{
	resize(500, 450);
	m_borderBar = new BorderBar(0, 100, this);
	m_borderBar->move(50, 100);

	m_borderSectorBar = new BorderSectorBar(this);
	m_borderSectorBar->move(200, 100);

	m_circeBar = new CircelBar(this);
	m_circeBar->move(350, 100);

	m_horizontalBar = new HorizontalBar(this);
	m_horizontalBar->move(100, 300);

	QPushButton *button = new QPushButton("start", this);
	connect(button, SIGNAL(clicked()), this, SLOT(start()));
	button->move(width() - button->width() - 5, height() - button->height() - 5);
	m_timeId = startTimer(50);
}

MainWindow::~MainWindow()
{
	killTimer(m_timeId);
}

void MainWindow::timerEvent(QTimerEvent *)
{
	if (!m_started)
		return;
	if (m_pos >= 100)
		m_pos = 0;
	m_borderBar->setCurrentValue(m_pos += 1);
	m_borderSectorBar->setCurrentValue(m_pos);
	m_circeBar->setCurrentValue(m_pos);
	m_horizontalBar->setCurrentValue(m_pos);
}

void MainWindow::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setBrush(QColor("#5f8aa4"));
	painter.drawRect(rect());
}

void MainWindow::start()
{
	m_started ? m_started = false : m_started = true;
}
