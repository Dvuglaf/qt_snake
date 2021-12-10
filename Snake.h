#pragma once
#include <QWidget>
#include <QTimer>
#include "Fruit.h"
#include <QSize>
#include <QVector>
#include <QKeyEvent>
#include "Settings.h"
#include <random>
#include <QPainter>

/**
 * ������ � ����� ������.
 */
class Snake : public QWidget {
	Q_OBJECT

public:
	static const qint64 _DOT_SIZE = 24; /**< ������ ������ ������� � ������� � ��������. */
private:
	const QSize _size; /**< ������ ����. */
	std::mt19937 _random; /**< ����. */
	enum class Directions {UP, LEFT, RIGHT, DOWN}; /**< ����������� �������� ������. */
	bool _game = false; /**< ������� ��������� ����. */
	bool _left = false; /**< ������ �� ������� �����. */
	bool _right = false; /**< ������ �� ������� ������. */
	bool _up = false; /**< ������ �� ������� �����. */
	bool _down = false; /**< ������ �� ������� ����. */
	bool  _randomFruit = true; /**< ������������ �� ����������� ������. */
	QImage _dot; /**< ����������� ����� ���� */
	Settings& _settings; /**< ���������. */
	QTimer* _timer; /**< ������. */
	Fruit _fruit; /**< �����. */
	Directions _direction ; /**< ������� ����������� ������. */
	qint32 _score = 0; /**< ���������� ��������� �������. */
	QVector<QPoint> _body; /**< ������� ���� ���������� ������. */

	/**
	 * ����������� ������� ������� ����.
	 *
	 * @params painter �����������.
	 */
	void pressStart(QPainter& painter);

	/**
	 * �������� ������������ � �������.
	 */
	void eatFruit();

	/**
	 * �������� ������������ � ����������� ������.
	 */
	void checkCollision();

	/**
	 * ������� �������� ������.
	 */
	void move();


	/**
	 * �������� ���� � ���������� ��� ���������.
	 */
	void showResult();

	/**
	 * ��������.
	 */
	void gameOver();

	/**
	 * �������, ���������� �� ��������� �����.
	 *
	 *@ params event �������.
	 */
	void paintEvent(QPaintEvent* event);

	/**
	 * �������, ����������� �� ������� ������ ����������.
	 *
	 *@ params key �������.
	 */
	void keyPressEvent(QKeyEvent* key);

	/**
	 * ��������� ���� ����������� ������ �� �������.
	 *
	 *@param index ������, ����������� ����������� ������.
	 *@return ���� � �����.
	 */
	char* getPath(qint32 index);

private slots:
	/**
	 * ����������, ���������� �� ���������� �����.
	 */
	void updateScene();

	/**
	 * ����������, ���������� �� ����� ����.
	 */
	void start();

	/**
	 * ����������, ������������ ������ � ������������� ��������� ����.
	 */
	void scoreMustIncreament();

public slots:
	/**
	 * ����������, ���������� �� ����� ���������.
	 *
	 *@param value �������� ���������.
	 */
	void changeDifficulty(qint32 value);

	/**
	* ����������, ���������� �� ����� ����������� ������.
	*
	* @param index ������, ���������� �� ����������� ������.
	* @param random ����, ���������� �� ��, �������� �� ����� �������� ����������� ���������.
	*/
	void changeFruitIcon(qint32 index , bool random);

signals:
	/**
	 * ������ � ������������� �������� ��������� ������ ����.
	 */
	void statusBarMustUpdate();

public:
	/**
	 * �������� ������� ����.
	 *
	 *@return ������� �������� �����.
	 */
	int getScore();
public:
	/**
	 * ����������� �� ���������, �������� ������ ������� 576�576.
	 *
	 *@paran parent ������.
	 */
	Snake(Settings& settings, QWidget* parent = 0);

	/**
	 * ����������� ����������� �����������.
	 */
	Snake(const Snake&) = delete;

	/**
	 * ����������� �������� ������������ ������������.
	 */
	Snake& operator=(const Snake&) = delete;
};
