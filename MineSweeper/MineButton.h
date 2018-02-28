#pragma once

#include <QPushButton>

class MineButton : public QPushButton
{
	Q_OBJECT

public:
	MineButton(QWidget *parent);
	~MineButton();

	inline void setNumber(int val) { number = val; }
private:
	bool opened;
	bool marked;
	int number;
signals:
	void boom();
	void zeroClick();
protected:
	virtual void contextMenuEvent(QContextMenuEvent *event) override;
};
