#ifndef GAME_H
#define GAME_H
#include "hero.h"
#include <QWidget>
#include "creature.h"
#include "object.h"
#include "core.h"
namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    Hero hero;
    Creature mon1,mon2,mon3,mon4,boss;
    Object sword,shield,water;
    explicit Game(QWidget *parent = nullptr);
    ~Game();



protected:
    void keyPressEvent(QKeyEvent* e);

private:
    Ui::Game *ui;
};

#endif // GAME_H
