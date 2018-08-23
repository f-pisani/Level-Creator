/********************************************************************************
** Form generated from reading UI file 'GUI_LevelSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_LEVELSETTINGS_H
#define UI_GUI_LEVELSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_LevelSettings
{
public:
    QDialogButtonBox *confirmation_Button;
    QGroupBox *levelGroupBox;
    QLineEdit *pathLineEdit;
    QPushButton *selectPathBtn;
    QGroupBox *settingsGroupBox;
    QGroupBox *levelSizeGroupBox;
    QWidget *formLayoutWidget;
    QFormLayout *layout_2;
    QLabel *levelWidth_label;
    QLabel *levelHeight_label;
    QSpinBox *levelWidth_spinBox;
    QSpinBox *levelHeight_spinBox;
    QGroupBox *gridGroupBox;
    QWidget *formLayoutWidget_2;
    QFormLayout *layout;
    QLabel *gridWidth_label;
    QLabel *gridHeight_label;
    QSpinBox *gridWidth_spinBox;
    QSpinBox *gridHeight_spinBox;

    void setupUi(QDialog *GUI_LevelSettings)
    {
        if (GUI_LevelSettings->objectName().isEmpty())
            GUI_LevelSettings->setObjectName(QStringLiteral("GUI_LevelSettings"));
        GUI_LevelSettings->resize(450, 380);
        GUI_LevelSettings->setMinimumSize(QSize(450, 380));
        GUI_LevelSettings->setMaximumSize(QSize(450, 380));
        GUI_LevelSettings->setBaseSize(QSize(450, 380));
        confirmation_Button = new QDialogButtonBox(GUI_LevelSettings);
        confirmation_Button->setObjectName(QStringLiteral("confirmation_Button"));
        confirmation_Button->setGeometry(QRect(270, 340, 166, 21));
        confirmation_Button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        levelGroupBox = new QGroupBox(GUI_LevelSettings);
        levelGroupBox->setObjectName(QStringLiteral("levelGroupBox"));
        levelGroupBox->setGeometry(QRect(10, 10, 431, 61));
        pathLineEdit = new QLineEdit(levelGroupBox);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setEnabled(false);
        pathLineEdit->setGeometry(QRect(10, 30, 361, 21));
        selectPathBtn = new QPushButton(levelGroupBox);
        selectPathBtn->setObjectName(QStringLiteral("selectPathBtn"));
        selectPathBtn->setGeometry(QRect(380, 30, 41, 21));
        settingsGroupBox = new QGroupBox(GUI_LevelSettings);
        settingsGroupBox->setObjectName(QStringLiteral("settingsGroupBox"));
        settingsGroupBox->setGeometry(QRect(10, 80, 431, 241));
        levelSizeGroupBox = new QGroupBox(settingsGroupBox);
        levelSizeGroupBox->setObjectName(QStringLiteral("levelSizeGroupBox"));
        levelSizeGroupBox->setGeometry(QRect(10, 20, 411, 101));
        formLayoutWidget = new QWidget(levelSizeGroupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 391, 61));
        layout_2 = new QFormLayout(formLayoutWidget);
        layout_2->setObjectName(QStringLiteral("layout_2"));
        layout_2->setContentsMargins(0, 0, 0, 0);
        levelWidth_label = new QLabel(formLayoutWidget);
        levelWidth_label->setObjectName(QStringLiteral("levelWidth_label"));

        layout_2->setWidget(0, QFormLayout::LabelRole, levelWidth_label);

        levelHeight_label = new QLabel(formLayoutWidget);
        levelHeight_label->setObjectName(QStringLiteral("levelHeight_label"));

        layout_2->setWidget(1, QFormLayout::LabelRole, levelHeight_label);

        levelWidth_spinBox = new QSpinBox(formLayoutWidget);
        levelWidth_spinBox->setObjectName(QStringLiteral("levelWidth_spinBox"));
        levelWidth_spinBox->setMinimum(8);
        levelWidth_spinBox->setMaximum(8192);
        levelWidth_spinBox->setValue(8);

        layout_2->setWidget(0, QFormLayout::FieldRole, levelWidth_spinBox);

        levelHeight_spinBox = new QSpinBox(formLayoutWidget);
        levelHeight_spinBox->setObjectName(QStringLiteral("levelHeight_spinBox"));
        levelHeight_spinBox->setMinimum(8);
        levelHeight_spinBox->setMaximum(8192);
        levelHeight_spinBox->setValue(8);

        layout_2->setWidget(1, QFormLayout::FieldRole, levelHeight_spinBox);

        gridGroupBox = new QGroupBox(settingsGroupBox);
        gridGroupBox->setObjectName(QStringLiteral("gridGroupBox"));
        gridGroupBox->setGeometry(QRect(10, 130, 411, 101));
        formLayoutWidget_2 = new QWidget(gridGroupBox);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 391, 61));
        layout = new QFormLayout(formLayoutWidget_2);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        gridWidth_label = new QLabel(formLayoutWidget_2);
        gridWidth_label->setObjectName(QStringLiteral("gridWidth_label"));

        layout->setWidget(0, QFormLayout::LabelRole, gridWidth_label);

        gridHeight_label = new QLabel(formLayoutWidget_2);
        gridHeight_label->setObjectName(QStringLiteral("gridHeight_label"));

        layout->setWidget(1, QFormLayout::LabelRole, gridHeight_label);

        gridWidth_spinBox = new QSpinBox(formLayoutWidget_2);
        gridWidth_spinBox->setObjectName(QStringLiteral("gridWidth_spinBox"));
        gridWidth_spinBox->setMinimum(2);
        gridWidth_spinBox->setMaximum(4);
        gridWidth_spinBox->setValue(2);

        layout->setWidget(0, QFormLayout::FieldRole, gridWidth_spinBox);

        gridHeight_spinBox = new QSpinBox(formLayoutWidget_2);
        gridHeight_spinBox->setObjectName(QStringLiteral("gridHeight_spinBox"));
        gridHeight_spinBox->setMinimum(2);
        gridHeight_spinBox->setMaximum(4);
        gridHeight_spinBox->setValue(2);

        layout->setWidget(1, QFormLayout::FieldRole, gridHeight_spinBox);


        retranslateUi(GUI_LevelSettings);

        QMetaObject::connectSlotsByName(GUI_LevelSettings);
    } // setupUi

    void retranslateUi(QDialog *GUI_LevelSettings)
    {
        GUI_LevelSettings->setWindowTitle(QApplication::translate("GUI_LevelSettings", "New level", 0));
        levelGroupBox->setTitle(QApplication::translate("GUI_LevelSettings", "Level file", 0));
        selectPathBtn->setText(QApplication::translate("GUI_LevelSettings", "...", 0));
        settingsGroupBox->setTitle(QApplication::translate("GUI_LevelSettings", "Settings", 0));
        levelSizeGroupBox->setTitle(QApplication::translate("GUI_LevelSettings", "Level size", 0));
        levelWidth_label->setText(QApplication::translate("GUI_LevelSettings", "Width:", 0));
        levelHeight_label->setText(QApplication::translate("GUI_LevelSettings", "Height: ", 0));
        gridGroupBox->setTitle(QApplication::translate("GUI_LevelSettings", "Grid size", 0));
        gridWidth_label->setText(QApplication::translate("GUI_LevelSettings", "Width:", 0));
        gridHeight_label->setText(QApplication::translate("GUI_LevelSettings", "Height:", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_LevelSettings: public Ui_GUI_LevelSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_LEVELSETTINGS_H
