/********************************************************************************
** Form generated from reading UI file 'ModelControlWidgetItem.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELCONTROLWIDGETITEM_H
#define UI_MODELCONTROLWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelControlWidgetItem
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *VisibilityButton;
    QPushButton *CategoryButton;
    QSpinBox *opacSpin;
    QPushButton *ColorPickerButton;
    QPushButton *DeleteButton;
    QPushButton *SaveButton;

    void setupUi(QWidget *ModelControlWidgetItem)
    {
        if (ModelControlWidgetItem->objectName().isEmpty())
            ModelControlWidgetItem->setObjectName(QStringLiteral("ModelControlWidgetItem"));
        ModelControlWidgetItem->resize(290, 30);
        ModelControlWidgetItem->setMinimumSize(QSize(290, 30));
        ModelControlWidgetItem->setMaximumSize(QSize(320, 30));
        gridLayout = new QGridLayout(ModelControlWidgetItem);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        VisibilityButton = new QPushButton(ModelControlWidgetItem);
        VisibilityButton->setObjectName(QStringLiteral("VisibilityButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VisibilityButton->sizePolicy().hasHeightForWidth());
        VisibilityButton->setSizePolicy(sizePolicy);
        VisibilityButton->setMinimumSize(QSize(25, 25));
        VisibilityButton->setMaximumSize(QSize(30, 25));
        VisibilityButton->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ImplantDesign/Resources/AnnotationVisibility.png"), QSize(), QIcon::Normal, QIcon::Off);
        VisibilityButton->setIcon(icon);
        VisibilityButton->setIconSize(QSize(64, 64));
        VisibilityButton->setCheckable(true);
        VisibilityButton->setChecked(false);

        horizontalLayout->addWidget(VisibilityButton);

        CategoryButton = new QPushButton(ModelControlWidgetItem);
        CategoryButton->setObjectName(QStringLiteral("CategoryButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CategoryButton->sizePolicy().hasHeightForWidth());
        CategoryButton->setSizePolicy(sizePolicy1);
        CategoryButton->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        CategoryButton->setFont(font);
        CategoryButton->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));

        horizontalLayout->addWidget(CategoryButton);

        opacSpin = new QSpinBox(ModelControlWidgetItem);
        opacSpin->setObjectName(QStringLiteral("opacSpin"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(opacSpin->sizePolicy().hasHeightForWidth());
        opacSpin->setSizePolicy(sizePolicy2);
        opacSpin->setMinimumSize(QSize(45, 0));
        opacSpin->setMaximumSize(QSize(55, 50));
        opacSpin->setFont(font);
        opacSpin->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        opacSpin->setMaximum(100);
        opacSpin->setValue(100);

        horizontalLayout->addWidget(opacSpin);

        ColorPickerButton = new QPushButton(ModelControlWidgetItem);
        ColorPickerButton->setObjectName(QStringLiteral("ColorPickerButton"));
        sizePolicy.setHeightForWidth(ColorPickerButton->sizePolicy().hasHeightForWidth());
        ColorPickerButton->setSizePolicy(sizePolicy);
        ColorPickerButton->setMinimumSize(QSize(25, 25));
        ColorPickerButton->setMaximumSize(QSize(30, 25));
        ColorPickerButton->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        ColorPickerButton->setProperty("displayColorName", QVariant(false));

        horizontalLayout->addWidget(ColorPickerButton);

        DeleteButton = new QPushButton(ModelControlWidgetItem);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        sizePolicy.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy);
        DeleteButton->setMinimumSize(QSize(25, 25));
        DeleteButton->setMaximumSize(QSize(30, 25));
        DeleteButton->setStyleSheet(QLatin1String("QPushButton:pressed{background-color: qconicalgradient(cx:1, cy:0, angle:176.3, stop:0.202247 rgba(255, 127, 148, 255), stop:1 rgba(255, 255, 255, 255));}\n"
"\n"
"QPushButton{border:2px solid gray;border-radius:10px;padding:2px 4px;}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ImplantDesign/Resources/AnnotationDelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DeleteButton->setIcon(icon1);

        horizontalLayout->addWidget(DeleteButton);

        SaveButton = new QPushButton(ModelControlWidgetItem);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        sizePolicy.setHeightForWidth(SaveButton->sizePolicy().hasHeightForWidth());
        SaveButton->setSizePolicy(sizePolicy);
        SaveButton->setMinimumSize(QSize(25, 25));
        SaveButton->setMaximumSize(QSize(30, 25));
        SaveButton->setStyleSheet(QLatin1String("QPushButton:pressed{background-color: qconicalgradient(cx:1, cy:0, angle:176.3, stop:0.202247 rgba(255, 127, 148, 255), stop:1 rgba(255, 255, 255, 255));}\n"
"\n"
"QPushButton{border:2px solid gray;border-radius:10px;padding:2px 4px;}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ImplantDesign/Resources/DownloadExtension.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveButton->setIcon(icon2);

        horizontalLayout->addWidget(SaveButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ModelControlWidgetItem);
        QObject::connect(VisibilityButton, SIGNAL(clicked()), ModelControlWidgetItem, SLOT(OnVisibilityOff()));

        QMetaObject::connectSlotsByName(ModelControlWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *ModelControlWidgetItem)
    {
        ModelControlWidgetItem->setWindowTitle(QApplication::translate("ModelControlWidgetItem", "ModelControlWidgetItem", 0));
#ifndef QT_NO_TOOLTIP
        VisibilityButton->setToolTip(QApplication::translate("ModelControlWidgetItem", "Visible", 0));
#endif // QT_NO_TOOLTIP
        VisibilityButton->setText(QString());
        CategoryButton->setText(QApplication::translate("ModelControlWidgetItem", "Category", 0));
#ifndef QT_NO_TOOLTIP
        opacSpin->setToolTip(QApplication::translate("ModelControlWidgetItem", "Opacity", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ColorPickerButton->setToolTip(QApplication::translate("ModelControlWidgetItem", "Color", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        DeleteButton->setToolTip(QApplication::translate("ModelControlWidgetItem", "Delete", 0));
#endif // QT_NO_TOOLTIP
        DeleteButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        SaveButton->setToolTip(QApplication::translate("ModelControlWidgetItem", "Save", 0));
#endif // QT_NO_TOOLTIP
        SaveButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModelControlWidgetItem: public Ui_ModelControlWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELCONTROLWIDGETITEM_H
