#include "StdAfx.h"
#include "ModelControlWidgetItem.h"

ModelControlWidgetItem::ModelControlWidgetItem(QWidget *parent,vtkRenderer* renderer)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_render=vtkSmartPointer<vtkRenderer>::New();
	m_render=renderer;



	PatientUperMarker = new QAction("PatientUperMarker", this);
	PatientUperMarker->setCheckable(true);
	PatientDownMarker = new QAction("PatientDownMarker", this);
	PatientDownMarker->setCheckable(true);
	ProsthesisUperMarker = new QAction("ProsthesisUperMarker", this);
	ProsthesisUperMarker->setCheckable(true);
	ProsthesisDownMarker = new QAction("ProsthesisDownMarker", this);
	ProsthesisDownMarker->setCheckable(true);

	ProsthesisUp = new QAction("ProsthesisUp", this);
	ProsthesisUp->setCheckable(true);
	ProsthesisDown = new QAction("ProsthesisDown", this);
	ProsthesisDown->setCheckable(true);

	QMenu * menuList = new QMenu(this);
	menuList->addAction(PatientUperMarker);
	menuList->addAction(PatientDownMarker);
	menuList->addAction(ProsthesisUperMarker);
	menuList->addAction(ProsthesisDownMarker);
	menuList->addAction(ProsthesisUp);
	menuList->addAction(ProsthesisDown);

	ui.CategoryButton->setMenu(menuList);


	connect(ui.opacSpin,SIGNAL(valueChanged(int)),this,SLOT(OnOpacity(int)));
	connect(ui.ColorPickerButton,SIGNAL(clicked()),this,SLOT(OnSetColor()));
	connect(ui.DeleteButton,SIGNAL(clicked()),this,SLOT(OnDelete()));
	connect(ui.SaveButton,SIGNAL(clicked()),this,SLOT(OnSaveData()));

	connect(PatientUperMarker, SIGNAL(triggered()), this, SLOT(OnSetPatientUperMarker()));
	connect(PatientDownMarker, SIGNAL(triggered()), this, SLOT(OnSetPatientDownMarker()));
	connect(ProsthesisUperMarker, SIGNAL(triggered()), this, SLOT(OnSetProsthesisUperMarker()));
	connect(ProsthesisDownMarker, SIGNAL(triggered()), this, SLOT(OnSetProsthesisDownMarker()));
	connect(ProsthesisUp, SIGNAL(triggered()), this, SLOT(OnSetProsthesisUp()));
	connect(ProsthesisDown, SIGNAL(triggered()), this, SLOT(OnSetProsthesisDown()));
}

ModelControlWidgetItem::~ModelControlWidgetItem()
{

}


vtkPolyData* ModelControlWidgetItem::GetInputData()
{
	return m_data;
}

void ModelControlWidgetItem::GetInputData(vtkPolyData* output)
{
	output->DeepCopy(m_data);
}

void ModelControlWidgetItem::OnOpacity(int opacity)
{
	m_actor->GetProperty()->SetOpacity(opacity/100.0);
	m_render->GetRenderWindow()->Render();
}
void ModelControlWidgetItem::OnSaveData()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save STL Model"),NULL, tr("*.stl"));

	if (fileName.isEmpty())
		return;

	auto transform=vtkSmartPointer<vtkTransform>::New();
	transform->SetMatrix(m_actor->GetMatrix());
	transform->Update();

	auto stlTransform=vtkSmartPointer<vtkTransformPolyDataFilter>::New();
	stlTransform->AddInputData(m_data);
	stlTransform->SetTransform(transform);
	stlTransform->Update();

	auto stlTriangles=vtkSmartPointer<vtkTriangleFilter>::New();
	
	stlTriangles->SetInputData(stlTransform->GetOutput());
	stlTriangles->Update();

	auto polyWriter = vtkSmartPointer<vtkSTLWriter>::New();
	polyWriter->SetFileName(qPrintable(fileName));
	polyWriter->SetFileTypeToBinary();
	polyWriter->SetInputData(stlTriangles->GetOutput());
	polyWriter->Write();
	ShowError("Save", "Done!");
}
void ModelControlWidgetItem::OnSetColor()
{
	QColor initalColor;
	initalColor.setRed(m_actor->GetProperty()->GetColor()[0] * 255);
	initalColor.setGreen(m_actor->GetProperty()->GetColor()[1] * 255);
	initalColor.setBlue(m_actor->GetProperty()->GetColor()[2] * 255);
	QColor qcolor = QColorDialog::getColor(initalColor, this);
	if (!qcolor.isValid())
	{
		return;
	}
	double color[3];
	color[0] = qcolor.red() / 255.0;
	color[1] = qcolor.green() / 255.0;
	color[2] = qcolor.blue() / 255.0;

	m_actor->GetProperty()->SetColor(color);
	QString backGroudColor;
	QString num;
	backGroudColor = "background-color: rgb(" + num.setNum(qcolor.red()) + ", " + num.setNum(qcolor.green()) + ", " + num.setNum(qcolor.blue()) + ")";
	ui.ColorPickerButton->setStyleSheet(backGroudColor);
	m_render->GetRenderWindow()->Render();
}
void ModelControlWidgetItem::OnSetPatientDownMarker()
{
	ui.CategoryButton->setText("Pa-DMarker");
	modelCategory = CPatientDownMarker;

	PatientDownMarker->setChecked(true);
	PatientUperMarker->setChecked(false);
	ProsthesisUperMarker->setChecked(false);
	ProsthesisDownMarker->setChecked(false);
	ProsthesisUp->setChecked(false);
	ProsthesisDown->setChecked(false);
}
void ModelControlWidgetItem::OnSetPatientUperMarker()
{
	ui.CategoryButton->setText("Pa-UMarker");
	modelCategory = CPatientUperMarker;

	PatientDownMarker->setChecked(false);
	PatientUperMarker->setChecked(true);
	ProsthesisUperMarker->setChecked(false);
	ProsthesisDownMarker->setChecked(false);
	ProsthesisUp->setChecked(false);
	ProsthesisDown->setChecked(false);
}

void ModelControlWidgetItem::OnSetProsthesisDown()
{
	ui.CategoryButton->setText("Pr-D");
	modelCategory = CProsthesisDown;

	PatientDownMarker->setChecked(false);
	PatientUperMarker->setChecked(false);
	ProsthesisUperMarker->setChecked(false);
	ProsthesisDownMarker->setChecked(false);
	ProsthesisUp->setChecked(false);
	ProsthesisDown->setChecked(true);
}

void ModelControlWidgetItem::OnSetProsthesisDownMarker()
{
	ui.CategoryButton->setText("Pr-DMarker");
	modelCategory = CProsthesisDownMarker;

	PatientDownMarker->setChecked(false);
	PatientUperMarker->setChecked(false);
	ProsthesisUperMarker->setChecked(false);
	ProsthesisDownMarker->setChecked(true);
	ProsthesisUp->setChecked(false);
	ProsthesisDown->setChecked(false);
}

void ModelControlWidgetItem::OnSetProsthesisUp()
{
	ui.CategoryButton->setText("Pr-U");
	modelCategory = CProsthesisUp;

	PatientDownMarker->setChecked(false);
	PatientUperMarker->setChecked(false);
	ProsthesisUperMarker->setChecked(false);
	ProsthesisDownMarker->setChecked(false);
	ProsthesisUp->setChecked(true);
	ProsthesisDown->setChecked(false);
}


void ModelControlWidgetItem::OnSetProsthesisUperMarker()
{
	ui.CategoryButton->setText("Pr-UMarker");
	modelCategory = CProsthesisUperMarker;

	PatientDownMarker->setChecked(false);
	PatientUperMarker->setChecked(false);
	ProsthesisUperMarker->setChecked(true);
	ProsthesisDownMarker->setChecked(false);
	ProsthesisUp->setChecked(false);
	ProsthesisDown->setChecked(false);
}
void ModelControlWidgetItem::OnVisibilityOff()
{
	if (ui.VisibilityButton->isChecked())
	{
		m_actor->SetVisibility(0);
		m_render->GetRenderWindow()->Render();
		QIcon icon;	
		icon.addFile(QStringLiteral(":/ImplantDesign/Resources/AnnotationInvisible.png"), QSize(), QIcon::Normal, QIcon::Off);
		
		ui.VisibilityButton->setIcon(icon);
		return;
	}
	m_actor->SetVisibility(1);
	QIcon icon;
	icon.addFile(QStringLiteral(":/ImplantDesign/Resources/AnnotationVisibility.png"), QSize(), QIcon::Normal, QIcon::Off);
	ui.VisibilityButton->setIcon(icon);
	m_render->GetRenderWindow()->Render();

}

void ModelControlWidgetItem::OnDelete()
{
	if(QMessageBox::information(this,tr("Delete Model"),tr("Are sure to delete to model"),QMessageBox::Ok|QMessageBox::Cancel)==QMessageBox::Ok)
	{
		m_render->RemoveActor(m_actor);
		m_render->GetRenderWindow()->Render();
		emit delete_signal(this);
	}
	
}

void ModelControlWidgetItem::SetColor(double* color1)
{
	m_actor->GetProperty()->SetColor(color1);
	QColor color;
	color.setRed(color1[0] * 255);
	color.setGreen(color1[1] * 255);
	color.setBlue(color1[2] * 255);
	QString backGroudColor;
	QString num;
	backGroudColor = "background-color: rgb(" + num.setNum(color.red()) + ", " + num.setNum(color.green()) + ", " + num.setNum(color.blue()) + ")";
	ui.ColorPickerButton->setStyleSheet(backGroudColor);
	m_render->GetRenderWindow()->Render();
	m_render->ResetCamera();
}

void ModelControlWidgetItem::SetInputData(vtkPolyData* input)
{
	m_data=vtkSmartPointer<vtkPolyData>::New();
	m_data->DeepCopy(input);
	m_mapper=vtkSmartPointer<vtkPolyDataMapper>::New();
	m_mapper->SetInputData(m_data);
	m_mapper->SetScalarVisibility(0);
	m_actor=vtkSmartPointer<vtkActor>::New();
	m_actor->SetMapper(m_mapper);

	//auto backfaceProperty = vtkSmartPointer<vtkProperty>::New();
	//backfaceProperty->SetSpecular(0.0);
	//backfaceProperty->SetDiffuse(0.0);
	//backfaceProperty->SetAmbient(10.0);
	//backfaceProperty->SetAmbientColor(1.0000, 0.3882, 0.2784);
	//m_actor->SetBackfaceProperty(backfaceProperty);
	

	m_render->AddActor(m_actor);
	QTime time = QTime::currentTime();//获取系统现在的时间
	auto randomNumGenerator = vtkSmartPointer<vtkMinimalStandardRandomSequence>::New();
	randomNumGenerator->SetSeed(time.msec());
	double rgb[3];
	rgb[0] = randomNumGenerator->GetValue();
	randomNumGenerator->Next();
	rgb[1] = randomNumGenerator->GetValue();
	randomNumGenerator->Next();
	rgb[2] = randomNumGenerator->GetValue();
	vtkMath::RandomSeed(50);
	vtkMath::RandomSeed(40);

	m_actor->GetProperty()->SetColor(rgb);
	QColor color;
	color.setRed(rgb[0]*255);
	color.setGreen(rgb[1]*255);
	color.setBlue(rgb[2]*255);
	QString backGroudColor;
	QString num;
	backGroudColor = "background-color: rgb(" + num.setNum(color.red()) + ", " + num.setNum(color.green()) + ", " + num.setNum(color.blue()) + ")";
	ui.ColorPickerButton->setStyleSheet(backGroudColor);
	m_render->GetRenderWindow()->Render();
	m_render->ResetCamera();
}







