/********************************************************************************
** Form generated from reading UI file 'ImplantDesign.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPLANTDESIGN_H
#define UI_IMPLANTDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QCustomVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ImplantDesignClass
{
public:
    QAction *actionLoadProject;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCustomVTKWidget *ViewWidget;
    QWidget *ParameterWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTableWidget *ModelTableWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *ThicknessSpinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *XExtendSpinBox;
    QLabel *label_3;
    QSpinBox *YExtendSpinBox;
    QLabel *label_4;
    QSpinBox *ZExtendSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ContourChooseButton;
    QPushButton *SingleChooseButton;
    QSpacerItem *verticalSpacer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImplantDesignClass)
    {
        if (ImplantDesignClass->objectName().isEmpty())
            ImplantDesignClass->setObjectName(QStringLiteral("ImplantDesignClass"));
        ImplantDesignClass->resize(878, 741);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ImplantDesign/Resources/smartguideicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ImplantDesignClass->setWindowIcon(icon);
        ImplantDesignClass->setStyleSheet(QStringLiteral("font: 75 9pt \"Arial\";"));
        actionLoadProject = new QAction(ImplantDesignClass);
        actionLoadProject->setObjectName(QStringLiteral("actionLoadProject"));
        QIcon icon1;
        QString iconThemeName = QStringLiteral("LoadProject");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral(":/ImplantDesign/Resources/openproject.ico"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionLoadProject->setIcon(icon1);
        centralWidget = new QWidget(ImplantDesignClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        ViewWidget = new QCustomVTKWidget(centralWidget);
        ViewWidget->setObjectName(QStringLiteral("ViewWidget"));

        gridLayout->addWidget(ViewWidget, 0, 0, 1, 1);

        ParameterWidget = new QWidget(centralWidget);
        ParameterWidget->setObjectName(QStringLiteral("ParameterWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ParameterWidget->sizePolicy().hasHeightForWidth());
        ParameterWidget->setSizePolicy(sizePolicy);
        ParameterWidget->setMaximumSize(QSize(350, 16777215));
        gridLayout_3 = new QGridLayout(ParameterWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(ParameterWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ModelTableWidget = new QTableWidget(groupBox);
        ModelTableWidget->setObjectName(QStringLiteral("ModelTableWidget"));
        ModelTableWidget->setMaximumSize(QSize(330, 16777215));

        gridLayout_2->addWidget(ModelTableWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ParameterWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        ThicknessSpinBox = new QSpinBox(groupBox_2);
        ThicknessSpinBox->setObjectName(QStringLiteral("ThicknessSpinBox"));
        ThicknessSpinBox->setMinimum(2);

        horizontalLayout->addWidget(ThicknessSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        XExtendSpinBox = new QSpinBox(groupBox_2);
        XExtendSpinBox->setObjectName(QStringLiteral("XExtendSpinBox"));
        XExtendSpinBox->setMinimum(100);
        XExtendSpinBox->setMaximum(300);

        horizontalLayout_2->addWidget(XExtendSpinBox);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        YExtendSpinBox = new QSpinBox(groupBox_2);
        YExtendSpinBox->setObjectName(QStringLiteral("YExtendSpinBox"));
        YExtendSpinBox->setMinimum(100);
        YExtendSpinBox->setMaximum(300);

        horizontalLayout_2->addWidget(YExtendSpinBox);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        ZExtendSpinBox = new QSpinBox(groupBox_2);
        ZExtendSpinBox->setObjectName(QStringLiteral("ZExtendSpinBox"));
        ZExtendSpinBox->setMinimum(100);
        ZExtendSpinBox->setMaximum(300);

        horizontalLayout_2->addWidget(ZExtendSpinBox);


        gridLayout_4->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ContourChooseButton = new QPushButton(groupBox_2);
        ContourChooseButton->setObjectName(QStringLiteral("ContourChooseButton"));
        ContourChooseButton->setStyleSheet(QLatin1String("QPushButton:checked { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"\n"
"	                 font: 75 16pt \"Arial\";\n"
"					\n"
"					\n"
"					color: rgb(255, 78, 34);\n"
"                    }"));
        ContourChooseButton->setCheckable(true);

        horizontalLayout_3->addWidget(ContourChooseButton);

        SingleChooseButton = new QPushButton(groupBox_2);
        SingleChooseButton->setObjectName(QStringLiteral("SingleChooseButton"));
        SingleChooseButton->setStyleSheet(QLatin1String("QPushButton:checked { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"\n"
"	                 font: 75 16pt \"Arial\";\n"
"					\n"
"					\n"
"					color: rgb(255, 78, 34);\n"
"                    }"));
        SingleChooseButton->setCheckable(true);

        horizontalLayout_3->addWidget(SingleChooseButton);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 215, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout->addWidget(ParameterWidget, 0, 1, 1, 1);

        ImplantDesignClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(ImplantDesignClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImplantDesignClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImplantDesignClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImplantDesignClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionLoadProject);

        retranslateUi(ImplantDesignClass);

        QMetaObject::connectSlotsByName(ImplantDesignClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImplantDesignClass)
    {
        ImplantDesignClass->setWindowTitle(QApplication::translate("ImplantDesignClass", "ImplantDesign", 0));
        actionLoadProject->setText(QApplication::translate("ImplantDesignClass", "LoadProject", 0));
        actionLoadProject->setShortcut(QApplication::translate("ImplantDesignClass", "Ctrl+O", 0));
        groupBox->setTitle(QApplication::translate("ImplantDesignClass", "Model ", 0));
        groupBox_2->setTitle(QApplication::translate("ImplantDesignClass", "Parameter", 0));
        label->setText(QApplication::translate("ImplantDesignClass", "Thickness:", 0));
        label_2->setText(QApplication::translate("ImplantDesignClass", "X Extend:", 0));
        label_3->setText(QApplication::translate("ImplantDesignClass", "Y Extend:", 0));
        label_4->setText(QApplication::translate("ImplantDesignClass", "Z Extend:", 0));
        ContourChooseButton->setText(QApplication::translate("ImplantDesignClass", "Contour Choose", 0));
        SingleChooseButton->setText(QApplication::translate("ImplantDesignClass", "Single Choose", 0));
    } // retranslateUi

};

namespace Ui {
    class ImplantDesignClass: public Ui_ImplantDesignClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPLANTDESIGN_H
