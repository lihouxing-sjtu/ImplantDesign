#include "stdafx.h"
#include "QCustomVTKWidget.h"

QCustomVTKWidget::QCustomVTKWidget(QWidget *)
{
	qpressflag = false;
}

QCustomVTKWidget::~QCustomVTKWidget(void)
{
}

void QCustomVTKWidget::keyPressEvent(QKeyEvent* e)
{
	QVTKWidget::keyPressEvent(e);
	if (e->key() ==Qt::Key_Q);
	{
		qpressflag = true;
	}
}

void QCustomVTKWidget::keyReleaseEvent(QKeyEvent* e)
{
	QVTKWidget::keyReleaseEvent(e);
	if (e->key() == Qt::Key_Q);
	{
		qpressflag = false;
	}
	if (e->key()==Qt::Key_Space)
	{
		emit changeWidgetState();
	}
}

void QCustomVTKWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	if(event->button()==Qt::LeftButton)
	{
		emit doubleClicked(this);
	}
}

void QCustomVTKWidget::mouseMoveEvent(QMouseEvent* event)
{
	QVTKWidget::mouseMoveEvent(event);
	if (qpressflag)
	{
		if (event->button()==Qt::LeftButton)
		{
			emit pickCell();
		}
	}
}

void QCustomVTKWidget::mousePressEvent(QMouseEvent* event)
{
	QVTKWidget::mousePressEvent(event);
	if (event->button()==Qt::RightButton)
	{
		double position[3] = { 0, 0, 0 };
		position[0]=this->GetRenderWindow()->GetInteractor()->GetEventPosition()[0];
		position[1] = this->GetRenderWindow()->GetInteractor()->GetEventPosition()[1];
		emit rightClicked(this, position);
	}
}
