#include "stdafx.h"
#include "ImplantDesign.h"

ImplantDesign::ImplantDesign(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->InitializeQVTKWidget();
	m_window = vtkSmartPointer<vtkFileOutputWindow>::New();
	m_window->SetInstance(m_window);
	m_window->SetFileName("a.txt");

	m_ImplantBase = vtkSmartPointer<vtkPolyData>::New();
	m_ImplantBaseActor = vtkSmartPointer<vtkActor>::New();

	ui.ModelTableWidget->setColumnCount(1);
	ui.ModelTableWidget->setColumnWidth(0, 330);
	ui.ModelTableWidget->setContentsMargins(0, 0, 0, 0);

	QStringList header;
	header.append("Model List");
	ui.ModelTableWidget->setHorizontalHeaderLabels(header);


	m_ChooseContourWidget = vtkSmartPointer<vtkContourWidget>::New();
	m_ChooseContourWidget->SetInteractor(m_Interactor);
	m_ChooseContourWidgetRep = vtkSmartPointer<vtkOrientedGlyphContourRepresentation>::New();
	m_ContourPointPlacer = vtkSmartPointer<vtkPolygonalSurfacePointPlacer>::New();
	m_LineInterpolateor = vtkSmartPointer<vtkPolygonalSurfaceContourLineInterpolator>::New();
	m_ChooseContourWidgetRep->SetPointPlacer(m_ContourPointPlacer);
	m_ChooseContourWidgetRep->GetLinesProperty()->SetLineWidth(3.0);
	m_ChooseContourWidgetRep->GetLinesProperty()->SetColor(0.1, 0.3, 0.7);
	m_ChooseContourWidgetRep->SetLineInterpolator(m_LineInterpolateor);
	m_ChooseContourWidget->SetRepresentation(m_ChooseContourWidgetRep);

	m_EventConnctor = vtkSmartPointer<vtkEventQtSlotConnect>::New();

	m_Selection = vtkSmartPointer<vtkSelection>::New();
	m_ExtractSelection = vtkSmartPointer<vtkExtractSelection>::New();

	m_PointLocator = vtkSmartPointer<vtkKdTreePointLocator>::New();

	m_ExtractActor = vtkSmartPointer<vtkActor>::New();


	connect(ui.actionLoadProject, SIGNAL(triggered()), this, SLOT(OnOpenProject()));
	connect(ui.ContourChooseButton, SIGNAL(clicked()), this, SLOT(OnContourChoose()));




}

ImplantDesign::~ImplantDesign()
{

}

void ImplantDesign::AddCellInScene(vtkIdType cellid)
{
		auto ids = vtkSmartPointer<vtkIdTypeArray>::New();
		ids->SetNumberOfValues(1);
		ids->InsertNextValue(cellid);
		
		auto selectionNode = vtkSmartPointer<vtkSelectionNode>::New();
		selectionNode->SetFieldType(vtkSelectionNode::CELL);
		selectionNode->SetContentType(vtkSelectionNode::INDICES);
		selectionNode->SetSelectionList(ids);

		auto selection = vtkSmartPointer<vtkSelection>::New();
		selection->AddNode(selectionNode);
		auto extractSelection = vtkSmartPointer<vtkExtractSelection>::New();
		extractSelection->SetInputData(0, m_ModelList.first()->m_data);
		extractSelection->SetInputData(1, selection);
		extractSelection->Update();

		auto selectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
		selectedMapper->SetInputData((vtkDataSet*)extractSelection->GetOutput());


		auto selectedActor = vtkSmartPointer<vtkActor>::New();
		selectedActor->SetMapper(selectedMapper);
		selectedActor->GetProperty()->SetColor(1, 0, 0);
		selectedActor->GetProperty()->SetEdgeVisibility(1);
		selectedActor->GetProperty()->SetEdgeColor(0, 1, 0);
		selectedActor->GetProperty()->SetLineWidth(3);
		selectedActor->GetProperty()->SetRepresentationToSurface();
		m_Renderer->AddActor(selectedActor);
		m_RenderWin->Render();
}

void ImplantDesign::AddPickedCell(vtkPoints* pts)
{
	double seedpoint[3];
	m_ChooseContourWidgetRep->GetContourRepresentationAsPolyData()->GetCenter(seedpoint);
	//auto implicitFunction = vtkSmartPointer<vtkImplicitSelectionLoop>::New();
	//implicitFunction->SetLoop(m_ChooseContourWidgetRep->GetContourRepresentationAsPolyData()->GetPoints());
	//implicitFunction->AutomaticNormalGenerationOn();

	double screenpt[3];
	this->GetDisplayCoordinate(seedpoint, screenpt);
	auto picker = vtkSmartPointer<vtkCellPicker>::New();
	picker->SetTolerance(0);
	picker->Pick(screenpt[0], screenpt[1], screenpt[2], m_Renderer);
	if (picker->GetCellId() != -1)//如果选中cell
	{
		this->AddCellInScene(picker->GetCellId());
		this->FindCell(picker->GetCellId());

	}
	//for (int i = 0; i < pts->GetNumberOfPoints();i++)
	//{
	//	double input[3];
	//	double output[3];
	//	pts->GetPoint(i, input);
	//	

	//	if (implicitFunction->EvaluateFunction(input)>0)
	//	{
	//		continue;
	//	}
	//	this->GetDisplayCoordinate(input,output);

	//	auto picker = vtkSmartPointer<vtkCellPicker>::New();
	//	picker->SetTolerance(0);
	//	picker->Pick(output[0], output[1], output[2], m_Renderer);

	//	if (picker->GetCellId() != -1)//如果选中cell
	//	{
	//		if (cellIDList.indexOf(picker->GetCellId()) == -1)//是否是已经选中过的cell
	//		{
	//			auto ids = vtkSmartPointer<vtkIdTypeArray>::New();
	//			ids->SetNumberOfValues(1);
	//			ids->InsertNextValue(picker->GetCellId());
	//			cellIDList.append(picker->GetCellId());

	//			auto selectionNode = vtkSmartPointer<vtkSelectionNode>::New();
	//			selectionNode->SetFieldType(vtkSelectionNode::CELL);
	//			selectionNode->SetContentType(vtkSelectionNode::INDICES);
	//			selectionNode->SetSelectionList(ids);

	//			auto selection = vtkSmartPointer<vtkSelection>::New();
	//			selection->AddNode(selectionNode);
	//			auto extractSelection = vtkSmartPointer<vtkExtractSelection>::New();
	//			extractSelection->SetInputData(0, m_ModelList.first()->m_data);
	//			extractSelection->SetInputData(1, selection);
	//			extractSelection->Update();

	//			auto selectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	//			selectedMapper->SetInputData((vtkDataSet*)extractSelection->GetOutput());


	//			auto selectedActor = vtkSmartPointer<vtkActor>::New();
	//			selectedActor->SetMapper(selectedMapper);
	//			selectedActor->GetProperty()->SetColor(1, 0, 0);
	//			selectedActor->GetProperty()->SetEdgeVisibility(1);
	//			selectedActor->GetProperty()->SetEdgeColor(0, 1, 0);
	//			selectedActor->GetProperty()->SetLineWidth(3);
	//			selectedActor->GetProperty()->SetRepresentationToSurface();
	//			m_Renderer->AddActor(selectedActor);
	//		}
	//	}
	//}
	
	//m_ExtractSelection->SetInputData(1, m_Selection);
	//auto selectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	//selectedMapper->SetInputData((vtkDataSet*)m_ExtractSelection->GetOutput());

	//if (m_Renderer->GetActors()->IsItemPresent(m_ExtractActor))
	//{
	//	m_Renderer->RemoveActor(m_ExtractActor);
	//}
	//m_ExtractActor = vtkSmartPointer<vtkActor>::New();
	//m_ExtractActor->SetMapper(selectedMapper);
	//m_ExtractActor->GetProperty()->SetColor(1, 0, 0);
	//m_ExtractActor->GetProperty()->SetEdgeVisibility(1);
	//m_ExtractActor->GetProperty()->SetEdgeColor(0, 1, 0);
	//m_ExtractActor->GetProperty()->SetLineWidth(3);
	//m_ExtractActor->GetProperty()->SetRepresentationToSurface();
	//m_Renderer->AddActor(m_ExtractActor);
	//m_RenderWin->Render();
	//m_ExtractSelection->Update();
	m_RenderWin->Render();
}

void ImplantDesign::FindCell(vtkIdType cellid)
{

	auto polydata = vtkSmartPointer<vtkPolyData>::New();
	polydata=m_ModelList.first()->m_data;

	//for each point of the cell, find the neibor cell
	auto pointsIds = vtkSmartPointer<vtkIdList>::New();
	polydata->GetCellPoints(cellid, pointsIds);
	polydata->BuildLinks();
	for (int i = 0; i < pointsIds->GetNumberOfIds(); i++)
	{
		auto neighbors = vtkSmartPointer<vtkIdList>::New();//neibor cell list
		if (i + 1 == pointsIds->GetNumberOfIds())
		{
			polydata->GetCellEdgeNeighbors(cellid, pointsIds->GetId(i), pointsIds->GetId(0), neighbors);
		}
		else
		{
			polydata->GetCellEdgeNeighbors(cellid, pointsIds->GetId(i), pointsIds->GetId(i + 1), neighbors);
		}

		for (int j = 0; j < neighbors->GetNumberOfIds(); j++)
		{

			if (cellIDList.indexOf(neighbors->GetId(j)) != -1)
			{
				continue;
			}
			double* normal = polydata->GetCellData()->GetNormals()->GetTuple(neighbors->GetId(j));
			double dg=vtkMath::DegreesFromRadians(vtkMath::AngleBetweenVectors(normal, normalOfDirection));
			if (dg)
			{
				this->AddCellInScene(neighbors->GetId(j));
				cellIDList.append(neighbors->GetId(j));
				this->FindCell(neighbors->GetId(j));
			}
		}
	}
	


}

void ImplantDesign::GetDisplayCoordinate(double* input, double* out)
{
	m_Renderer->SetWorldPoint(input[0],input[1],input[2],1);
	m_Renderer->WorldToDisplay();
	m_Renderer->GetDisplayPoint(out);
}

void ImplantDesign::GetPlaneSourcePoint(double* input, double* out,vtkPlane* plane)
{
	auto worldpointpicker = vtkSmartPointer<vtkWorldPointPicker>::New();
	worldpointpicker->Pick(input, m_Renderer);
	worldpointpicker->GetPickPosition(out);
	plane->ProjectPoint(out, out);
}

void ImplantDesign::InitializeQVTKWidget()
{
	m_RenderWin = vtkSmartPointer<vtkRenderWindow>::New();
	m_Renderer = vtkSmartPointer<vtkRenderer>::New();
	m_Interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	m_TrackballCamera = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();

	m_Renderer->SetGradientBackground(true);
	m_Renderer->SetBackground(84 / 255.0, 168 / 255.0, 252 / 255.0);
	m_Renderer->SetBackground2(144 / 255.0, 120 / 255.0, 137 / 255.0);

	m_RenderWin->AddRenderer(m_Renderer);
	m_Interactor->SetInteractorStyle(m_TrackballCamera);
	m_Interactor->SetRenderWindow(m_RenderWin);
	ui.ViewWidget->SetRenderWindow(m_RenderWin);
	m_Interactor->Initialize();
}

void ImplantDesign::OnCloseContour()
{

	disconnect(ui.ViewWidget, SIGNAL(changeWidgetState()), this, SLOT(OnChangeWidgetState()));
	m_ChooseContourWidget->CloseLoop();
	auto model = vtkSmartPointer<vtkPolyData>::New();
	model->DeepCopy(m_ModelList.first()->m_data);
	auto temp = vtkSmartPointer<vtkPolyData>::New();
	temp = m_ChooseContourWidgetRep->GetContourRepresentationAsPolyData();	
	temp->BuildLinks();

	QList<vtkIdType> cells2delete;
	QList<vtkIdType> pointList;
	for (int i = 0; i < temp->GetNumberOfPoints();i++)
	{
		auto cells = vtkSmartPointer<vtkIdList>::New();
		vtkIdType pt=m_PointLocator->FindClosestPoint(temp->GetPoints()->GetPoint(i));
		if (pointList.indexOf(pt)==-1)
		{
			pointList.append(pt);		
			model->GetPointCells(pt, cells);
			for (int j = 0; j < cells->GetNumberOfIds(); j++)
			{
				if (cells2delete.indexOf(cells->GetId(j)) == -1)
				{
					cells2delete.append(cells->GetId(j));
					model->DeleteCell(cells->GetId(j));
				}
			}
		}

	}

	model->RemoveDeletedCells();
	auto pointLocator = vtkSmartPointer<vtkPointLocator>::New();
	pointLocator->SetDataSet(model);
	pointLocator->BuildLocator();

	double center[3];
	center[0] = m_Interactor->GetEventPosition()[0];
	center[1] = m_Interactor->GetEventPosition()[1];
	center[2] = 0;
	auto worldpointpicker = vtkSmartPointer<vtkWorldPointPicker>::New();
	worldpointpicker->Pick(center, m_Renderer);
	worldpointpicker->GetPickPosition(center);
	int index = pointLocator->FindClosestPoint(center);
	auto sphere = vtkSmartPointer<vtkSphereWidget>::New();
	sphere->SetCenter(center);
	sphere->SetRadius(2);
	sphere->SetInteractor(m_Interactor);
	sphere->On();
	auto connector = vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
	connector->SetInputData(model);
	connector->AddSeed(index);
	connector->SetExtractionModeToPointSeededRegions();
	connector->Update();

	auto selectedpd = vtkSmartPointer<vtkPolyData>::New();
	selectedpd = connector->GetOutput();
	auto resultpd = vtkSmartPointer<vtkPolyData>::New();
	this->SoftBoundary(selectedpd, resultpd);

	vtkSmartPointer<vtkPolyDataMapper> clipMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	clipMapper->SetInputData(resultpd);
	clipMapper->ScalarVisibilityOff();
	vtkSmartPointer<vtkActor> clipActor =
		vtkSmartPointer<vtkActor>::New();
	clipActor->SetMapper(clipMapper);

	m_Renderer->AddActor(clipActor);
	m_RenderWin->Render();

	return;
	ui.ContourChooseButton->setChecked(false);


	auto m_ContourNodes = vtkSmartPointer<vtkPolyData>::New();
	m_ContourNodes=m_ChooseContourWidgetRep->GetContourRepresentationAsPolyData();
	auto points = vtkSmartPointer<vtkPoints>::New();
	points=m_ContourNodes->GetPoints();
	QString msg;


	
	
	vtkPolygon::ComputeNormal(points, normalOfDirection);
	double focalpoint[3];
	m_Renderer->GetActiveCamera()->GetFocalPoint(focalpoint);
	//焦平面
	
	auto focalplane = vtkSmartPointer<vtkPlane>::New();
	focalplane->SetOrigin(focalpoint);
	focalplane->SetNormal(normalOfDirection);
	
	QList<double> xlist;
	QList<double> ylist;
	
	for (int i = 0; i < points->GetNumberOfPoints();i++)
	{
		double inputpoint[3];
		double outputpoint[3];
		points->GetPoint(i, inputpoint);
		this->GetDisplayCoordinate(inputpoint, outputpoint);
		xlist.append(outputpoint[0]);
		ylist.append(outputpoint[1]);
	}
	double max_x, min_x;
	max_x = xlist.first();
	min_x = xlist.first();
	for each (double var in xlist)
	{
		max_x = vtkMath::Max(max_x, var);
		min_x = vtkMath::Min(min_x, var);
	}
	
	double max_y, min_y;
	max_y = ylist.first();
	min_y = ylist.first();
	for each (double var in ylist)
	{
		max_y = vtkMath::Max(max_y, var);
		min_y = vtkMath::Min(min_y, var);
	}
	
	double firstpoint_display[3] = { min_x, max_y,0 };
	double secondpoint_display[3] = { max_x, min_y,0 };
	double origion_display[3] = { min_x, min_y,0 };

	double firstpoint[3];
	double secondpoint[3];
	double origion[3];
	this->GetPlaneSourcePoint(firstpoint_display, firstpoint,focalplane);
	this->GetPlaneSourcePoint(secondpoint_display, secondpoint,focalplane);
	this->GetPlaneSourcePoint(origion_display, origion, focalplane);

	auto planesource = vtkSmartPointer<vtkPlaneSource>::New();
	planesource->SetOrigin(origion);
	planesource->SetPoint1(firstpoint);
	planesource->SetPoint2(secondpoint);
	planesource->SetResolution(500, 500);
	planesource->Update();
	

	this->AddPickedCell(planesource->GetOutput()->GetPoints());

	this->OnContourChoose();
}

void ImplantDesign::OnContourChoose()
{
	connect(ui.ViewWidget, SIGNAL(changeWidgetState()), this, SLOT(OnChangeWidgetState()));
	pd = vtkSmartPointer<vtkPolyData>::New();
	
	//Create a mapper and actor
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(pd);

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetInterpolationToFlat();

	m_Renderer->AddActor(actor);

	m_ChooseContourWidget = vtkSmartPointer<vtkContourWidget>::New();
	m_ChooseContourWidget->SetInteractor(m_Interactor);
	m_ChooseContourWidget->GetEventTranslator()->RemoveTranslation(vtkCommand::RightButtonPressEvent);

	m_ChooseContourWidgetRep = vtkSmartPointer<vtkOrientedGlyphContourRepresentation>::New();
	m_ContourPointPlacer = vtkSmartPointer<vtkPolygonalSurfacePointPlacer>::New();
	m_ContourPointPlacer->AddProp(m_ModelList.first()->m_actor);
	m_ContourPointPlacer->GetPolys()->AddItem(pd);
	
	m_ChooseContourWidgetRep->SetPointPlacer(m_ContourPointPlacer);
	m_ChooseContourWidgetRep->GetLinesProperty()->SetLineWidth(3.0);
	m_ChooseContourWidgetRep->GetLinesProperty()->SetColor(0.1, 0.3, 0.7);
	m_ChooseContourWidgetRep->SetLineInterpolator(m_LineInterpolateor);
	m_ChooseContourWidget->SetRepresentation(m_ChooseContourWidgetRep);

	if (ui.ContourChooseButton->isChecked())
	{
		m_ChooseContourWidget->On();
		ui.SingleChooseButton->setDisabled(true);
		m_EventConnctor->Connect(m_ChooseContourWidget->GetInteractor(), vtkCommand::RightButtonPressEvent, this, SLOT(OnCloseContour()));
	}
	else
	{
		ui.SingleChooseButton->setDisabled(false);
		m_ChooseContourWidget->Off();
		m_EventConnctor->Disconnect(m_ChooseContourWidget->GetInteractor(), vtkCommand::RightButtonPressEvent, this, SLOT(OnCloseContour()));
	}
	m_RenderWin->Render();
}

void ImplantDesign::OnDeleteModel(ModelControlWidgetItem* item)
{
	int index = m_ModelList.indexOf(item);
	m_ModelList.removeAt(index);
	ui.ModelTableWidget->removeRow(index);
}

void ImplantDesign::OnOpenProject()
{
	TCHAR path[255];
	SHGetSpecialFolderPath(0, path, CSIDL_DESKTOP, 0);
	QString desktop;
	#ifdef UNICODE   
		desktop = QString::fromUtf16((ushort*)path);
	#else   
		desktop = QString::fromLocal8Bit(path);
	#endif
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open Project"), desktop, tr("Project Files (*.stl)"));
	if (!fileName.isEmpty())
	{
		auto stlReader = vtkSmartPointer<vtkSTLReader>::New();
		stlReader->SetFileName(fileName.toLocal8Bit());
		stlReader->Update();
		
		m_PointLocator->SetDataSet(stlReader->GetOutput());
		m_PointLocator->BuildLocator();
		ModelControlWidgetItem* item = new ModelControlWidgetItem(this, m_Renderer);
		item->SetInputData(stlReader->GetOutput());
		m_ModelList.append(item);
		ui.ModelTableWidget->setRowCount(m_ModelList.size());
		ui.ModelTableWidget->setCellWidget(m_ModelList.size() - 1, 0, item);
		connect(item, SIGNAL(delete_signal(ModelControlWidgetItem*)), this, SLOT(OnDeleteModel(ModelControlWidgetItem*)));

		m_ExtractSelection->SetInputData(0, stlReader->GetOutput());



	}
}

void ImplantDesign::OnSingleChoose()
{

}

void ImplantDesign::OnChangeWidgetState()
{
	if (m_ChooseContourWidget->GetWidgetState() == vtkContourWidget::Define)
	{
		m_ChooseContourWidget->SetWidgetState(vtkContourWidget::Manipulate);
		m_EventConnctor->Disconnect(m_ChooseContourWidget->GetInteractor(), vtkCommand::RightButtonPressEvent, this, SLOT(OnCloseContour()));
	}
	else
	{
		m_ChooseContourWidget->SetWidgetState(vtkContourWidget::Define);
		m_EventConnctor->Connect(m_ChooseContourWidget->GetInteractor(), vtkCommand::RightButtonPressEvent, this, SLOT(OnCloseContour()));
	}
}

void ImplantDesign::SoftBoundary(vtkPolyData* input, vtkPolyData* output)
{
	auto inputpd = vtkSmartPointer<vtkPolyData>::New();
	inputpd = input;

	vtkSmartPointer<vtkImplicitModeller> implicitModeller =
		vtkSmartPointer<vtkImplicitModeller>::New();
	implicitModeller->SetSampleDimensions(50, 50, 50);
	implicitModeller->SetInputData(inputpd);
	implicitModeller->SetAdjustBounds(1);
	implicitModeller->SetAdjustDistance(.1);
	implicitModeller->SetMaximumDistance(2 + 1);
	implicitModeller->SetProcessModeToPerVoxel();
	implicitModeller->SetCapping(1);
	implicitModeller->SetCapValue(2 + 1);
	implicitModeller->Update();

	// Create the 0 isosurface
	vtkSmartPointer<vtkContourFilter> contourFilter =
		vtkSmartPointer<vtkContourFilter>::New();
	contourFilter->SetInputConnection(implicitModeller->GetOutputPort());
	contourFilter->SetValue(0, 2);
	contourFilter->Update();

	vtkSmartPointer<vtkPolyDataConnectivityFilter> connectivityFilter =
		vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
	connectivityFilter->SetInputConnection(contourFilter->GetOutputPort());
	connectivityFilter->SetExtractionModeToLargestRegion();
	connectivityFilter->Update();

	if (!connectivityFilter->GetOutput()->GetNumberOfPoints())
	{
		return ;
	}

	vtkSmartPointer<vtkTriangleFilter> TriangleFilter =
		vtkSmartPointer<vtkTriangleFilter>::New();
	TriangleFilter->SetInputConnection(connectivityFilter->GetOutputPort());
	TriangleFilter->Update();

	int numberOfSubdivisions = 2;
	vtkSmartPointer<vtkLoopSubdivisionFilter> subdivisionFilter =
		vtkSmartPointer<vtkLoopSubdivisionFilter>::New();
	subdivisionFilter->SetNumberOfSubdivisions(numberOfSubdivisions);
	subdivisionFilter->SetInputConnection(TriangleFilter->GetOutputPort());
	subdivisionFilter->Update();

	vtkSmartPointer<vtkSmoothPolyDataFilter> smoothFilter =
		vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
	smoothFilter->SetInputConnection(subdivisionFilter->GetOutputPort());
	smoothFilter->SetNumberOfIterations(50);
	smoothFilter->SetRelaxationFactor(.1);    //small relaxation factors and large numbers of iterations are more stable
	smoothFilter->BoundarySmoothingOn();
	smoothFilter->Update();
	





	int operation = 2;
	auto intersection = vtkSmartPointer<vtkIntersectionPolyDataFilter>::New();
	intersection->SetInputData(0, m_ModelList.first()->m_data);
	intersection->SetInputData(1, smoothFilter->GetOutput());
	intersection->Update();



	auto distance =vtkSmartPointer<vtkDistancePolyDataFilter>::New();
	distance->SetInputData(0, intersection->GetOutput(1));
	distance->SetInputData(1, intersection->GetOutput(2));
	distance->Update();


	auto thresh1 =vtkSmartPointer<vtkThreshold>::New();
	thresh1->AllScalarsOn();
	thresh1->SetInputArrayToProcess(0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_CELLS, "Distance");
	thresh1->SetInputConnection(distance->GetOutputPort(0));
	thresh1->ThresholdByUpper(0.0);

	auto thresh2 =vtkSmartPointer<vtkThreshold>::New();
	thresh2->AllScalarsOn();
	thresh2->SetInputArrayToProcess(0, 0, 0, vtkDataObject::FIELD_ASSOCIATION_CELLS, "Distance");
	thresh2->SetInputData(distance->GetSecondDistanceOutput());
	thresh2->ThresholdByUpper(0.0);



	auto surface1 =vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
	surface1->SetInputConnection(thresh1->GetOutputPort());

	auto surface2 =vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
	surface2->SetInputConnection(thresh2->GetOutputPort());


	auto reverseSense =vtkSmartPointer<vtkReverseSense>::New();
	reverseSense->SetInputConnection(surface1->GetOutputPort());
	reverseSense->ReverseCellsOn();
	reverseSense->ReverseNormalsOn();
	

	auto appender =vtkSmartPointer<vtkAppendPolyData>::New();
	appender->SetInputConnection(surface2->GetOutputPort());
	appender->AddInputConnection(surface1->GetOutputPort());
	appender->Update();
	auto clean = vtkSmartPointer<vtkCleanPolyData>::New();
	clean->SetInputData(appender->GetOutput());
	clean->Update();
	auto connector = vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
	connector->SetInputData(clean->GetOutput());
	connector->SetExtractionModeToLargestRegion();
	connector->ColorRegionsOn();
	connector->Update();
	output->DeepCopy(connector->GetOutput());


	return;

	auto featureEdge = vtkSmartPointer<vtkFeatureEdges>::New();
	featureEdge->SetInputData(inputpd);
	featureEdge->BoundaryEdgesOn();
	featureEdge->FeatureEdgesOff();
	featureEdge->ManifoldEdgesOff();
	featureEdge->NonManifoldEdgesOff();
	featureEdge->Update();
	output->DeepCopy(featureEdge->GetOutput());
	
	auto pointLocator = vtkSmartPointer<vtkKdTreePointLocator>::New();
	pointLocator->SetDataSet(inputpd);
	pointLocator->BuildLocator();

	auto boundarypd = vtkSmartPointer<vtkPolyData>::New();
	boundarypd = featureEdge->GetOutput();
	
	auto boundarypts = vtkSmartPointer<vtkPoints>::New();
	boundarypts = boundarypd->GetPoints();
	int numofpts = boundarypts->GetNumberOfPoints();
	QList<vtkIdType> idList;
	for (int i = 0; i < numofpts;i++)
	{
		vtkIdType id=pointLocator->FindClosestPoint(boundarypts->GetPoint(i));
		idList.append(id);
	}

	auto reducedpd = vtkSmartPointer<vtkPolyData>::New();

	auto reducedpts = vtkSmartPointer<vtkPoints>::New();
	reducedpts->Initialize();

	int numofline = 0;
	auto cellArray = vtkSmartPointer<vtkCellArray>::New();
	cellArray->Initialize();
	auto cell = vtkSmartPointer<vtkIdList>::New();
	for (int i = 0; i < numofpts+5;i=i+5)
	{
		double pt[3];
		if (i>numofpts)
		{
			boundarypts->GetPoint(0, pt);
		}
		else
		{
			boundarypts->GetPoint(i, pt);
		}cell->InsertNextId(numofline);
		numofline++;
	}
	cellArray->InsertNextCell(cell);
	reducedpd->SetPoints(reducedpts);
	reducedpd->SetPolys(cellArray);

	auto cardinalSpline = vtkSmartPointer<vtkCardinalSpline>::New();
	cardinalSpline->SetLeftConstraint(2);
	cardinalSpline->SetRightConstraint(2);
	cardinalSpline->SetLeftValue(0);
	cardinalSpline->SetRightValue(0);

	auto spline = vtkSmartPointer<vtkSplineFilter>::New();
	spline->SetSpline(cardinalSpline);
	spline->SetInputData(reducedpd);
	spline->SetNumberOfSubdivisions(numofpts*50);
	spline->SetSubdivideToSpecified();
	spline->Update();
	output->DeepCopy(featureEdge->GetOutput());
	//output = reducedpd;
}

