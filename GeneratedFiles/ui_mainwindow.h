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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QCheckBox *flagsCheckBox;
    QCheckBox *srcCheckBox;
    QCheckBox *dstCheckBox;
    QWidget *dstContainer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dstLabel;
    QComboBox *dstOpComboBox;
    QLineEdit *dstLineEdit;
    QWidget *srcContainer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *srcLabel;
    QComboBox *srcOpComboBox;
    QLineEdit *srcLineEdit;
    QWidget *flagsContainer;
    QWidget *layoutWidget2;
    QHBoxLayout *flagsHorizontalLayout;
    QLabel *flagsLabel;
    QLineEdit *flags1LineEdit;
    QComboBox *flagsOpComboBox;
    QLineEdit *flags2LineEdit;
    QPushButton *searchPushButton;
    QPushButton *clearPushButton;
    QCheckBox *matPropCheckBox;
    QWidget *matPropContainer;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *nuLabel;
    QLineEdit *matPropLineEdit;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuMaterial_XML;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(459, 635);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 261));
        flagsCheckBox = new QCheckBox(groupBox);
        flagsCheckBox->setObjectName(QStringLiteral("flagsCheckBox"));
        flagsCheckBox->setGeometry(QRect(10, 20, 70, 17));
        srcCheckBox = new QCheckBox(groupBox);
        srcCheckBox->setObjectName(QStringLiteral("srcCheckBox"));
        srcCheckBox->setGeometry(QRect(10, 70, 70, 17));
        dstCheckBox = new QCheckBox(groupBox);
        dstCheckBox->setObjectName(QStringLiteral("dstCheckBox"));
        dstCheckBox->setGeometry(QRect(10, 120, 70, 17));
        dstContainer = new QWidget(groupBox);
        dstContainer->setObjectName(QStringLiteral("dstContainer"));
        dstContainer->setGeometry(QRect(30, 140, 241, 31));
        layoutWidget = new QWidget(dstContainer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 279, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dstLabel = new QLabel(layoutWidget);
        dstLabel->setObjectName(QStringLiteral("dstLabel"));

        horizontalLayout_3->addWidget(dstLabel);

        dstOpComboBox = new QComboBox(layoutWidget);
        dstOpComboBox->setObjectName(QStringLiteral("dstOpComboBox"));

        horizontalLayout_3->addWidget(dstOpComboBox);

        dstLineEdit = new QLineEdit(layoutWidget);
        dstLineEdit->setObjectName(QStringLiteral("dstLineEdit"));

        horizontalLayout_3->addWidget(dstLineEdit);

        srcContainer = new QWidget(groupBox);
        srcContainer->setObjectName(QStringLiteral("srcContainer"));
        srcContainer->setGeometry(QRect(30, 90, 241, 31));
        layoutWidget1 = new QWidget(srcContainer);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 278, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        srcLabel = new QLabel(layoutWidget1);
        srcLabel->setObjectName(QStringLiteral("srcLabel"));

        horizontalLayout_2->addWidget(srcLabel);

        srcOpComboBox = new QComboBox(layoutWidget1);
        srcOpComboBox->setObjectName(QStringLiteral("srcOpComboBox"));

        horizontalLayout_2->addWidget(srcOpComboBox);

        srcLineEdit = new QLineEdit(layoutWidget1);
        srcLineEdit->setObjectName(QStringLiteral("srcLineEdit"));

        horizontalLayout_2->addWidget(srcLineEdit);

        flagsContainer = new QWidget(groupBox);
        flagsContainer->setObjectName(QStringLiteral("flagsContainer"));
        flagsContainer->setGeometry(QRect(30, 40, 371, 31));
        layoutWidget2 = new QWidget(flagsContainer);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 376, 33));
        flagsHorizontalLayout = new QHBoxLayout(layoutWidget2);
        flagsHorizontalLayout->setSpacing(6);
        flagsHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        flagsHorizontalLayout->setObjectName(QStringLiteral("flagsHorizontalLayout"));
        flagsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        flagsLabel = new QLabel(layoutWidget2);
        flagsLabel->setObjectName(QStringLiteral("flagsLabel"));

        flagsHorizontalLayout->addWidget(flagsLabel);

        flags1LineEdit = new QLineEdit(layoutWidget2);
        flags1LineEdit->setObjectName(QStringLiteral("flags1LineEdit"));

        flagsHorizontalLayout->addWidget(flags1LineEdit);

        flagsOpComboBox = new QComboBox(layoutWidget2);
        flagsOpComboBox->setObjectName(QStringLiteral("flagsOpComboBox"));

        flagsHorizontalLayout->addWidget(flagsOpComboBox);

        flags2LineEdit = new QLineEdit(layoutWidget2);
        flags2LineEdit->setObjectName(QStringLiteral("flags2LineEdit"));

        flagsHorizontalLayout->addWidget(flags2LineEdit);

        searchPushButton = new QPushButton(groupBox);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));
        searchPushButton->setGeometry(QRect(230, 230, 80, 22));
        clearPushButton = new QPushButton(groupBox);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        clearPushButton->setGeometry(QRect(320, 230, 80, 22));
        matPropCheckBox = new QCheckBox(groupBox);
        matPropCheckBox->setObjectName(QStringLiteral("matPropCheckBox"));
        matPropCheckBox->setGeometry(QRect(10, 170, 111, 17));
        matPropContainer = new QWidget(groupBox);
        matPropContainer->setObjectName(QStringLiteral("matPropContainer"));
        matPropContainer->setGeometry(QRect(20, 190, 251, 31));
        layoutWidget3 = new QWidget(matPropContainer);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 0, 231, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nuLabel = new QLabel(layoutWidget3);
        nuLabel->setObjectName(QStringLiteral("nuLabel"));

        horizontalLayout->addWidget(nuLabel);

        matPropLineEdit = new QLineEdit(layoutWidget3);
        matPropLineEdit->setObjectName(QStringLiteral("matPropLineEdit"));

        horizontalLayout->addWidget(matPropLineEdit);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 280, 391, 271));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 459, 38));
        menuMaterial_XML = new QMenu(menuBar);
        menuMaterial_XML->setObjectName(QStringLiteral("menuMaterial_XML"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMaterial_XML->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuMaterial_XML->addAction(actionOpen);
        menuMaterial_XML->addAction(actionOpen_Folder);
        menuMaterial_XML->addAction(actionClear_Materials);
        menuAbout->addAction(actionAbout);

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
        groupBox->setTitle(QApplication::translate("MainWindow", "Search Properties", Q_NULLPTR));
        flagsCheckBox->setText(QApplication::translate("MainWindow", "Flags", Q_NULLPTR));
        srcCheckBox->setText(QApplication::translate("MainWindow", "src Factor", Q_NULLPTR));
        dstCheckBox->setText(QApplication::translate("MainWindow", "dst Factor", Q_NULLPTR));
        dstLabel->setText(QApplication::translate("MainWindow", "dstFactor", Q_NULLPTR));
        dstOpComboBox->clear();
        dstOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        srcLabel->setText(QApplication::translate("MainWindow", "srcFactor", Q_NULLPTR));
        srcOpComboBox->clear();
        srcOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        flagsLabel->setText(QApplication::translate("MainWindow", "Flags & ", Q_NULLPTR));
        flagsOpComboBox->clear();
        flagsOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        searchPushButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        clearPushButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        matPropCheckBox->setText(QApplication::translate("MainWindow", "Material Property", Q_NULLPTR));
        nuLabel->setText(QApplication::translate("MainWindow", "NU_", Q_NULLPTR));
        menuMaterial_XML->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
