#ifndef IMPLANTDESIGN_H
#define IMPLANTDESIGN_H

#include <QtWidgets/QMainWindow>
#include "ui_ImplantDesign.h"

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingOpenGL2);
#include "ModelControlWidgetItem.h"
class ImplantDesign : public QMainWindow
{
	Q_OBJECT

public:
	ImplantDesign(QWidget *parent = 0);
	~ImplantDesign();

private:
	Ui::ImplantDesignClass ui;

	vtkSmartPointer<vtkRenderWindow> m_RenderWin;
	vtkSmartPointer<vtkRenderWindowInteractor> m_Interactor;
	vtkSmartPointer<vtkRenderer> m_Renderer;
	vtkSmartPointer<vtkInteractorStyleTrackballCamera> m_TrackballCamera;


	vtkSmartPointer<vtkPolyData> m_ImplantBase;
	vtkSmartPointer<vtkActor> m_ImplantBaseActor;
	QList<ModelControlWidgetItem*> m_ModelList;
	vtkSmartPointer<vtkContourWidget> m_ChooseContourWidget;
	vtkSmartPointer<vtkOrientedGlyphContourRepresentation> m_ChooseContourWidgetRep;
	vtkSmartPointer<vtkFocalPlanePointPlacer> m_ContourPointPlacer;
	vtkSmartPointer<vtkBezierContourLineInterpolator> m_LineInterpolateor;
	double normalOfDirection[3];
	QList<int> cellIDList;
	vtkSmartPointer<vtkExtractSelection> m_ExtractSelection;
	vtkSmartPointer<vtkSelection> m_Selection;
	vtkSmartPointer<vtkActor> m_ExtractActor;
	vtkSmartPointer<vtkEventQtSlotConnect> m_EventConnctor;
	void InitializeQVTKWidget();
	void GetDisplayCoordinate(double* input, double* out);
	void GetPlaneSourcePoint(double* input, double* out,vtkPlane* plane);
	void AddPickedCell(vtkPoints* pts);
	void FindCell(vtkIdType cellid);
	void AddCellInScene(vtkIdType cellid);

protected slots:

	void OnDeleteModel(ModelControlWidgetItem* item);
	void OnOpenProject();
	void OnContourChoose();
	void OnSingleChoose();
	void OnCloseContour();

};

#endif // IMPLANTDESIGN_H
