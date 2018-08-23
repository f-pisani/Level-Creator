/********************************************************************************
** Form generated from reading UI file 'GUI_AssetsManager.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_ASSETSMANAGER_H
#define UI_GUI_ASSETSMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_AssetsManager
{
public:
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *renameButton;
    QPushButton *removeButton;
    QPushButton *removeAllButton;
    QPushButton *exportDatButton;
    QPushButton *importDatButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectAllButton;
    QPushButton *unselectAllButton;
    QPushButton *toggleSelectionButton;
    QLabel *preview;

    void setupUi(QDialog *GUI_AssetsManager)
    {
        if (GUI_AssetsManager->objectName().isEmpty())
            GUI_AssetsManager->setObjectName(QStringLiteral("GUI_AssetsManager"));
        GUI_AssetsManager->resize(660, 330);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUI_AssetsManager->sizePolicy().hasHeightForWidth());
        GUI_AssetsManager->setSizePolicy(sizePolicy);
        GUI_AssetsManager->setMinimumSize(QSize(660, 330));
        GUI_AssetsManager->setMaximumSize(QSize(660, 330));
        GUI_AssetsManager->setBaseSize(QSize(660, 330));
        GUI_AssetsManager->setContextMenuPolicy(Qt::DefaultContextMenu);
        listWidget = new QListWidget(GUI_AssetsManager);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 411, 221));
        listWidget->setMouseTracking(true);
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
        listWidget->setFrameShape(QFrame::Box);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setAlternatingRowColors(true);
        listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setModelColumn(0);
        listWidget->setBatchSize(100);
        listWidget->setSortingEnabled(true);
        horizontalLayoutWidget = new QWidget(GUI_AssetsManager);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 280, 641, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        renameButton = new QPushButton(horizontalLayoutWidget);
        renameButton->setObjectName(QStringLiteral("renameButton"));

        horizontalLayout->addWidget(renameButton);

        removeButton = new QPushButton(horizontalLayoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);

        removeAllButton = new QPushButton(horizontalLayoutWidget);
        removeAllButton->setObjectName(QStringLiteral("removeAllButton"));

        horizontalLayout->addWidget(removeAllButton);

        exportDatButton = new QPushButton(horizontalLayoutWidget);
        exportDatButton->setObjectName(QStringLiteral("exportDatButton"));

        horizontalLayout->addWidget(exportDatButton);

        importDatButton = new QPushButton(horizontalLayoutWidget);
        importDatButton->setObjectName(QStringLiteral("importDatButton"));

        horizontalLayout->addWidget(importDatButton);

        horizontalLayoutWidget_2 = new QWidget(GUI_AssetsManager);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(120, 10, 421, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectAllButton = new QPushButton(horizontalLayoutWidget_2);
        selectAllButton->setObjectName(QStringLiteral("selectAllButton"));

        horizontalLayout_2->addWidget(selectAllButton);

        unselectAllButton = new QPushButton(horizontalLayoutWidget_2);
        unselectAllButton->setObjectName(QStringLiteral("unselectAllButton"));

        horizontalLayout_2->addWidget(unselectAllButton);

        toggleSelectionButton = new QPushButton(horizontalLayoutWidget_2);
        toggleSelectionButton->setObjectName(QStringLiteral("toggleSelectionButton"));

        horizontalLayout_2->addWidget(toggleSelectionButton);

        preview = new QLabel(GUI_AssetsManager);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setGeometry(QRect(440, 60, 200, 200));
        preview->setContextMenuPolicy(Qt::NoContextMenu);
        preview->setAutoFillBackground(false);
        preview->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        preview->setFrameShape(QFrame::Box);
        preview->setFrameShadow(QFrame::Sunken);
        preview->setScaledContents(false);
        preview->setAlignment(Qt::AlignCenter);

        retranslateUi(GUI_AssetsManager);

        QMetaObject::connectSlotsByName(GUI_AssetsManager);
    } // setupUi

    void retranslateUi(QDialog *GUI_AssetsManager)
    {
        GUI_AssetsManager->setWindowTitle(QApplication::translate("GUI_AssetsManager", "Assets Manager", 0));
        addButton->setText(QApplication::translate("GUI_AssetsManager", "Add...", 0));
        renameButton->setText(QApplication::translate("GUI_AssetsManager", "Rename...", 0));
        removeButton->setText(QApplication::translate("GUI_AssetsManager", "Remove...", 0));
        removeAllButton->setText(QApplication::translate("GUI_AssetsManager", "Remove all...", 0));
        exportDatButton->setText(QApplication::translate("GUI_AssetsManager", "Export to DAT", 0));
        importDatButton->setText(QApplication::translate("GUI_AssetsManager", "Import from DAT", 0));
        selectAllButton->setText(QApplication::translate("GUI_AssetsManager", "Select all", 0));
        unselectAllButton->setText(QApplication::translate("GUI_AssetsManager", "Unselect all", 0));
        toggleSelectionButton->setText(QApplication::translate("GUI_AssetsManager", "Toggle selection", 0));
        preview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GUI_AssetsManager: public Ui_GUI_AssetsManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_ASSETSMANAGER_H
