//
// Created by marek on 5/31/2021.
//
#include "SActions.h"

using namespace std;


CAction SActions::MovePlayer(EDirection dir) {
    return CAction([dir](CGame &game) {
        //player can move to any field which is empty (is not a wall or zombie spawn)
        if (game.GetMap().isInside(game.GetPlayer().Coord() + dir)
            && game.GetMap().isEmpty(game.GetPlayer().Coord() + dir)) {
            game.GetPlayer().Coord(game.GetPlayer().Coord() + dir);
        }
    });
}

CAction SActions::MoveZombie(size_t zombieId, CCoords newPosition) {
    return CAction([zombieId, newPosition](CGame &game) {
        //Check if zombie was not killed in a meantime, if so, dont generate moveAction
        //Check if some other zombie didnt already move to newPosition
        std::shared_ptr<CZombie> tmp = nullptr;

        for (const auto &zombie : game.GetZombies()) {
            if (zombie->Coord() == newPosition) {
                return;
            }
            if (zombie->GetId() == zombieId) {
                tmp = zombie;
            }
        }
        if (tmp != nullptr) {
            tmp->Coord(newPosition);
        }
    });
}

CAction SActions::ZombieSpawn(const shared_ptr<CZombie> &zombie) {
    return CAction([zombie](CGame &game) {
        game.AddZombie(zombie);
    });
}

CAction SActions::SpawnItem(const shared_ptr<CItem> &item, CCoords position) {
    return CAction([item, position](CGame &game) {
        if (game.isEmpty(position)) {
            game.AddItem(position, item);
        }
    });
}

CAction SActions::PickUp() {
    return CAction([](CGame &game) {
        for (auto &item : game.GetItems()) {
            if (game.GetPlayer().Coord() == item.first) {
                game.GetPlayer().Inventory()->AddItem(item.second);
                game.RemoveItem(item.first);
            }
        }
    });

}

CAction SActions::Teleport(CPlayer &player) {
    return CAction([&player](CGame &game) {
        if (player.GetProperties().m_Ports > 0) {
            CCoords newPosition = player.Coord();
            while (game.GetMap().isEmpty(newPosition + player.Direction())) {
                newPosition = newPosition + player.Direction();
            }
            player.Coord(newPosition);
            player.MinusPort();
        }
    });

}

CAction SActions::UseActiveItem(CPlayer &player) {
    return CAction([&player](CGame &game) {
        if (!player.Inventory()->EmptyItems()) {
            player.Inventory()->GetActiveItem()->UseItem(game);
        }
    });
}

CAction SActions::SwitchActiveItem() {
    return CAction([](CGame &game) {
        game.GetPlayer().Inventory()->NextActiveItem();
    });
}
