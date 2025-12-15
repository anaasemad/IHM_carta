/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *ini_sesion;
    QVBoxLayout *verticalLayout_4;
    QWidget *historial;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableViewHistorial;
    QLabel *label_filtro;
    QDateEdit *dateEditFiltro;
    QPushButton *Boton_volver;
    QWidget *mapa;
    QVBoxLayout *verticalLayout;
    QLabel *barra_arriba;
    QPushButton *Modificar_perfil;
    QPushButton *boton_historial;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget_2;
    QWidget *menu_principal;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *boton_alet;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *boton_lista;
    QSpacerItem *verticalSpacer_3;
    QWidget *problema;
    QWidget *lista_problemas;
    QListWidget *listWidget;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QLabel *barra_herramientas;
    QPushButton *linea;
    QPushButton *punto;
    QPushButton *goma;
    QPushButton *color;
    QPushButton *Bcompas;
    QPushButton *limpiar;
    QPushButton *Bregla;
    QPushButton *Btransportador;
    QSlider *horizontalSlider;
    QSpinBox *grosor;
    QPushButton *texto;
    QGraphicsView *graphicsView;
    QLabel *labelStatus;
    QWidget *editar_perfil;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QDateEdit *dateEdit;
    QPushButton *Boton_guardar;
    QPushButton *Boton_volver_2;
    QWidget *registro;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(855, 689);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(78241, 16777215));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        ini_sesion = new QWidget();
        ini_sesion->setObjectName("ini_sesion");
        sizePolicy.setHeightForWidth(ini_sesion->sizePolicy().hasHeightForWidth());
        ini_sesion->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(ini_sesion);
        verticalLayout_4->setObjectName("verticalLayout_4");
        stackedWidget->addWidget(ini_sesion);
        historial = new QWidget();
        historial->setObjectName("historial");
        verticalLayoutWidget = new QWidget(historial);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 130, 781, 461));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tableViewHistorial = new QTableView(verticalLayoutWidget);
        tableViewHistorial->setObjectName("tableViewHistorial");

        verticalLayout_5->addWidget(tableViewHistorial);

        label_filtro = new QLabel(historial);
        label_filtro->setObjectName("label_filtro");
        label_filtro->setGeometry(QRect(480, 100, 121, 20));
        dateEditFiltro = new QDateEdit(historial);
        dateEditFiltro->setObjectName("dateEditFiltro");
        dateEditFiltro->setGeometry(QRect(620, 100, 110, 26));
        Boton_volver = new QPushButton(historial);
        Boton_volver->setObjectName("Boton_volver");
        Boton_volver->setGeometry(QRect(40, 20, 93, 29));
        stackedWidget->addWidget(historial);
        mapa = new QWidget();
        mapa->setObjectName("mapa");
        sizePolicy.setHeightForWidth(mapa->sizePolicy().hasHeightForWidth());
        mapa->setSizePolicy(sizePolicy);
        mapa->setMaximumSize(QSize(811, 628));
        verticalLayout = new QVBoxLayout(mapa);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        barra_arriba = new QLabel(mapa);
        barra_arriba->setObjectName("barra_arriba");
        sizePolicy.setHeightForWidth(barra_arriba->sizePolicy().hasHeightForWidth());
        barra_arriba->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(176, 210, 240, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(215, 232, 247, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(88, 105, 120, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(117, 140, 160, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush8(QColor(88, 105, 120, 127));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
        QBrush brush9(QColor(244, 250, 255, 255));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush9);
#endif
        barra_arriba->setPalette(palette);
        barra_arriba->setAutoFillBackground(true);
        barra_arriba->setFrameShape(QFrame::Shape::NoFrame);
        barra_arriba->setFrameShadow(QFrame::Shadow::Plain);

        verticalLayout->addWidget(barra_arriba);

        Modificar_perfil = new QPushButton(mapa);
        Modificar_perfil->setObjectName("Modificar_perfil");

        verticalLayout->addWidget(Modificar_perfil);

        boton_historial = new QPushButton(mapa);
        boton_historial->setObjectName("boton_historial");

        verticalLayout->addWidget(boton_historial);

        horizontalWidget = new QWidget(mapa);
        horizontalWidget->setObjectName("horizontalWidget");
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(1, -1, -1, -1);
        stackedWidget_2 = new QStackedWidget(horizontalWidget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        menu_principal = new QWidget();
        menu_principal->setObjectName("menu_principal");
        sizePolicy.setHeightForWidth(menu_principal->sizePolicy().hasHeightForWidth());
        menu_principal->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(menu_principal);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        boton_alet = new QPushButton(menu_principal);
        boton_alet->setObjectName("boton_alet");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(boton_alet->sizePolicy().hasHeightForWidth());
        boton_alet->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(boton_alet, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        boton_lista = new QPushButton(menu_principal);
        boton_lista->setObjectName("boton_lista");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(boton_lista->sizePolicy().hasHeightForWidth());
        boton_lista->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(boton_lista, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        gridLayout->setRowStretch(0, 2);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 2);
        gridLayout->setRowStretch(4, 2);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        stackedWidget_2->addWidget(menu_principal);
        problema = new QWidget();
        problema->setObjectName("problema");
        stackedWidget_2->addWidget(problema);
        lista_problemas = new QWidget();
        lista_problemas->setObjectName("lista_problemas");
        listWidget = new QListWidget(lista_problemas);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 30, 331, 371));
        stackedWidget_2->addWidget(lista_problemas);

        horizontalLayout_2->addWidget(stackedWidget_2);

        verticalWidget = new QWidget(horizontalWidget);
        verticalWidget->setObjectName("verticalWidget");
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(verticalWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(verticalWidget);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        barra_herramientas = new QLabel(widget_2);
        barra_herramientas->setObjectName("barra_herramientas");
        barra_herramientas->setGeometry(QRect(0, 0, 401, 29));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(barra_herramientas->sizePolicy().hasHeightForWidth());
        barra_herramientas->setSizePolicy(sizePolicy3);
        barra_herramientas->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush10(QColor(181, 181, 181, 255));
        brush10.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush10);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush11(QColor(218, 218, 218, 255));
        brush11.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush11);
        QBrush brush12(QColor(90, 90, 90, 255));
        brush12.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush12);
        QBrush brush13(QColor(121, 121, 121, 255));
        brush13.setStyle(Qt::BrushStyle::SolidPattern);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush13);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush2);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush2);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush10);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush11);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush6);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush2);
#endif
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush10);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush11);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush12);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush13);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush10);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush11);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush6);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush7);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush2);
#endif
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush12);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush10);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush11);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush12);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush13);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush12);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush2);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush12);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush10);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush10);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush10);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush6);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush14(QColor(90, 90, 90, 127));
        brush14.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush14);
#endif
        QBrush brush15(QColor(235, 235, 235, 255));
        brush15.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush15);
#endif
        barra_herramientas->setPalette(palette1);
        barra_herramientas->setAutoFillBackground(true);
        barra_herramientas->setFrameShape(QFrame::Shape::NoFrame);
        barra_herramientas->setFrameShadow(QFrame::Shadow::Plain);
        linea = new QPushButton(widget_2);
        linea->setObjectName("linea");
        linea->setGeometry(QRect(150, 0, 40, 24));
        sizePolicy2.setHeightForWidth(linea->sizePolicy().hasHeightForWidth());
        linea->setSizePolicy(sizePolicy2);
        linea->setMaximumSize(QSize(167, 167));
        linea->setCheckable(true);
        punto = new QPushButton(widget_2);
        punto->setObjectName("punto");
        punto->setGeometry(QRect(0, 0, 31, 24));
        sizePolicy2.setHeightForWidth(punto->sizePolicy().hasHeightForWidth());
        punto->setSizePolicy(sizePolicy2);
        punto->setMinimumSize(QSize(0, 0));
        punto->setMaximumSize(QSize(167, 167));
        punto->setIconSize(QSize(10, 16));
        punto->setCheckable(true);
        goma = new QPushButton(widget_2);
        goma->setObjectName("goma");
        goma->setGeometry(QRect(290, 0, 31, 24));
        sizePolicy2.setHeightForWidth(goma->sizePolicy().hasHeightForWidth());
        goma->setSizePolicy(sizePolicy2);
        goma->setMaximumSize(QSize(167, 167));
        color = new QPushButton(widget_2);
        color->setObjectName("color");
        color->setGeometry(QRect(269, 0, 21, 24));
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(color->sizePolicy().hasHeightForWidth());
        color->setSizePolicy(sizePolicy4);
        color->setMaximumSize(QSize(167, 167));
        color->setIconSize(QSize(9, 9));
        color->setAutoDefault(false);
        color->setFlat(false);
        Bcompas = new QPushButton(widget_2);
        Bcompas->setObjectName("Bcompas");
        Bcompas->setEnabled(true);
        Bcompas->setGeometry(QRect(30, 0, 31, 24));
        sizePolicy2.setHeightForWidth(Bcompas->sizePolicy().hasHeightForWidth());
        Bcompas->setSizePolicy(sizePolicy2);
        Bcompas->setMaximumSize(QSize(167, 167));
        Bcompas->setIconSize(QSize(10, 16));
        Bcompas->setCheckable(true);
        limpiar = new QPushButton(widget_2);
        limpiar->setObjectName("limpiar");
        limpiar->setGeometry(QRect(320, 0, 31, 24));
        sizePolicy2.setHeightForWidth(limpiar->sizePolicy().hasHeightForWidth());
        limpiar->setSizePolicy(sizePolicy2);
        limpiar->setMaximumSize(QSize(167, 167));
        Bregla = new QPushButton(widget_2);
        Bregla->setObjectName("Bregla");
        Bregla->setGeometry(QRect(60, 0, 31, 24));
        sizePolicy2.setHeightForWidth(Bregla->sizePolicy().hasHeightForWidth());
        Bregla->setSizePolicy(sizePolicy2);
        Bregla->setMaximumSize(QSize(167, 167));
        Bregla->setCheckable(true);
        Btransportador = new QPushButton(widget_2);
        Btransportador->setObjectName("Btransportador");
        Btransportador->setGeometry(QRect(90, 0, 31, 24));
        sizePolicy2.setHeightForWidth(Btransportador->sizePolicy().hasHeightForWidth());
        Btransportador->setSizePolicy(sizePolicy2);
        Btransportador->setMaximumSize(QSize(167, 167));
        QFont font;
        font.setKerning(true);
        Btransportador->setFont(font);
        Btransportador->setIconSize(QSize(8, 16));
        Btransportador->setCheckable(true);
        horizontalSlider = new QSlider(widget_2);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(350, 10, 51, 20));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        grosor = new QSpinBox(widget_2);
        grosor->setObjectName("grosor");
        grosor->setGeometry(QRect(190, 0, 51, 25));
        grosor->setMinimum(1);
        grosor->setMaximum(20);
        grosor->setValue(6);
        texto = new QPushButton(widget_2);
        texto->setObjectName("texto");
        texto->setGeometry(QRect(120, 0, 31, 24));
        barra_herramientas->raise();
        linea->raise();
        punto->raise();
        goma->raise();
        color->raise();
        Bcompas->raise();
        Bregla->raise();
        Btransportador->raise();
        horizontalSlider->raise();
        limpiar->raise();
        grosor->raise();
        texto->raise();

        verticalLayout_3->addWidget(widget_2);

        graphicsView = new QGraphicsView(verticalWidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_3->addWidget(graphicsView);

        labelStatus = new QLabel(verticalWidget);
        labelStatus->setObjectName("labelStatus");

        verticalLayout_3->addWidget(labelStatus);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 18);

        horizontalLayout_2->addWidget(verticalWidget);


        verticalLayout->addWidget(horizontalWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(3, 15);
        stackedWidget->addWidget(mapa);
        editar_perfil = new QWidget();
        editar_perfil->setObjectName("editar_perfil");
        label = new QLabel(editar_perfil);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 60, 63, 20));
        label_2 = new QLabel(editar_perfil);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 140, 63, 20));
        label_3 = new QLabel(editar_perfil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 220, 63, 20));
        label_4 = new QLabel(editar_perfil);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 300, 63, 20));
        label_5 = new QLabel(editar_perfil);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 390, 63, 20));
        textEdit = new QTextEdit(editar_perfil);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(100, 170, 171, 31));
        textEdit_2 = new QTextEdit(editar_perfil);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(100, 250, 211, 31));
        textEdit_3 = new QTextEdit(editar_perfil);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(100, 340, 151, 31));
        dateEdit = new QDateEdit(editar_perfil);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(100, 420, 110, 26));
        Boton_guardar = new QPushButton(editar_perfil);
        Boton_guardar->setObjectName("Boton_guardar");
        Boton_guardar->setGeometry(QRect(340, 470, 111, 71));
        Boton_volver_2 = new QPushButton(editar_perfil);
        Boton_volver_2->setObjectName("Boton_volver_2");
        Boton_volver_2->setGeometry(QRect(20, 10, 93, 29));
        stackedWidget->addWidget(editar_perfil);
        registro = new QWidget();
        registro->setObjectName("registro");
        stackedWidget->addWidget(registro);

        verticalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 855, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(1);
        color->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_filtro->setText(QCoreApplication::translate("MainWindow", "Filtar por fecha", nullptr));
        Boton_volver->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        barra_arriba->setText(QString());
        Modificar_perfil->setText(QCoreApplication::translate("MainWindow", "Modificar perfil", nullptr));
        boton_historial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
        boton_alet->setText(QCoreApplication::translate("MainWindow", "Problema aleatorio", nullptr));
        boton_lista->setText(QCoreApplication::translate("MainWindow", "Lista problemas", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Problema 1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Problema 2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Problema 3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Problema 4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Problema 5", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        barra_herramientas->setText(QString());
        linea->setText(QCoreApplication::translate("MainWindow", "linea", nullptr));
        punto->setText(QCoreApplication::translate("MainWindow", "punt", nullptr));
        goma->setText(QCoreApplication::translate("MainWindow", "goma", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        Bcompas->setText(QCoreApplication::translate("MainWindow", "compas", nullptr));
        limpiar->setText(QCoreApplication::translate("MainWindow", "limpiar", nullptr));
        Bregla->setText(QCoreApplication::translate("MainWindow", "regla", nullptr));
        Btransportador->setText(QCoreApplication::translate("MainWindow", "transportador", nullptr));
        texto->setText(QCoreApplication::translate("MainWindow", "texto", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "labelStatus", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Boton_guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        Boton_volver_2->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
