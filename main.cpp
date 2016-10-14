#include "stdafx.h"
#include "ImplantDesign.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImplantDesign w;
	w.showMaximized();

	return a.exec();
}
