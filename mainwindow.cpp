#include "mainwindow.h"
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), m_pos(0), m_started(false)
{
	resize(600, 400);
	QWidget *widget = new QWidget(this);

	m_borderBar = new ProgressBar::BorderBar(0, 100, this);
	//m_borderBar->move(50, 100);

	m_borderSectorBar = new ProgressBar::BorderSectorBar(this);
	//m_borderSectorBar->move(200, 100);

	m_circeBar = new ProgressBar::CircelBar(this);
	//m_circeBar->move(350, 100);

	m_horizontalBar = new ProgressBar::HorizontalBar(this);
	m_horizontalBar->setFixedHeight(30);			//	最好设置一下这里..
	m_horizontalBar->setDrag(true);					//	设置可拖动..
	m_horizontalBar->setCursorChange(true);			//	进入控件改变鼠标样式..
	connect(m_horizontalBar, SIGNAL(currentValueChanged(int)), this, SLOT(setPos(int)));
	//m_horizontalBar->move(100, 300);

	QHBoxLayout *hlayout = new QHBoxLayout;
	hlayout->addSpacing(50);
	hlayout->addWidget(m_borderBar);
	hlayout->addSpacing(50);
	hlayout->addWidget(m_borderSectorBar);
	hlayout->addSpacing(50);
	hlayout->addWidget(m_circeBar);
	hlayout->addSpacing(20);

	QPushButton *button = new QPushButton("start", this);
	connect(button, SIGNAL(clicked()), this, SLOT(start()));
	button->setStyleSheet("border:0px; color:'lightgray'");
	//button->move(width() - button->width() - 5, height() - button->height() - 5);

	QVBoxLayout *vboxlayout = new QVBoxLayout(widget);
	vboxlayout->addSpacing(50);
	vboxlayout->addLayout(hlayout);
	vboxlayout->addSpacing(50);
	vboxlayout->addWidget(m_horizontalBar);
	vboxlayout->addSpacing(50);
	vboxlayout->addWidget(button, 0, Qt::AlignRight);


	setCentralWidget(widget);
	widget->setLayout(vboxlayout);

	m_timeId = startTimer(100);
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
	//painter.drawRect(rect());
	painter.drawRect(-1, -1, width() + 1, height() + 1);
}

void MainWindow::start()
{
	m_started ? m_started = false : m_started = true;
}

void MainWindow::setPos(int pos)
{
	m_pos = pos;
	m_borderBar->setCurrentValue(m_pos);
	m_borderSectorBar->setCurrentValue(m_pos);
	m_circeBar->setCurrentValue(m_pos);
}

