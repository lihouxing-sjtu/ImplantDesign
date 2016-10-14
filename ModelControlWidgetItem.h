#ifndef MODELCONTROLWIDGETITEM_H
#define MODELCONTROLWIDGETITEM_H

#include <QWidget>
#include "ui_ModelControlWidgetItem.h"
enum Category
{
	CPatientUperMarker,
	CPatientDownMarker,
	CProsthesisUperMarker,
	CProsthesisDownMarker,
	CProsthesisUp,
	CProsthesisDown
};
class ModelControlWidgetItem : public QWidget
{
	Q_OBJECT


public:
	ModelControlWidgetItem(QWidget *parent = 0,vtkRenderer *render=nullptr );
	~ModelControlWidgetItem();

	 void GetInputData(vtkPolyData* output);
	 vtkPolyData* GetInputData();
	void SetInputData(vtkPolyData*);
	void SetColor(double* color);
	vtkSmartPointer<vtkActor> m_actor;
	vtkSmartPointer<vtkPolyData> m_data;
	int modelCategory;
private:
	Ui::ModelControlWidgetItem ui;
	vtkSmartPointer<vtkRenderer> m_render;
	vtkSmartPointer<vtkPolyDataMapper> m_mapper;
	
	QAction* PatientUperMarker;
	QAction* PatientDownMarker;
	QAction* ProsthesisUperMarker;
	QAction* ProsthesisDownMarker;
	QAction* ProsthesisUp;
	QAction* ProsthesisDown;


protected slots:
	void OnDelete();
	void OnOpacity(int);
	void OnVisibilityOff();
	void OnSetColor();
	void OnSaveData();

	void OnSetPatientUperMarker();
	void OnSetPatientDownMarker();
	void OnSetProsthesisUperMarker();
	void OnSetProsthesisDownMarker();
	void OnSetProsthesisUp();
	void OnSetProsthesisDown();

signals:
	void delete_signal(ModelControlWidgetItem*);
};

#endif // MODELCONTROLWIDGETITEM_H
