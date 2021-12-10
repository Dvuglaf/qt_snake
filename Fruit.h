#pragma once
#include <QWidget>
#include <random>

/**
 * �������� ������������ �����, ������ - ����������.
 */
class Fruit : public QWidget {

	qint32 _fruitX; /**< ������� ������ �� ��� ��. */
	qint32 _fruitY; /**< ������� ������ �� ��� ��. */
	std::mt19937 _random; /**< ����. */

public:
	/**
	 * ����������� � ����������.
	 *
	 * @param dotSize ���������� ������ � ���� � ��������.
	 */
	Fruit(qint32 dotSize = 24);

	/**
	 * ����������� ����������� �����������.
	 */
	Fruit(const Fruit& ) = delete;

	/**
	 * ����������� �������� ������������ ������������.
	 */
	Fruit &operator= (const Fruit&) = delete;

	/**
	 * ������� ����� �� ��������� ��������.
	 *
	 * @param dotSize ���������� ������ � ���� � ��������
	 */
	void spawnFruit(qint32 dotSize);

	/**
	 * �������� ������� ������ �� ��� ��.
	 *
	 * @return ������� ������ �� ��� ��.
	 */
	qint32 fruitX() const;

	/**
	 * �������� ������� ������ �� ��� ��.
	 *
	 * @return ������� ������ �� ��� ��.
	 */
	qint32 fruitY() const;
};