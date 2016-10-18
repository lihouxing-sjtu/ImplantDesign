#ifndef QCUSTOMVTKWIDGET_H
#define QCUSTOMVTKWIDGET_H

#include "stdafx.h"
#include <QtGui>
#include "QVTKWidget.h"

class QCustomVTKWidget :
	public QVTKWidget
{
	Q_OBJECT

public:
	QCustomVTKWidget(QWidget *);
public:
	~QCustomVTKWidget(void);

protected:
	bool qpressflag;
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent* event);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);
	void mouseMoveEvent(QMouseEvent* event);
signals:
	void doubleClicked(QCustomVTKWidget*);
	void rightClicked(QCustomVTKWidget*, double*);
	void pickCell();
	void changeWidgetState();
};

#endif 