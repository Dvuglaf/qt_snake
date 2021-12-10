#pragma once
#include <QMainWindow>
#include "Snake.h"
#include <QSize>
#include <QLabel>

/**
 * �������� ���� ����.
 */
class MainWindow :public QMainWindow {

	Q_OBJECT
private:

	Snake* _snake; /**< ������. */
	Settings _settings; /**< ���������. */
	QLabel* _statusBar; /**< ������ ���, ������������ ������� ����. */

private slots:
	/**
	 * ����������, ���������� �� ���������� ������ �� ������ ����.
	 */
	void refreshStatusBar();
	
	/**
	 * ����������, ���������� �� ����� ���� ��������.
	 */
	void showSettings();

public:
	/**
	 * ����������� �� ���������, �������� ������ ���� 576x576.
	 */
	MainWindow();

	/**
	 * ����������� ����������� �����������.
	 */
	MainWindow(const MainWindow&) = delete;

	/**
	 * ����������� �������� ������������ ������������.
	 */
	MainWindow& operator= (const MainWindow&) = delete;


};