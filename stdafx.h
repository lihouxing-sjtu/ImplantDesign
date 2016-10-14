#include <shlobj.h>


#include <QtWidgets>








//first parameter is the title of the window, second is the message
#define ShowError(title,message)\
{\
	QMessageBox error;\
	error.setWindowTitle(title);\
	error.setText(message);\
	error.exec();\
}


//vtk include

#include <vtkActor.h>
#include <vtkBezierContourLineInterpolator.h>
#include <vtkDataArray.h>
#include <vtkCamera.h>
#include <vtkCellData.h>
#include <vtkCellPicker.h>


#include <vtkClipPolyData.h>
#include <vtkContourWidget.h>
#include <vtkContourRepresentation.h>
#include <vtkDataSet.h>
#include <vtkDataSetMapper.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkExtractSelection.h>
#include <vtkFocalPlanePointPlacer.h>

#include <vtkMath.h>
#include <vtkMinimalStandardRandomSequence.h>
#include <vtkIdTypeArray.h>
#include <vtkImplicitFunction.h>
#include <vtkImplicitSelectionLoop.h>

#include <vtkInteractorStyle.h>
#include <vtkInteractorStyleTrackballCamera.h>

#include <vtkOrientedGlyphContourRepresentation.h>
#include <vtkPlane.h>
#include <vtkPlaneSource.h>
#include <vtkWorldPointPicker.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolygon.h>
#include <vtkProperty.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkSelectPolyData.h>

#include <vtkSmartPointer.h>

#include <vtkSTLReader.h>
#include <vtkSTLWriter.h>
#include <vtkTriangleFilter.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

#include <vtkWidgetEventTranslator.h>