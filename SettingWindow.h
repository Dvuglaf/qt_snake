#pragma once

#include <QImage>
#include <QWidget>
#include "Settings.h"

/**
 * ���� ��� ����������� � ���������� ��������� ��������.
 */
class SettingsWindow : public QWidget {

Q_OBJECT

    Settings& _settings; /**< ��������� ���������. */

private:
    /**
    * ������ ������ ����������� �������� ����������� ������.
    *
    * @return ������ � PushButtons, ���������� �� ����������� ������.
    */
    QWidget* createFirstTab();

    /**
    * ������ ������ ����������� �������� ���������.
    *
    * @return ������ � PushButtons, ���������� �� ��������� ����.
    */
    QWidget* createSecondTab();

signals:
    /**
    * ������ ������������, ����� ��������� ���������� ��������.
    *
    * @param index �������� c��������.
    */
    void changeD(qint32 index) ;

signals:
    /**
    * ������ ������������, ����� ��������� ���������� ��������.
    *
    * @param index ������, ���������� �� ����������� ������.
    * @param random ����, ���������� �� ��, �������� �� ����� �������� ����������� ���������.
    */
    void changeF(qint32 index, bool random) ;

private slots:

    /**
    * ���������� ��� ������� ������� ������, ���������� �� ���������.
    *
    * @param index ����� �������� c��������.
    */
    void difficultyChanged(qint32 index) ;

    /**
    * ���������� ��� ������� ������� ������, ���������� �� ����������� ������ .
    *
    * @param index ������, ����������� ����������� ������.
    */
    void fruitChanged(qint32 index) ;

public:

    /**
     * �����������.
     *
     * @param settings ��������� ��� ����������� � ���������� ���������.
     */
    explicit SettingsWindow(Settings& settings);

    /**
     * ����������� ����������� �����������.
     */
    SettingsWindow(const SettingsWindow&) = delete;

    /**
     * ����������� �������� ������������ ������������.
     */
    SettingsWindow& operator=(const SettingsWindow&) = delete;

};