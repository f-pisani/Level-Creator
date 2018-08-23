/********************************************************************************
** Form generated from reading UI file 'GUI_ToolBox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_TOOLBOX_H
#define UI_GUI_TOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_ToolBox
{
public:
    QWidget *Information;
    QWidget *Assets;
    QTableWidget *assetsTable;

    void setupUi(QToolBox *GUI_ToolBox)
    {
        if (GUI_ToolBox->objectName().isEmpty())
            GUI_ToolBox->setObjectName(QStringLiteral("GUI_ToolBox"));
        GUI_ToolBox->resize(240, 600);
        GUI_ToolBox->setMinimumSize(QSize(240, 600));
        GUI_ToolBox->setMaximumSize(QSize(240, 600));
        GUI_ToolBox->setBaseSize(QSize(240, 600));
        GUI_ToolBox->setFrameShape(QFrame::NoFrame);
        GUI_ToolBox->setFrameShadow(QFrame::Plain);
        Information = new QWidget();
        Information->setObjectName(QStringLiteral("Information"));
        GUI_ToolBox->addItem(Information, QStringLiteral("Information"));
        Assets = new QWidget();
        Assets->setObjectName(QStringLiteral("Assets"));
        Assets->setGeometry(QRect(0, 0, 240, 546));
        assetsTable = new QTableWidget(Assets);
        if (assetsTable->columnCount() < 3)
            assetsTable->setColumnCount(3);
        assetsTable->setObjectName(QStringLiteral("assetsTable"));
        assetsTable->setGeometry(QRect(10, 10, 220, 400));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(assetsTable->sizePolicy().hasHeightForWidth());
        assetsTable->setSizePolicy(sizePolicy);
        assetsTable->setMinimumSize(QSize(220, 400));
        assetsTable->setMaximumSize(QSize(220, 400));
        assetsTable->setBaseSize(QSize(220, 400));
        assetsTable->setStyleSheet(QLatin1String("background-color: rgb(200, 200, 200);\n"
"selection-background-color: rgb(0, 0, 255);"));
        assetsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        assetsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        assetsTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        assetsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        assetsTable->setProperty("showDropIndicator", QVariant(false));
        assetsTable->setDragDropOverwriteMode(false);
        assetsTable->setAlternatingRowColors(false);
        assetsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        assetsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        assetsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        assetsTable->setShowGrid(false);
        assetsTable->setWordWrap(false);
        assetsTable->setCornerButtonEnabled(false);
        assetsTable->setColumnCount(3);
        assetsTable->horizontalHeader()->setVisible(false);
        assetsTable->horizontalHeader()->setDefaultSectionSize(64);
        assetsTable->horizontalHeader()->setMinimumSectionSize(64);
        assetsTable->verticalHeader()->setVisible(false);
        assetsTable->verticalHeader()->setDefaultSectionSize(64);
        assetsTable->verticalHeader()->setMinimumSectionSize(64);
        GUI_ToolBox->addItem(Assets, QStringLiteral("Assets"));

        retranslateUi(GUI_ToolBox);

        GUI_ToolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GUI_ToolBox);
    } // setupUi

    void retranslateUi(QToolBox *GUI_ToolBox)
    {
        GUI_ToolBox->setWindowTitle(QApplication::translate("GUI_ToolBox", "ToolBox", 0));
        GUI_ToolBox->setItemText(GUI_ToolBox->indexOf(Information), QApplication::translate("GUI_ToolBox", "Information", 0));
        GUI_ToolBox->setItemText(GUI_ToolBox->indexOf(Assets), QApplication::translate("GUI_ToolBox", "Assets", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_ToolBox: public Ui_GUI_ToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_TOOLBOX_H
