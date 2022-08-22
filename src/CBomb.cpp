//
// Created by marek on 6/12/2021.
//

#include "CBomb.h"

CBomb::CBomb() : CItem('B', 1) {}

CBomb::CBomb(size_t bombs) : CItem('B', bombs) {}

void CBomb::UseItem(CGame &game) {
    CCoords coord = {game.GetPlayer().Coord().m_X - 2, game.GetPlayer().Coord().m_Y - 2};
    //check all coords which are close to player
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            if (game.GetMap().isInside({coord.m_X + i, coord.m_Y + j})) {
                game.KillZombie({coord.m_X + i, coord.m_Y + j});
            }
        }
    }
    m_Amount--;
    //If ran out of bombs, remove them from inventory.
    if (m_Amount == 0) {
        game.GetPlayer().Inventory()->DropItem(GetName());
    }
}
