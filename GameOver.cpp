#include "GameOver.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QAction>
#include <QLabel>
#include <QString>

GameOver::GameOver(qint64 score, QWidget* parent): QWidget(parent){


    setWindowTitle(u8"����");

    const auto text = QString(u8"��� ���������: %1!").arg(score);
    const auto label = new QLabel(text);


    const auto exitButton = new QPushButton(u8"�����");
    connect(exitButton, &QAbstractButton::clicked, this, &QWidget::close);

    const auto rootLayout = new QVBoxLayout;
    rootLayout->addWidget(label);
    rootLayout->addWidget(exitButton);
    rootLayout->setAlignment(exitButton, Qt::AlignRight);
    setStyleSheet("background-color:white;");

    setLayout(rootLayout);
}