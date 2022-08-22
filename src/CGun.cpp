//
// Created by marek on 5/31/2021.
//

#include "CGun.h"


CGun::CGun() : CItem('G', 3) {} //each field with G adds 3 ammunition.

CGun::CGun(size_t ammo) : CItem('G', ammo) {}

void CGun::UseItem(CGame &game) {
    //fires only if there is some ammo
    if (m_Amount > 0) {
        //bullet travels in current player's direction
        CCoords bullet = game.GetPlayer().Coord() + game.GetPlayer().Direction();
        //find closest object in players direction(zombie/wall)
        while (game.GetMap().isEmpty(bullet) && !game.KillZombie(bullet)) {
            bullet = bullet + game.GetPlayer().Direction();
        }
        m_Amount--; //reduce ammunition after each shot.
    }
    //If magazine was cleared out, delete gun from inventory.
    if (m_Amount == 0) {
        game.GetPlayer().Inventory()->DropItem(GetName());
    }
}
