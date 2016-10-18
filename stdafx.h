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
#include <vtkAppendPolyData.h>
#include <vtkBezierContourLineInterpolator.h>
#include <vtkBooleanOperationPolyDataFilter.h>
#include <vtkDataArray.h>
#include <vtkCamera.h>
#include <vtkCardinalSpline.h>
#include <vtkCellData.h>
#include <vtkCellPicker.h>

#include <vtkCleanPolyData.h>
#include <vtkClipPolyData.h>

#include <vtkContourFilter.h>
#include <vtkContourWidget.h>
#include <vtkContourRepresentation.h>
#include <vtkDataSet.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkDistancePolyDataFilter.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkExtractSelection.h>
#include <vtkFeatureEdges.h>
#include <vtkFileOutputWindow.h>
#include <vtkFocalPlanePointPlacer.h>
#include <vtkIdTypeArray.h>
#include <vtkImplicitFunction.h>
#include <vtkImplicitModeller.h>
#include <vtkImplicitSelectionLoop.h>

#include <vtkInteractorStyle.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkIntersectionPolyDataFilter.h>
#include <vtkKdTreePointLocator.h>
#include <vtkLoopSubdivisionFilter.h>
#include <vtkMath.h>
#include <vtkMinimalStandardRandomSequence.h>


#include <vtkOrientedGlyphContourRepresentation.h>
#include <vtkPlane.h>
#include <vtkPlaneSource.h>
#include <vtkWorldPointPicker.h>
#include <vtkPoints.h>
#include <vtkPointLocator.h>
#include <vtkPolyData.h>
#include <vtkPolyDataCollection.h>
#include <vtkPolyDataConnectivityFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <vtkPolygon.h>
#include <vtkPolygonalSurfacePointPlacer.h>
#include <vtkPolygonalSurfaceContourLineInterpolator.h>
#include <vtkProperty.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkReverseSense.h>
#include <vtkSelection.h>
#include <vtkSelectionNode.h>
#include <vtkSelectPolyData.h>
#include <vtkSphereWidget.h>
#include <vtkSplineFilter.h>
#include <vtkSmartPointer.h>
#include <vtkSmoothPolyDataFilter.h>

#include <vtkSTLReader.h>
#include <vtkSTLWriter.h>
#include <vtkThreshold.h>
#include <vtkTriangleFilter.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

#include <vtkWidgetEventTranslator.h>