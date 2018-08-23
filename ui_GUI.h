/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "GUI_StatusBar.hpp"
#include "GUI_ToolBar.hpp"
#include "GUI_ToolBox.hpp"

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QAction *actionFileNew;
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionFileSave_As;
    QAction *actionFileClose;
    QAction *actionFileQuit;
    QAction *actionLevelAssetsManager;
    QAction *actionLevelSettings;
    QAction *actionViewZoom25;
    QAction *actionViewZoom50;
    QAction *actionViewZoom100;
    QAction *actionViewZoom125;
    QAction *actionViewZoom150;
    QAction *actionViewZoom175;
    QAction *actionViewReset;
    QWidget *mainWidget;
    QFrame *editorFrame;
    GUI_ToolBox *toolBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuLevel;
    QMenu *menuView;
    GUI_StatusBar *statusBar;
    GUI_ToolBar *toolBar;

    void setupUi(QMainWindow *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->setEnabled(true);
        GUI->resize(1300, 725);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUI->sizePolicy().hasHeightForWidth());
        GUI->setSizePolicy(sizePolicy);
        GUI->setMinimumSize(QSize(1300, 725));
        GUI->setMaximumSize(QSize(1300, 725));
        GUI->setBaseSize(QSize(1300, 725));
        GUI->setCursor(QCursor(Qt::ArrowCursor));
        GUI->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral("data/Object.png"), QSize(), QIcon::Normal, QIcon::Off);
        GUI->setWindowIcon(icon);
        GUI->setAutoFillBackground(false);
        GUI->setIconSize(QSize(32, 32));
        GUI->setAnimated(true);
        GUI->setUnifiedTitleAndToolBarOnMac(true);
        actionFileNew = new QAction(GUI);
        actionFileNew->setObjectName(QStringLiteral("actionFileNew"));
        actionFileOpen = new QAction(GUI);
        actionFileOpen->setObjectName(QStringLiteral("actionFileOpen"));
        actionFileSave = new QAction(GUI);
        actionFileSave->setObjectName(QStringLiteral("actionFileSave"));
        actionFileSave->setEnabled(false);
        actionFileSave_As = new QAction(GUI);
        actionFileSave_As->setObjectName(QStringLiteral("actionFileSave_As"));
        actionFileSave_As->setEnabled(false);
        actionFileClose = new QAction(GUI);
        actionFileClose->setObjectName(QStringLiteral("actionFileClose"));
        actionFileClose->setEnabled(false);
        actionFileQuit = new QAction(GUI);
        actionFileQuit->setObjectName(QStringLiteral("actionFileQuit"));
        actionFileQuit->setMenuRole(QAction::QuitRole);
        actionLevelAssetsManager = new QAction(GUI);
        actionLevelAssetsManager->setObjectName(QStringLiteral("actionLevelAssetsManager"));
        actionLevelAssetsManager->setEnabled(true);
        actionLevelSettings = new QAction(GUI);
        actionLevelSettings->setObjectName(QStringLiteral("actionLevelSettings"));
        actionLevelSettings->setEnabled(true);
        actionViewZoom25 = new QAction(GUI);
        actionViewZoom25->setObjectName(QStringLiteral("actionViewZoom25"));
        actionViewZoom25->setEnabled(true);
        actionViewZoom50 = new QAction(GUI);
        actionViewZoom50->setObjectName(QStringLiteral("actionViewZoom50"));
        actionViewZoom50->setEnabled(true);
        actionViewZoom100 = new QAction(GUI);
        actionViewZoom100->setObjectName(QStringLiteral("actionViewZoom100"));
        actionViewZoom100->setEnabled(true);
        actionViewZoom125 = new QAction(GUI);
        actionViewZoom125->setObjectName(QStringLiteral("actionViewZoom125"));
        actionViewZoom125->setEnabled(true);
        actionViewZoom150 = new QAction(GUI);
        actionViewZoom150->setObjectName(QStringLiteral("actionViewZoom150"));
        actionViewZoom150->setEnabled(true);
        actionViewZoom175 = new QAction(GUI);
        actionViewZoom175->setObjectName(QStringLiteral("actionViewZoom175"));
        actionViewZoom175->setEnabled(true);
        actionViewReset = new QAction(GUI);
        actionViewReset->setObjectName(QStringLiteral("actionViewReset"));
        actionViewReset->setEnabled(true);
        mainWidget = new QWidget(GUI);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        editorFrame = new QFrame(mainWidget);
        editorFrame->setObjectName(QStringLiteral("editorFrame"));
        editorFrame->setEnabled(true);
        editorFrame->setGeometry(QRect(10, 10, 1024, 600));
        editorFrame->setMouseTracking(false);
        editorFrame->setFocusPolicy(Qt::StrongFocus);
        editorFrame->setContextMenuPolicy(Qt::DefaultContextMenu);
        editorFrame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        editorFrame->setFrameShape(QFrame::Box);
        toolBox = new GUI_ToolBox(mainWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(1045, 10, 240, 600));
        GUI->setCentralWidget(mainWidget);
        menuBar = new QMenuBar(GUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 20));
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setToolTipsVisible(true);
        menuLevel = new QMenu(menuBar);
        menuLevel->setObjectName(QStringLiteral("menuLevel"));
        menuLevel->setEnabled(false);
        menuLevel->setToolTipsVisible(true);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuView->setEnabled(false);
        GUI->setMenuBar(menuBar);
        statusBar = new GUI_StatusBar(GUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setSizeGripEnabled(false);
        GUI->setStatusBar(statusBar);
        toolBar = new GUI_ToolBar(GUI);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setEnabled(false);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(false);
        GUI->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLevel->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionFileNew);
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileSave);
        menuFile->addAction(actionFileSave_As);
        menuFile->addAction(actionFileClose);
        menuFile->addSeparator();
        menuFile->addAction(actionFileQuit);
        menuLevel->addAction(actionLevelSettings);
        menuLevel->addAction(actionLevelAssetsManager);
        menuView->addAction(actionViewZoom25);
        menuView->addAction(actionViewZoom50);
        menuView->addAction(actionViewZoom100);
        menuView->addAction(actionViewZoom125);
        menuView->addAction(actionViewZoom150);
        menuView->addAction(actionViewZoom175);
        menuView->addSeparator();
        menuView->addAction(actionViewReset);

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QMainWindow *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "[GNB] Level Editor", 0));
        actionFileNew->setText(QApplication::translate("GUI", "New...", 0));
#ifndef QT_NO_TOOLTIP
        actionFileNew->setToolTip(QApplication::translate("GUI", "Create a new level.", 0));
#endif // QT_NO_TOOLTIP
        actionFileOpen->setText(QApplication::translate("GUI", "Open...", 0));
#ifndef QT_NO_TOOLTIP
        actionFileOpen->setToolTip(QApplication::translate("GUI", "Open an existing level.", 0));
#endif // QT_NO_TOOLTIP
        actionFileSave->setText(QApplication::translate("GUI", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionFileSave->setToolTip(QApplication::translate("GUI", "Save the current level.", 0));
#endif // QT_NO_TOOLTIP
        actionFileSave_As->setText(QApplication::translate("GUI", "Save As...", 0));
#ifndef QT_NO_TOOLTIP
        actionFileSave_As->setToolTip(QApplication::translate("GUI", "Save the current level. (Ask for directory.)", 0));
#endif // QT_NO_TOOLTIP
        actionFileClose->setText(QApplication::translate("GUI", "Close...", 0));
#ifndef QT_NO_TOOLTIP
        actionFileClose->setToolTip(QApplication::translate("GUI", "Close current level.", 0));
#endif // QT_NO_TOOLTIP
        actionFileQuit->setText(QApplication::translate("GUI", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        actionFileQuit->setToolTip(QApplication::translate("GUI", "Quit [GNB] Level Design.", 0));
#endif // QT_NO_TOOLTIP
        actionLevelAssetsManager->setText(QApplication::translate("GUI", "Assets Manager...", 0));
#ifndef QT_NO_TOOLTIP
        actionLevelAssetsManager->setToolTip(QApplication::translate("GUI", "Open Assets Manager (add, rename, remove, export, import).", 0));
#endif // QT_NO_TOOLTIP
        actionLevelSettings->setText(QApplication::translate("GUI", "Settings...", 0));
#ifndef QT_NO_TOOLTIP
        actionLevelSettings->setToolTip(QApplication::translate("GUI", "Show current level settings.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom25->setText(QApplication::translate("GUI", "25 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom25->setToolTip(QApplication::translate("GUI", "Set zoom to: 25%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom50->setText(QApplication::translate("GUI", "50 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom50->setToolTip(QApplication::translate("GUI", "Set zoom to: 50%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom100->setText(QApplication::translate("GUI", "100 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom100->setToolTip(QApplication::translate("GUI", "Set zoom to: 100%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom125->setText(QApplication::translate("GUI", "125 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom125->setToolTip(QApplication::translate("GUI", "Set zoom to: 125%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom150->setText(QApplication::translate("GUI", "150 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom150->setToolTip(QApplication::translate("GUI", "Set zoom to: 150%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewZoom175->setText(QApplication::translate("GUI", "175 %", 0));
#ifndef QT_NO_TOOLTIP
        actionViewZoom175->setToolTip(QApplication::translate("GUI", "Set zoom to: 175%.", 0));
#endif // QT_NO_TOOLTIP
        actionViewReset->setText(QApplication::translate("GUI", "Reset", 0));
#ifndef QT_NO_TOOLTIP
        actionViewReset->setToolTip(QApplication::translate("GUI", "Reset zoom and view position (center).", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("GUI", "File", 0));
        menuLevel->setTitle(QApplication::translate("GUI", "Level", 0));
        menuView->setTitle(QApplication::translate("GUI", "View", 0));
        toolBar->setWindowTitle(QApplication::translate("GUI", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
