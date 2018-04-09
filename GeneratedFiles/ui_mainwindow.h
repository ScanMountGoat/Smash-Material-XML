/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpen_Folder;
    QAction *actionAbout;
    QAction *actionDisplay_Settings;
    QAction *actionClear_Materials;
    QAction *actionSearch_Settings;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *searchClearHorizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *searchPushButton;
    QPushButton *clearPushButton;
    QMenuBar *menuBar;
    QMenu *menuMaterial_XML;
    QMenu *menuAbout;
    QMenu *menuSearch_Settings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1008, 961);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName(QStringLiteral("actionOpen_Folder"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDisplay_Settings = new QAction(MainWindow);
        actionDisplay_Settings->setObjectName(QStringLiteral("actionDisplay_Settings"));
        actionClear_Materials = new QAction(MainWindow);
        actionClear_Materials->setObjectName(QStringLiteral("actionClear_Materials"));
        actionSearch_Settings = new QAction(MainWindow);
        actionSearch_Settings->setObjectName(QStringLiteral("actionSearch_Settings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(plainTextEdit);

        searchClearHorizontalLayout = new QHBoxLayout();
        searchClearHorizontalLayout->setSpacing(6);
        searchClearHorizontalLayout->setObjectName(QStringLiteral("searchClearHorizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        searchClearHorizontalLayout->addItem(horizontalSpacer);

        searchPushButton = new QPushButton(centralWidget);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));

        searchClearHorizontalLayout->addWidget(searchPushButton);

        clearPushButton = new QPushButton(centralWidget);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));

        searchClearHorizontalLayout->addWidget(clearPushButton);


        verticalLayout_4->addLayout(searchClearHorizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1008, 21));
        menuMaterial_XML = new QMenu(menuBar);
        menuMaterial_XML->setObjectName(QStringLiteral("menuMaterial_XML"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuSearch_Settings = new QMenu(menuBar);
        menuSearch_Settings->setObjectName(QStringLiteral("menuSearch_Settings"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMaterial_XML->menuAction());
        menuBar->addAction(menuSearch_Settings->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuMaterial_XML->addAction(actionOpen);
        menuMaterial_XML->addAction(actionOpen_Folder);
        menuMaterial_XML->addAction(actionClear_Materials);
        menuAbout->addAction(actionAbout);
        menuSearch_Settings->addAction(actionSearch_Settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Material XML", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Add materials from file", Q_NULLPTR));
        actionOpen_Folder->setText(QApplication::translate("MainWindow", "Add materials from folder", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionDisplay_Settings->setText(QApplication::translate("MainWindow", "Display Settings", Q_NULLPTR));
        actionClear_Materials->setText(QApplication::translate("MainWindow", "Clear materials", Q_NULLPTR));
        actionSearch_Settings->setText(QApplication::translate("MainWindow", "Search Settings", Q_NULLPTR));
        searchPushButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        clearPushButton->setText(QApplication::translate("MainWindow", "Clear Output", Q_NULLPTR));
        menuMaterial_XML->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuSearch_Settings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
