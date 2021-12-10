#pragma once
#include <QWidget>

/**
 * ������ � ������������ ����� ��� ���������.
 */
class GameOver :public QWidget {

Q_OBJECT

public:
    /**
     * ����������� � �����������.
     *
     *@param score ����, ��������� �� �����.
     *@param parent ������
     */
	GameOver(qint64 score, QWidget* parent = 0);

    /**
     * ����������� ����������� �����������.
     */
    GameOver(const GameOver&) = delete;

    /**
     * ����������� �������� ������������ ������������.
     */
    GameOver& operator=(const GameOver&) = delete;
};