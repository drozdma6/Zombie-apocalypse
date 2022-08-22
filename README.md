#Zombie Apocalypse
Simple command line game inspired by [Boxhead](https://www.y8.com/games/box_head_2play). Players are gaining scores by killing zombies. The player is losing health if he stands on the same block as some zombie.
## Application commands
- `new`  create a new game with a new character and a map,
- `load` loads previously saved game,
- `quit` exits the game.

## Game commands
- `w s a d` for moving character,
- `e` for switching current weapon,
- `p` for teleport to the nearest wall in front of the character,
- `f` to fire,
- `q` to quit.

## Map
```
+--------- -+
| >      #  |
|B    #     |
|         #+|
|  G     ZZ |
|    #  Z ##|
|    #     +|
+-----------+

> player
Z Zombie
G Gun
B Bomb
| Vertikal wall
- Horizontal wall
# Inside wall
+ Zombie spawn
```