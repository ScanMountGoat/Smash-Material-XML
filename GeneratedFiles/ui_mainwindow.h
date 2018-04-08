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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QRadioButton>
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *settingsHorizontalLayout;
    QGroupBox *searchPropertiesGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *flagsMatPropHorizontalLayout;
    QFrame *flagsFrame;
    QWidget *flagsContainer;
    QWidget *layoutWidget;
    QHBoxLayout *flagsHorizontalLayout;
    QLabel *flagsLabel;
    QLineEdit *flags1LineEdit;
    QComboBox *flagsOpComboBox;
    QLineEdit *flags2LineEdit;
    QCheckBox *flagsCheckBox;
    QFrame *matPropertyFrame;
    QCheckBox *matPropCheckBox;
    QWidget *matPropContainer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *nuLabel;
    QLineEdit *matPropLineEdit;
    QHBoxLayout *dstSrcHorizontalLayout;
    QFrame *dstFrame;
    QCheckBox *dstCheckBox;
    QWidget *dstContainer;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dstLabel;
    QComboBox *dstOpComboBox;
    QLineEdit *dstLineEdit;
    QFrame *srcFrame;
    QWidget *srcContainer;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *srcLabel;
    QComboBox *srcOpComboBox;
    QLineEdit *srcLineEdit;
    QCheckBox *srcCheckBox;
    QHBoxLayout *searchClearHorizontalLayout;
    QPushButton *searchPushButton;
    QPushButton *clearPushButton;
    QGroupBox *displayOptionsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *displayFileNameCheckBox;
    QCheckBox *displaySrcCheckBox;
    QCheckBox *displayDstCheckBox;
    QCheckBox *displayFlagsCheckBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *allPropertiesRadioButton;
    QRadioButton *selectedPropertyRadioButton;
    QRadioButton *noPropertyRadioButton;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuMaterial_XML;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(997, 942);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        settingsHorizontalLayout = new QHBoxLayout();
        settingsHorizontalLayout->setSpacing(6);
        settingsHorizontalLayout->setObjectName(QStringLiteral("settingsHorizontalLayout"));
        searchPropertiesGroupBox = new QGroupBox(centralWidget);
        searchPropertiesGroupBox->setObjectName(QStringLiteral("searchPropertiesGroupBox"));
        searchPropertiesGroupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(searchPropertiesGroupBox->sizePolicy().hasHeightForWidth());
        searchPropertiesGroupBox->setSizePolicy(sizePolicy);
        searchPropertiesGroupBox->setMinimumSize(QSize(840, 230));
        verticalLayout = new QVBoxLayout(searchPropertiesGroupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        flagsMatPropHorizontalLayout = new QHBoxLayout();
        flagsMatPropHorizontalLayout->setSpacing(6);
        flagsMatPropHorizontalLayout->setObjectName(QStringLiteral("flagsMatPropHorizontalLayout"));
        flagsFrame = new QFrame(searchPropertiesGroupBox);
        flagsFrame->setObjectName(QStringLiteral("flagsFrame"));
        flagsFrame->setFrameShape(QFrame::StyledPanel);
        flagsFrame->setFrameShadow(QFrame::Raised);
        flagsContainer = new QWidget(flagsFrame);
        flagsContainer->setObjectName(QStringLiteral("flagsContainer"));
        flagsContainer->setGeometry(QRect(30, 30, 371, 31));
        layoutWidget = new QWidget(flagsContainer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 371, 33));
        flagsHorizontalLayout = new QHBoxLayout(layoutWidget);
        flagsHorizontalLayout->setSpacing(6);
        flagsHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        flagsHorizontalLayout->setObjectName(QStringLiteral("flagsHorizontalLayout"));
        flagsHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        flagsLabel = new QLabel(layoutWidget);
        flagsLabel->setObjectName(QStringLiteral("flagsLabel"));

        flagsHorizontalLayout->addWidget(flagsLabel);

        flags1LineEdit = new QLineEdit(layoutWidget);
        flags1LineEdit->setObjectName(QStringLiteral("flags1LineEdit"));

        flagsHorizontalLayout->addWidget(flags1LineEdit);

        flagsOpComboBox = new QComboBox(layoutWidget);
        flagsOpComboBox->setObjectName(QStringLiteral("flagsOpComboBox"));

        flagsHorizontalLayout->addWidget(flagsOpComboBox);

        flags2LineEdit = new QLineEdit(layoutWidget);
        flags2LineEdit->setObjectName(QStringLiteral("flags2LineEdit"));

        flagsHorizontalLayout->addWidget(flags2LineEdit);

        flagsCheckBox = new QCheckBox(flagsFrame);
        flagsCheckBox->setObjectName(QStringLiteral("flagsCheckBox"));
        flagsCheckBox->setGeometry(QRect(10, 10, 70, 17));

        flagsMatPropHorizontalLayout->addWidget(flagsFrame);

        matPropertyFrame = new QFrame(searchPropertiesGroupBox);
        matPropertyFrame->setObjectName(QStringLiteral("matPropertyFrame"));
        matPropertyFrame->setFrameShape(QFrame::StyledPanel);
        matPropertyFrame->setFrameShadow(QFrame::Raised);
        matPropCheckBox = new QCheckBox(matPropertyFrame);
        matPropCheckBox->setObjectName(QStringLiteral("matPropCheckBox"));
        matPropCheckBox->setGeometry(QRect(10, 0, 111, 17));
        matPropContainer = new QWidget(matPropertyFrame);
        matPropContainer->setObjectName(QStringLiteral("matPropContainer"));
        matPropContainer->setGeometry(QRect(20, 20, 251, 31));
        layoutWidget1 = new QWidget(matPropContainer);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 231, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        nuLabel = new QLabel(layoutWidget1);
        nuLabel->setObjectName(QStringLiteral("nuLabel"));

        horizontalLayout->addWidget(nuLabel);

        matPropLineEdit = new QLineEdit(layoutWidget1);
        matPropLineEdit->setObjectName(QStringLiteral("matPropLineEdit"));

        horizontalLayout->addWidget(matPropLineEdit);


        flagsMatPropHorizontalLayout->addWidget(matPropertyFrame);


        verticalLayout->addLayout(flagsMatPropHorizontalLayout);

        dstSrcHorizontalLayout = new QHBoxLayout();
        dstSrcHorizontalLayout->setSpacing(6);
        dstSrcHorizontalLayout->setObjectName(QStringLiteral("dstSrcHorizontalLayout"));
        dstFrame = new QFrame(searchPropertiesGroupBox);
        dstFrame->setObjectName(QStringLiteral("dstFrame"));
        dstFrame->setFrameShape(QFrame::StyledPanel);
        dstFrame->setFrameShadow(QFrame::Raised);
        dstCheckBox = new QCheckBox(dstFrame);
        dstCheckBox->setObjectName(QStringLiteral("dstCheckBox"));
        dstCheckBox->setGeometry(QRect(0, 0, 70, 17));
        dstContainer = new QWidget(dstFrame);
        dstContainer->setObjectName(QStringLiteral("dstContainer"));
        dstContainer->setGeometry(QRect(20, 20, 241, 31));
        layoutWidget2 = new QWidget(dstContainer);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dstLabel = new QLabel(layoutWidget2);
        dstLabel->setObjectName(QStringLiteral("dstLabel"));

        horizontalLayout_3->addWidget(dstLabel);

        dstOpComboBox = new QComboBox(layoutWidget2);
        dstOpComboBox->setObjectName(QStringLiteral("dstOpComboBox"));

        horizontalLayout_3->addWidget(dstOpComboBox);

        dstLineEdit = new QLineEdit(layoutWidget2);
        dstLineEdit->setObjectName(QStringLiteral("dstLineEdit"));

        horizontalLayout_3->addWidget(dstLineEdit);


        dstSrcHorizontalLayout->addWidget(dstFrame);

        srcFrame = new QFrame(searchPropertiesGroupBox);
        srcFrame->setObjectName(QStringLiteral("srcFrame"));
        srcFrame->setFrameShape(QFrame::StyledPanel);
        srcFrame->setFrameShadow(QFrame::Raised);
        srcContainer = new QWidget(srcFrame);
        srcContainer->setObjectName(QStringLiteral("srcContainer"));
        srcContainer->setGeometry(QRect(30, 20, 241, 31));
        layoutWidget3 = new QWidget(srcContainer);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 241, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        srcLabel = new QLabel(layoutWidget3);
        srcLabel->setObjectName(QStringLiteral("srcLabel"));

        horizontalLayout_2->addWidget(srcLabel);

        srcOpComboBox = new QComboBox(layoutWidget3);
        srcOpComboBox->setObjectName(QStringLiteral("srcOpComboBox"));

        horizontalLayout_2->addWidget(srcOpComboBox);

        srcLineEdit = new QLineEdit(layoutWidget3);
        srcLineEdit->setObjectName(QStringLiteral("srcLineEdit"));

        horizontalLayout_2->addWidget(srcLineEdit);

        srcCheckBox = new QCheckBox(srcFrame);
        srcCheckBox->setObjectName(QStringLiteral("srcCheckBox"));
        srcCheckBox->setGeometry(QRect(10, 0, 70, 17));

        dstSrcHorizontalLayout->addWidget(srcFrame);


        verticalLayout->addLayout(dstSrcHorizontalLayout);

        searchClearHorizontalLayout = new QHBoxLayout();
        searchClearHorizontalLayout->setSpacing(6);
        searchClearHorizontalLayout->setObjectName(QStringLiteral("searchClearHorizontalLayout"));
        searchPushButton = new QPushButton(searchPropertiesGroupBox);
        searchPushButton->setObjectName(QStringLiteral("searchPushButton"));

        searchClearHorizontalLayout->addWidget(searchPushButton);

        clearPushButton = new QPushButton(searchPropertiesGroupBox);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));

        searchClearHorizontalLayout->addWidget(clearPushButton);


        verticalLayout->addLayout(searchClearHorizontalLayout);


        settingsHorizontalLayout->addWidget(searchPropertiesGroupBox);

        displayOptionsGroupBox = new QGroupBox(centralWidget);
        displayOptionsGroupBox->setObjectName(QStringLiteral("displayOptionsGroupBox"));
        verticalLayout_2 = new QVBoxLayout(displayOptionsGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        displayFileNameCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayFileNameCheckBox->setObjectName(QStringLiteral("displayFileNameCheckBox"));

        verticalLayout_2->addWidget(displayFileNameCheckBox);

        displaySrcCheckBox = new QCheckBox(displayOptionsGroupBox);
        displaySrcCheckBox->setObjectName(QStringLiteral("displaySrcCheckBox"));

        verticalLayout_2->addWidget(displaySrcCheckBox);

        displayDstCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayDstCheckBox->setObjectName(QStringLiteral("displayDstCheckBox"));

        verticalLayout_2->addWidget(displayDstCheckBox);

        displayFlagsCheckBox = new QCheckBox(displayOptionsGroupBox);
        displayFlagsCheckBox->setObjectName(QStringLiteral("displayFlagsCheckBox"));

        verticalLayout_2->addWidget(displayFlagsCheckBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        allPropertiesRadioButton = new QRadioButton(displayOptionsGroupBox);
        allPropertiesRadioButton->setObjectName(QStringLiteral("allPropertiesRadioButton"));

        verticalLayout_3->addWidget(allPropertiesRadioButton);

        selectedPropertyRadioButton = new QRadioButton(displayOptionsGroupBox);
        selectedPropertyRadioButton->setObjectName(QStringLiteral("selectedPropertyRadioButton"));

        verticalLayout_3->addWidget(selectedPropertyRadioButton);

        noPropertyRadioButton = new QRadioButton(displayOptionsGroupBox);
        noPropertyRadioButton->setObjectName(QStringLiteral("noPropertyRadioButton"));

        verticalLayout_3->addWidget(noPropertyRadioButton);


        verticalLayout_2->addLayout(verticalLayout_3);


        settingsHorizontalLayout->addWidget(displayOptionsGroupBox);


        verticalLayout_4->addLayout(settingsHorizontalLayout);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(6);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 21));
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
        searchPropertiesGroupBox->setTitle(QApplication::translate("MainWindow", "Search Properties", Q_NULLPTR));
        flagsLabel->setText(QApplication::translate("MainWindow", "Flags & ", Q_NULLPTR));
        flagsOpComboBox->clear();
        flagsOpComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "==", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">", Q_NULLPTR)
         << QApplication::translate("MainWindow", ">=", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<", Q_NULLPTR)
         << QApplication::translate("MainWindow", "<=", Q_NULLPTR)
        );
        flagsCheckBox->setText(QApplication::translate("MainWindow", "Flags", Q_NULLPTR));
        matPropCheckBox->setText(QApplication::translate("MainWindow", "Material Property", Q_NULLPTR));
        nuLabel->setText(QApplication::translate("MainWindow", "NU_", Q_NULLPTR));
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
        srcCheckBox->setText(QApplication::translate("MainWindow", "src Factor", Q_NULLPTR));
        searchPushButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        clearPushButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        displayOptionsGroupBox->setTitle(QApplication::translate("MainWindow", "Display Settings", Q_NULLPTR));
        displayFileNameCheckBox->setText(QApplication::translate("MainWindow", "File Name", Q_NULLPTR));
        displaySrcCheckBox->setText(QApplication::translate("MainWindow", "Src Factor", Q_NULLPTR));
        displayDstCheckBox->setText(QApplication::translate("MainWindow", "Dst Factor", Q_NULLPTR));
        displayFlagsCheckBox->setText(QApplication::translate("MainWindow", "Flags", Q_NULLPTR));
        allPropertiesRadioButton->setText(QApplication::translate("MainWindow", "All Properties", Q_NULLPTR));
        selectedPropertyRadioButton->setText(QApplication::translate("MainWindow", "Selected Property", Q_NULLPTR));
        noPropertyRadioButton->setText(QApplication::translate("MainWindow", "No Properties", Q_NULLPTR));
        menuMaterial_XML->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
